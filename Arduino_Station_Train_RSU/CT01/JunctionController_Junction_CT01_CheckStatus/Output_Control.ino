void junctionController(int index){

  if(index != lastJunction){

    switch(index){
    case 0:      
      Serial.print ("D01->B02-A");     
      //Point 7 Normal
        P7Normal();
      //Point 6 Reverse
        P6Reverse();
      //Point 5 Reverse
        P5Reverse();
    break;
    
    case 1:
    Serial.print ("D01->B02-B");
    //Point 7 Reverse
        P7Reverse();
      //Point 6 Reverse
        P6Reverse();
      //Point 5 Reverse
        P5Reverse();
    break;
    
    case 2:    
      Serial.print ("D02->B02-A");                 
     //Point 7 Normal
       P7Normal();        
     //Point 6 Reverse
       P6Reverse();
     //Point 5 Normal
       P5Normal();          
      //Point 4 Reverse
        P4Reverse();            
     //Point 3 Reverse
        P3Reverse();;         
    
    break;
    
    case 3:    
    Serial.print ("D02->B02-B");
    //Point 7 Reverse
        P7Reverse();
     //Point 6 Reverse
        P6Reverse();
     //Point 5 Normal
        P5Normal();
      //Point 4 Reverse
        P4Reverse();
      //Point 3 Reverse
        P3Reverse();
    break;
    
    case 4:
    //Do something
    //เส้นทาง [4] กับ [5] ใช้ตัวสับลางตัวเดียวกัน
    //เลยต้องเซทให้โปรแกรมรู้ว่า ทำงานในเส้นทางไหนอยู่
    //เพื่อไม่ให้ cpu ทำงานมากไป
    if(directionList[4].myactive == false){
      directionList[4].myactive = true;

      directionList[5].myactive = false;

      Serial.print ("D03->B02-A");
           
      //Point 7 Normal
        P7Normal();
      //Point 6 Reverse
        P6Reverse();
      //Point 5 Normal
        P5Normal();
      //Point 4 Reverse
        P4Reverse();
      //Point 3 Normal
        P3Normal();
      //Point 2 Reverse
        P2Reverse();    
    }
    
    break;
    
    case 5:
    //Do something

    if(directionList[5].myactive == false){
      directionList[5].myactive = true;

      directionList[4].myactive = false;
      

      //digitalWrite(D8, LOW);
      
      Serial.print ("D003->B02-B");
          
      //Point 7 Reverse
        P7Reverse();
      //Point 6 Reverse
        P6Reverse();
      //Point 5 Normal
        P5Normal();
      //Point 4 Reverse
        P4Reverse();
      //Point 3 Normal
        P3Normal();
      //Point 2 Reverse
        P2Reverse();
   
    }
    
    
    break;

    case 6:
    //Do something    
    //เส้นทาง [6] กับ [7] ใช้ตัวสับลางตัวเดียวกัน
    //เลยต้องเซทให้โปรแกรมรู้ว่า ทำงานในเส้นทางไหนอยู่
    //เพื่อไม่ให้ cpu ทำงานมากไป
    if(directionList[6].myactive == false){
      directionList[6].myactive = true;

      directionList[7].myactive = false;

      // ควบคุมตัวสับราง
      //digitalWrite(D8, HIGH);
      
      Serial.print ("D04->B02-A");
           
      //Point 7 Normal
         P7Normal();
      //Point 6 Reverse
        P6Reverse();
      //Point 5 Normal
         P5Normal();
      //Point 4 Reverse
        P4Reverse();
      //Point 3 Normal
         P3Normal();
      //Point 2 Normal
        P2Normal();
    
    }
    
    break;
    case 7:
    //Do something    
    //เส้นทาง [6] กับ [7] ใช้ตัวสับลางตัวเดียวกัน
    //เลยต้องเซทให้โปรแกรมรู้ว่า ทำงานในเส้นทางไหนอยู่
    //เพื่อไม่ให้ cpu ทำงานมากไป
    if(directionList[7].myactive == false){
      directionList[7].myactive = true;

      directionList[6].myactive = false;

      // ควบคุมตัวสับราง
      //digitalWrite(D8, HIGH);
      
      Serial.print ("D04->B02-B");
      
      //Point 7 Reverse
        P7Reverse();
      //Point 6 Reverse
        P6Reverse();
      //Point 5 Normal
         P5Normal();
      //Point 4 Reverse
         P4Reverse();
      //Point 3 Normal
         P3Normal();
      //Point 2 Normal
        P2Normal();
    
    }
    
    break;
    case 8:
    //Do something    
    //เส้นทาง [8] กับ [9] ใช้ตัวสับลางตัวเดียวกัน
    //เลยต้องเซทให้โปรแกรมรู้ว่า ทำงานในเส้นทางไหนอยู่
    //เพื่อไม่ให้ cpu ทำงานมากไป
    if(directionList[8].myactive == false){
      directionList[8].myactive = true;

      directionList[9].myactive = false;

      // ควบคุมตัวสับราง
      //digitalWrite(D8, HIGH);
      
      Serial.print ("D05->B02-A");
     // 1      2     3     4     5       6       7
     // 2,3    4,5   6,7   8,9   10,11   12,13   A0,A1 
      
      //Point 7 Normal
       P7Normal();
      //Point 6 Reverse
        P6Reverse();
      //Point 5 Normal
        P5Normal();
      //Point 4 Normal
        P4Normal();
      //Point 1 Normal
        P1Normal();
        
    }
    
    break;
    case 9:
    //Do something    
    //เส้นทาง [8] กับ [9] ใช้ตัวสับลางตัวเดียวกัน
    //เลยต้องเซทให้โปรแกรมรู้ว่า ทำงานในเส้นทางไหนอยู่
    //เพื่อไม่ให้ cpu ทำงานมากไป
    if(directionList[9].myactive == false){
      directionList[9].myactive = true;

      directionList[8].myactive = false;

      // ควบคุมตัวสับราง
      //digitalWrite(D8, HIGH);
      
      Serial.print ("D05->B02-B");
     
      //Point 7 Reverse
        P7Reverse();
      //Point 6 Reverse
        P6Reverse();
      //Point 5 Normal
        P5Normal();
      //Point 4 Normal
        P4Normal();
      //Point 1 Normal
        P1Normal();
    }
    
    break;
    case 10:
    //Do something    
    //เส้นทาง [10] กับ [11] ใช้ตัวสับลางตัวเดียวกัน
    //เลยต้องเซทให้โปรแกรมรู้ว่า ทำงานในเส้นทางไหนอยู่
    //เพื่อไม่ให้ cpu ทำงานมากไป
    if(directionList[10].myactive == false){
      directionList[10].myactive = true;

      directionList[11].myactive = false;

      // ควบคุมตัวสับราง
      //digitalWrite(D8, HIGH);
      
      Serial.print ("D06->B02-A");
     // 1      2     3     4     5       6       7
     // 2,3    4,5   6,7   8,9   10,11   12,13   A0,A1 
      
      //Point 7 Normal
        P7Normal();
      //Point 6 Reverse
        P6Reverse();
      //Point 5 Normal
        P5Normal();
      //Point 4 Normal
        P4Normal();
      //Point 1 Reverse
        P1Reverse();
    }
    
    break;
    case 11:
    //Do something    
    //เส้นทาง [10] กับ [11] ใช้ตัวสับลางตัวเดียวกัน
    //เลยต้องเซทให้โปรแกรมรู้ว่า ทำงานในเส้นทางไหนอยู่
    //เพื่อไม่ให้ cpu ทำงานมากไป
    if(directionList[10].myactive == false){
      directionList[10].myactive = true;

      directionList[11].myactive = false;
  
      Serial.print ("D06->B02-B");
     
      //Point 7 Reverse
        P7Reverse();
      //Point 6 Reverse
        P6Reverse();
      //Point 5 Normal
        P5Normal();
      //Point 4 Normal
        P4Normal();
      //Point 1 Reverse
        P1Reverse();
    }
    
    break;
    
    case 12:    
      Serial.print ("D07->B02-A");
      //Point 7 Normal
        P7Normal();
      //Point 6 Normal
        P6Normal();
      
    break;
    
    case 13:      
      Serial.print ("D07->B02-B");
      //Point 7 Reverse
        P7Reverse();
      //Point 6 Normal
        P6Normal();
    
    break;

    default:
    break;
    
  }
  lastJunction = index;
  }  
}

