void loopInput(){

//1 B02-A-1
   if(get_IR_sensor0_Value() == "0"){
    carArrivedAtStation(0);
    Serial.print("B02-A-1 ");
   }

//2 B02-A-2
   if(get_IR_sensor1_Value() == "0"){
    carArrivedAtStation(0);
    Serial.print("B02-A-2 ");
   }
   
//3 B03-A-1
   if(get_IR_sensor2_Value() == "0"){
    carArrivedAtStation(2);
    Serial.print("B03-A-1 ");
   }
   
//4 B03-A-2
   if(get_IR_sensor3_Value() == "0"){
    carArrivedAtStation(2);
    Serial.print("B03-A-2 ");
   }
   
//5 B04-A-1
   if(get_IR_sensor4_Value() == "0"){
    carArrivedAtStation(4);
    Serial.print("B04-A-1 ");
   }
   
//6 B04-A-2
   if(get_IR_sensor5_Value() == "0"){
    carArrivedAtStation(4);
    Serial.print("B04-A-2 ");
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
