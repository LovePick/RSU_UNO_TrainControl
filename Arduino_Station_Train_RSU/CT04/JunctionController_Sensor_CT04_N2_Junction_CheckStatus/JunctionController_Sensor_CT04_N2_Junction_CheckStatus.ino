#include <ESP8266WiFi.h>
#include <SocketIoClient.h>
#include <ArduinoJson.h>
#include <Arduino.h>

#define USER_SERIAL Serial

#include <IOXhop_MCUio.h>

//----------------
// To do
// Setup PIN here
//----------------
//ST04_Junction

IOXhop_MCUio mcu(8, D1, D2);

//P1
int P1N = 2;  int P1R = 3;
//P2
int P2N = 4;  int P2R = 5;
//P3
int P3N = 6;  int P3R = 7;
//P4
int P4N = 8;  int P4R = 9;
//P5
int P5N = 10; int P5R = 11;
//P6
int P6N = 12; int P6R = 13;
//P7
int P7N = mcu.A0; int P7R = mcu.A1;

int ENA = mcu.A2; //mcu.A2 Null
int ENB = mcu.A3; 

int lastJunction = -1;

int led3State = -1;
unsigned long startTime;
unsigned long blinkRate = 500UL;

// Set your Static IP address
IPAddress local_IP(192, 168, 1, 110);
// Set your Gateway IP address
IPAddress gateway(192, 168, 1, 1);

IPAddress subnet(255, 255, 224, 0);
IPAddress primaryDNS(8, 8, 8, 8);   //optional
IPAddress secondaryDNS(8, 8, 4, 4); //optional

//----------------
// Interface
//----------------
struct DirectionInterface{
  char* target1;
  char* target2;
  bool myactive;
};

struct StationAndCarInterface{
  char* stationID;
  char* carID;
  char* lastCarID;
};


struct JunctionInterface{
  bool needUpdateData;

  int junctionDirection;
  int lastDirection;
};

//----------------

SocketIoClient webSocket;


const char* ssid = "RGGROUP";
const char* pass = "RG@GROUP1234";//WIFI_PASSWORD;


//----------------
// Setup Junction
//----------------

struct DirectionInterface directionList[6];

struct StationAndCarInterface stationList[4];


//----------------
// Controll Junction
//----------------
void setupDirectionList(){
  directionList[0].target1 = "B11-A";
  directionList[0].target2 = "B01-A";

  directionList[1].target1 = "B11-B";
  directionList[1].target2 = "B01-B";

  directionList[2].target1 = "B01-A";
  directionList[2].target2 = "TB01";

  directionList[3].target1 = "B01-A";
  directionList[3].target2 = "TB02";

  directionList[4].target1 = "B01-B";
  directionList[4].target2 = "TB01";

  directionList[5].target1 = "B01-B";
  directionList[5].target2 = "TB02";
  
}

//----------------
// Controll Station
//----------------
void setupStationList(){
  stationList[0].stationID = "B01-A";
  stationList[0].carID = "";
  stationList[0].lastCarID = "";

  stationList[1].stationID = "B01-B";
  stationList[1].carID = "";
  stationList[1].lastCarID = "";

  stationList[2].stationID = "TB01";
  stationList[2].carID = "";
  stationList[2].lastCarID = "";

  stationList[3].stationID = "TB02";
  stationList[3].carID = "";
  stationList[3].lastCarID = "";

}




void carArrivedAtStation(int index){
  stationPostArrive(index);
}


