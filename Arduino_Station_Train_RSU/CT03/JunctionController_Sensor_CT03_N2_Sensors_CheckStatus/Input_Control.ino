void loopInput(){
  // read input data here
  
//1 B09-A-1
   if(get_IR_sensor0_Value() == "0"){
    carArrivedAtStation(6);
    Serial.print("B09-A-1 ");
   }

//2 B09-A-2
   if(get_IR_sensor1_Value() == "0"){
    carArrivedAtStation(6);
    Serial.print("B09-A-2 ");
   }
   
//3 B11-C-1
   if(get_IR_sensor2_Value() == "0"){
    carArrivedAtStation(4);
    Serial.print("B11-C-1 ");
   }
   
//4 B11-C-2
   if(get_IR_sensor3_Value() == "0"){
    carArrivedAtStation(4);
    Serial.print("B11-C-2 ");
   }
   
//5 B11-D-1
   if(get_IR_sensor4_Value() == "0"){
    carArrivedAtStation(5);
    Serial.print("B11-D-1 ");
   }
   
//6 B11-D-2
   if(get_IR_sensor5_Value() == "0"){
    carArrivedAtStation(5);
    Serial.print("B11-D-2 ");
   }
   
//7 B09-B-1
   if(get_IR_sensor6_Value() == "0"){
    carArrivedAtStation(7);
    Serial.print("B09-B-1 ");
   }
   
//8 B09-B-2
   if(get_IR_sensor7_Value() == "0"){
    carArrivedAtStation(7);
    Serial.print("B09-B-2 ");
   }

}

// get IR sensor 0 data
String get_IR_sensor0_Value(){ 
   
IR_sensor0_Value = digitalRead(IR_sensor0Pin);
    //delay(1);
    return String(IR_sensor0_Value);
}

// get IR sensor 1 data
String get_IR_sensor1_Value(){ 
   
IR_sensor1_Value =digitalRead(IR_sensor1Pin);
    //delay(1);
    return String(IR_sensor1_Value);
}

// get IR sensor 2 data
String get_IR_sensor2_Value(){ 
   
IR_sensor2_Value =digitalRead(IR_sensor2Pin);
//delay(1);
    return String(IR_sensor2_Value);  
}

// get IR sensor 3 data
String get_IR_sensor3_Value(){ 
   
IR_sensor3_Value =digitalRead(IR_sensor3Pin);
//delay(1);
    return String(IR_sensor3_Value);  
}

// get IR sensor 4 data
String get_IR_sensor4_Value(){ 
   
IR_sensor4_Value =digitalRead(IR_sensor4Pin);
//delay(1);
    return String(IR_sensor4_Value);  
}

// get IR sensor 5 data
String get_IR_sensor5_Value(){ 
   
IR_sensor5_Value =digitalRead(IR_sensor5Pin);
//delay(1);
    return String(IR_sensor5_Value);  
}

// get IR sensor 6 data
String get_IR_sensor6_Value(){ 
   
IR_sensor6_Value =digitalRead(IR_sensor6Pin);
//delay(1);
    return String(IR_sensor6_Value);  
}

// get IR sensor 7 data
String get_IR_sensor7_Value(){ 
   
IR_sensor7_Value =digitalRead(IR_sensor7Pin);
//delay(1);
    return String(IR_sensor7_Value);  
}
