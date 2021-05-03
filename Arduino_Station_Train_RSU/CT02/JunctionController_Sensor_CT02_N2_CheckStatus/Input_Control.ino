void loopInput(){

//1 B04-B-1
   if(get_IR_sensor0_Value() == "0"){
    carArrivedAtStation(5);
    Serial.print("B04-B-1 ");
   }

//2 B04-B-2
   if(get_IR_sensor1_Value() == "0"){
    carArrivedAtStation(5);
    Serial.print("B04-B-2 ");
   }
   
//3 B03-B-1
   if(get_IR_sensor2_Value() == "0"){
    carArrivedAtStation(3);
    Serial.print("B03-B-1 ");
   }
   
//4 B03-B-2
   if(get_IR_sensor3_Value() == "0"){
    carArrivedAtStation(3);
    Serial.print("B03-B-2 ");
   }
   
//5 B02-B-1
   if(get_IR_sensor4_Value() == "0"){
    carArrivedAtStation(1);
    Serial.print("B02-B-1 ");
   }
   
//6 B02-B-2
   if(get_IR_sensor5_Value() == "0"){
    carArrivedAtStation(1);
    Serial.print("B02-B-2 ");
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
