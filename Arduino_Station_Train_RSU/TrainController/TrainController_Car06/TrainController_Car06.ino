#include <ESP8266WiFi.h>
#include <SocketIoClient.h>
#include <ArduinoJson.h>
#include <Arduino.h>
#include "wifipassword.h"
#define USER_SERIAL Serial

//----------------
// To do
// Setup PIN here
//----------------
const int FwdPin = 0; //Forward Motor Pin
const int BwdPin = 2;  //Backward Motor Pin
long ActTime = 3000; // The time for a particular part of the cycle.
int MinSpd = 300; //Minimum speed (0-1023)
int MaxSpd = 1023; //Top speed (0-1023)
int MoveSpd = 0;  //Move Speed
boolean DirFlag = true; //Flag for direction

// Set your Static IP address
IPAddress local_IP(192, 168, 1, 56);
// Set your Gateway IP address
IPAddress gateway(192, 168, 1, 1);

IPAddress subnet(255, 255, 224, 0);
IPAddress primaryDNS(8, 8, 8, 8);   //optional
IPAddress secondaryDNS(8, 8, 4, 4); //optional

//----------------
// Interface
//----------------
struct CarInterface{
    bool needUpdateData;
    
    bool moveing;
    int moveDirection;
    double moveSpeed;

    bool lastMoveing;
    int lastMoveDirection;
    double lastMoveSpeed;
};
struct CarInterface myCar;


//----------------

SocketIoClient webSocket;

const char* ssid = "RGGROUP";
const char* pass = WIFI_PASSWORD;


//----------------
// Setup Car
const char* charCarName = "Car06";
//----------------
// To do
// Register Car
//----------------
void registerCar(){
  webSocket.emit("registerCar", "{\"name\":\"Car06\"}");
}

//----------------
// To do 
// Car Controll
//----------------
void serverControllMoveCarForwardWith(double moveSpeed){
  //Car move forward
  //MoveSpd = int(double(MaxSpd) * moveSpeed);
  MoveSpd = MaxSpd * moveSpeed;

  USER_SERIAL.println("Move Forward");
  USER_SERIAL.println(MoveSpd);
  analogWrite(FwdPin, MoveSpd);
  analogWrite(BwdPin, 0);
}

void serverControllMoveCarBackwardWith(double moveSpeed){
  //Car move backward
    MoveSpd = MaxSpd * moveSpeed;
  USER_SERIAL.println("Move Backward");
  USER_SERIAL.println(MoveSpd);
  analogWrite(BwdPin, MoveSpd);
  analogWrite(FwdPin, 0);
}

void serverControllStopCar(){
  //Car stop  
    USER_SERIAL.println("Stop");
    digitalWrite(FwdPin, LOW);
    digitalWrite(BwdPin, LOW);
}
//----------------


//----------------
// Setup Junction
//----------------


void setup() {
  
  pinMode(FwdPin, OUTPUT);
  pinMode(BwdPin, OUTPUT);
  digitalWrite(FwdPin, LOW);
  digitalWrite(BwdPin, LOW);

  setupCarData();
  
  USER_SERIAL.begin(115200);

  connetWiFi();

  webSocket.begin("192.168.1.8", 5000);

  webSocket.on("connect", onConnectEvent);
  webSocket.on("cars", controller);
  webSocket.on("checkStatus", onCheckStatusEvent);
  webSocket.on("stopAll", onStopAllEvent);
  
}

//----------------
// Run Time Loop
//----------------
void loop() {
  
  webSocket.loop();

  loopCarControll();
}
//----------------