void stopAllCarInControll(){
  int arrayLeng = (int)( sizeof(stationList) / sizeof(stationList[0]) );
  for(int i = 0; i < arrayLeng; i++){
    stopCarWith(stationList[i].carID);
  }
}
//START HERE
void setup() {

  delay(2000); // Wait MCU setup
  mcu.mode(P1N, OUTPUT); // Set pin 13 to OUTPUT
  mcu.mode(P1R, OUTPUT); // Set pin 13 to OUTPUT
  mcu.mode(P2N, OUTPUT); // Set pin 13 to OUTPUT
  mcu.mode(P2R, OUTPUT); // Set pin 13 to OUTPUT
  mcu.mode(P3N, OUTPUT); // Set pin 13 to OUTPUT
  mcu.mode(P3R, OUTPUT); // Set pin 13 to OUTPUT
  mcu.mode(P4N, OUTPUT); // Set pin 13 to OUTPUT
  mcu.mode(P4R, OUTPUT); // Set pin 13 to OUTPUT
  mcu.mode(P5N, OUTPUT); // Set pin 13 to OUTPUT
  mcu.mode(P5R, OUTPUT); // Set pin 13 to OUTPUT
  mcu.mode(P6N, OUTPUT); // Set pin 13 to OUTPUT
  mcu.mode(P6R, OUTPUT); // Set pin 13 to OUTPUT
  mcu.mode(P7N, OUTPUT); // Set pin 13 to OUTPUT
  mcu.mode(P7R, OUTPUT); // Set pin 13 to OUTPUT
  mcu.mode(ENA, OUTPUT); // Set pin 13 to OUTPUT
  mcu.mode(ENB, OUTPUT); // Set pin 13 to OUTPUT

  //Set All High
  mcu.set(P1N, HIGH);
  delay(100);
  mcu.set(P1R, HIGH);
  delay(100);
  mcu.set(P2N, HIGH);
  delay(100);
  mcu.set(P2R, HIGH);
  delay(100);
  mcu.set(P3N, HIGH);
  delay(100);
  mcu.set(P3R, HIGH);
  delay(100);
  mcu.set(P4N, HIGH);
  delay(100);
  mcu.set(P4R, HIGH);
  delay(100);
  mcu.set(P5N, HIGH);
  delay(100);
  mcu.set(P5R, HIGH);
  delay(100);
  mcu.set(P6N, HIGH);
  delay(100);
  mcu.set(P6R, HIGH);
  delay(100);
  mcu.set(P7N, HIGH);
  delay(100);
  mcu.set(P7R, HIGH);
  delay(100);
  
  mcu.set(ENA, LOW);
  delay(100);
  mcu.set(ENB, LOW);
  delay(100);

  pinMode(LED_BUILTIN, OUTPUT);
  
  setupDirectionList();
  setupStationList();
  
  
  USER_SERIAL.begin(115200);
  connetWiFi();

  webSocket.begin("192.168.1.8", 5000);

  webSocket.on("connect", onConnectEvent);
  webSocket.on("cars", controller);

  //เพิ่ม Register 24/04/2021
  webSocket.on("checkStatus", onCheckStatusEvent);
  //----
}

//เพิ่ม Register 24/04/2021
void onCheckStatusEvent(const char* message, size_t length){
  registerControl();
}

void registerControl(){
  webSocket.emit("registerControl", "{\"name\":\"CT04_02\"}");
}
//----

//----------------
// Run Time Loop
//----------------
void loop() {
  
  webSocket.loop();
  // loopJunctionControll();
  loopInput();

  //led_Status
   if (millis() - startTime >= blinkRate)
    {
      blinkToggle();
      startTime = millis();
    }  
}
//----------------

void blinkToggle()
{
  led3State == 1 ? digitalWrite(LED_BUILTIN, LOW): digitalWrite(LED_BUILTIN, HIGH);
  led3State = !led3State;
}

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
// Controll  (on connect)
//----------------
void onConnectEvent(const char* message, size_t length){

  
}


//----------------
// Controll Car (on car)
//----------------
void controller(const char* message, size_t length){

  DynamicJsonDocument doc(1024);
  deserializeJson(doc, message);
    
  JsonArray objectCars = doc["cars"];
  
  int arraySize =  objectCars.size();
  
  for(int i = 0; i < arraySize; i++){
    JsonObject car = objectCars[i];
    const char* _id = car["id"];
    const int _status = car["status"];
//    const int _direction = car["direction"];
//    const char* _name = car["name"];
    const char* _to = car["to"];
    const char* _from = car["from"];

    if(_status == 3){
      int ans = checkIsInTargetList(_from, _to);
      
      if(ans >= 0){
      

        junctionController(ans);
      }

      int stationIndex = checkIsInStationList(_to);

    
      if(stationIndex >= 0){

        const char* empty = "";
  
        if (equalString(_id, empty) == true) {
          stationList[stationIndex].carID = "";
       
        }else{
          char *car_id = (char *) malloc(strlen(_id) + 1);
          strcpy(car_id,_id);
      
          stationList[stationIndex].carID = car_id;
        }
      
      }
    }

    
    
    
  }// end for
}// end controlled