void P1Normal(){
  //Point 1 Normal
        mcu.set(P1N, LOW);  delay(100);
        mcu.set(ENB, HIGH); delay(100);
        mcu.set(ENB, LOW);  delay(100);
        mcu.set(P1N, HIGH); delay(100);
}

void P1Reverse(){
  //Point 1 Reverse
        mcu.set(P1R, LOW);  delay(100);
        mcu.set(ENB, HIGH); delay(100);
        mcu.set(ENB, LOW);  delay(100);
        mcu.set(P1R, HIGH); delay(100);
}

void P2Normal(){
  //Point 2 Normal
        mcu.set(P2N, LOW);  delay(100);
        mcu.set(ENB, HIGH); delay(100);
        mcu.set(ENB, LOW);  delay(100);
        mcu.set(P2N, HIGH); delay(100);
}

void P2Reverse(){
  //Point 2 Reverse
        mcu.set(P2R, LOW);  delay(100);
        mcu.set(ENB, HIGH); delay(100);
        mcu.set(ENB, LOW);  delay(100);
        mcu.set(P2R, HIGH); delay(100);
}

void P3Normal(){
  //Point 3 Normal
        mcu.set(P3N, LOW);  delay(100);
        mcu.set(ENB, HIGH); delay(100);
        mcu.set(ENB, LOW);  delay(100);
        mcu.set(P3N, HIGH); delay(100);
}