void connetWiFi(){
   int numberOfNetwork = WiFi.scanNetworks();

  USER_SERIAL.print("test");
  for(int i = 0; i < numberOfNetwork; i++){
    USER_SERIAL.print("Network name: ");
    USER_SERIAL.println(WiFi.SSID(i));
    USER_SERIAL.print("Signal strength: ");
    USER_SERIAL.println(WiFi.RSSI(i));
    USER_SERIAL.println("---------------------");
  }


  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED){
    USER_SERIAL.print(".");
    delay(1000);
  }

  // Configures static IP address
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }

  USER_SERIAL.print("");
  USER_SERIAL.println("Wi-Fi connected");
  USER_SERIAL.print("IP Address : ");
  USER_SERIAL.println(WiFi.localIP());
}
//----------------
// Controll Car (on connect)
//----------------
void onConnectEvent(const char* message, size_t length){

  registerCar();
  setupCarData();
}

void onCheckStatusEvent(const char* message, size_t length){
  registerCar();
}

void onStopAllEvent(const char* message, size_t length){
  myCar.moveing = false;
  myCar.moveSpeed = 0.0;
  serverControllStopCar();
}

//----------------
// Controll Car (on car)
//----------------
void controller(const char* message, size_t length){


  
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, message);
    
  JsonArray objectCars = doc["cars"];
  doc.clear();

  int arraySize =  objectCars.size();

  for(int i = 0; i < arraySize; i++){
    JsonObject thisCar = objectCars[i];

    const char* _name = thisCar["name"];
    const char* _to = thisCar["to"];
    const char* _from = thisCar["from"];
    const int _direction = thisCar["direction"];
    //find Car by Name
    // Using strcmp() for check equal string

    String str1 = String(_name);
    String str2 = String(charCarName);
    
    if (str1 == str2){ 
      readCarDataWith(thisCar);

    }

    
    //------------
  }// end for

 
}// end controlled


//----------------
// controll car 
//----------------
void readCarDataWith(JsonObject car){


    const int _direction = car["direction"];
    const char* _to = car["to"];
    const char* _from = car["from"];
    const char* _name = car["name"];
    const int _position = car["position"];
    const char* _id = car["id"];
    const int _status = car["status"];
    const char* _line = car["line"];
    const double _speed = car["speed"];


    USER_SERIAL.print("Car ID :");
    USER_SERIAL.print(_id);
    USER_SERIAL.print("  Car Name :");
    USER_SERIAL.println(_name);   
    USER_SERIAL.print("Status :");
    USER_SERIAL.println(_status);  

    if(_status == 3){
      myCar.moveing = true;
      myCar.moveSpeed = _speed;
    }else{
      myCar.moveing = false;
      myCar.moveSpeed = 0.0;
    }
    myCar.moveDirection = _direction; //0 = ขาไป, 1 = ขากลับ
   
    
}

//----------------
void setupCarData(){
  myCar.needUpdateData = true;
  
  myCar.moveing = false;
  myCar.moveDirection = 0;
  myCar.moveSpeed = 1.0;

  myCar.lastMoveing = false;
  myCar.lastMoveDirection = 0;
  myCar.lastMoveSpeed = 1.0;
}

//----------------
void loopCarControll(){

  if(myCar.moveing != myCar.lastMoveing){
    myCar.needUpdateData = true;
  }
  if(myCar.moveDirection != myCar.lastMoveDirection){
    myCar.needUpdateData = true;
  }
  if(myCar.moveSpeed != myCar.lastMoveSpeed){
    myCar.needUpdateData = true;
  }

  
  if(myCar.needUpdateData == true){
    //---
    if(myCar.moveing == true){
      if(myCar.moveDirection == 0){
        serverControllMoveCarForwardWith(myCar.moveSpeed);
      }else if(myCar.moveDirection == 1){
        serverControllMoveCarBackwardWith(myCar.moveSpeed);
      }else{
        serverControllStopCar();
      }
    }else{
      serverControllStopCar();
    }
    myCar.lastMoveing = myCar.moveing;
    myCar.lastMoveDirection = myCar.moveDirection;
    myCar.lastMoveSpeed = myCar.moveSpeed;
    myCar.needUpdateData = false;
  }
  
  
}




//----------------
// Helper
//----------------