//----------------

//----------------






//----------------
// Helper
//----------------

int checkIsInTargetList(const char* station1, const char* station2){

  int ans = -1;
  int arrayLeng = (int)( sizeof(directionList) / sizeof(directionList[0]) );
  for(int i = 0; i < arrayLeng; i++){
    
    if(isInTarget(station1, station2, directionList[i].target1, directionList[i].target2)){
      ans = i;
      break;
    }
  }

  return ans;
}


bool equalString(const char* s1, const char* s2){
    String str1 = String(s1);
    String str2 = String(s2);
    
    if (str1 == str2){ 
      return true;
    }else{
      return false;
    }
}

bool isInTarget(const char* station1, const char* station2, const char* target1, const char* target2){


  // Using strcmp() for check equal string
  bool res1_1 = equalString(station1, target1); 
  bool res1_2 = equalString(station2, target2); 

  bool res2_1 = equalString(station1, target2); 
  bool res2_2 = equalString(station2, target1); 
  

  if(res1_1 == true && res1_2 == true){
    return true;
  }

  if(res2_1 == true && res2_2 == true){
    return true;
  }


  return false;
}



int checkIsInStationList(const char* stationName){
  int ans = -1;

  int arrayLeng = (int)( sizeof(stationList) / sizeof(stationList[0]) );
      for(int i = 0; i < arrayLeng; i++){
    
        if(equalString(stationName, stationList[i].stationID)){
         ans = i;
         break;
       }
     }
 

  return ans;
}


void stationPostArrive(int stationIndex){
  int arrayLeng = (int)( sizeof(stationList) / sizeof(stationList[0]) );

  if(stationIndex >= 0){
    if(stationIndex < arrayLeng){

      if(stationList[stationIndex].lastCarID != stationList[stationIndex].carID){
        carArrivedWith(stationList[stationIndex]);

        stationList[stationIndex].lastCarID = stationList[stationIndex].carID;
      }
      
    }
  }
}



void stopCarWith(char* carID){
  char *body = carNameBodyWith(carID);

  webSocket.emit("stop", body);
}

void carArrivedWith(StationAndCarInterface station){


  char *body = carArrivedBodyWith(station);
   webSocket.emit("arrived", body);
  
}



char* carNameBodyWith(char* carID){
  
  char* message1 = "{\"carID\":\"";
  char* message2 = "\"}"; 

  char *message = (char *) malloc(strlen(message1) + strlen(carID) + strlen(message2) + 1);

  strcpy(message,message1);
  //USER_SERIAL.println(message);
  
  strcat(message, carID);
  //USER_SERIAL.println(message);
  
  strcat(message, message2);
  USER_SERIAL.println(message);

  return message;
  
}


char* carArrivedBodyWith(StationAndCarInterface station){

  char* stationID = station.stationID;
  char* carID = station.carID;
  
  char* message1 = "{\"carID\":\"";
  char* message2 = "\",\"stationID\":\""; 
  char* message3 = "\"}";

  char *message = (char *) malloc(strlen(message1) + strlen(stationID) + strlen(message2) + strlen(carID) + strlen(message3) + 1);

  strcpy(message,message1);
  //USER_SERIAL.println(message);
  
  strcat(message, carID);
  //USER_SERIAL.println(message);
  
  strcat(message, message2);
  //USER_SERIAL.println(message);

  strcat(message, stationID);
  //USER_SERIAL.println(message);

  strcat(message, message3);
  USER_SERIAL.println(message);

  return message;
  
}