void P3Reverse(){
  //Point 3 Reverse
        mcu.set(P3R, LOW);  delay(100);
        mcu.set(ENB, HIGH); delay(100);
        mcu.set(ENB, LOW);  delay(100);
        mcu.set(P3R, HIGH); delay(100);
}

void P4Normal(){
  //Point 4 Normal
        mcu.set(P4N, LOW);  delay(100);
        mcu.set(ENB, HIGH); delay(100);
        mcu.set(ENB, LOW);  delay(100);
        mcu.set(P4N, HIGH); delay(100);
}

void P4Reverse(){
  //Point 4 Reverse
        mcu.set(P4R, LOW);  delay(100);
        mcu.set(ENB, HIGH); delay(100);
        mcu.set(ENB, LOW);  delay(100);
        mcu.set(P4R, HIGH); delay(100);
}

void P5Normal(){
  //Point 5 Normal
        mcu.set(P5N, LOW);  delay(100);
        mcu.set(ENB, HIGH); delay(100);
        mcu.set(ENB, LOW);  delay(100);
        mcu.set(P5N, HIGH); delay(100);
}

void P5Reverse(){
  //Point 5 Reverse
        mcu.set(P5R, LOW);  delay(100);
        mcu.set(ENB, HIGH); delay(100);
        mcu.set(ENB, LOW);  delay(100);
        mcu.set(P5R, HIGH); delay(100);
}

void P6Normal(){
  //Point 6 Normal
        mcu.set(P6N, LOW);  delay(100);
        mcu.set(ENB, HIGH); delay(100);
        mcu.set(ENB, LOW);  delay(100);
        mcu.set(P6N, HIGH); delay(100);
}

void P6Reverse(){
  //Point 6 Reverse
        mcu.set(P6R, LOW);  delay(100);
        mcu.set(ENB, HIGH); delay(100);
        mcu.set(ENB, LOW);  delay(100);
        mcu.set(P6R, HIGH); delay(100);
}

void P7Normal(){
  //Point 7 Normal
        mcu.set(P7N, LOW);  delay(100);
        mcu.set(ENB, HIGH); delay(100);
        mcu.set(ENB, LOW);  delay(100);
        mcu.set(P7N, HIGH); delay(100);
}

void P7Reverse(){
  //Point 7 Reverse
        mcu.set(P7R, LOW);  delay(100);
        mcu.set(ENB, HIGH); delay(100);
        mcu.set(ENB, LOW);  delay(100);
        mcu.set(P7R, HIGH); delay(100);
}
