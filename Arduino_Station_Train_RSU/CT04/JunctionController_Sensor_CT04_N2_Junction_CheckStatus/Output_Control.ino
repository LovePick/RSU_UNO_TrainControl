void junctionController(int index){
//P1-P9A, P2-P9B
if(index != lastJunction){
  switch(index){
    case 0:
    //Do something
    Serial.print ("B11-A->B01-A");
    
    break;
    case 1:
    //Do something
    Serial.print ("B11-B->B01-B");
    
    break;
    case 2:
    //Do something
    Serial.print ("B01-A->TB01");
    //Point 9A Normal P1
      P1Normal();
    //Point 9B Normal P2
      P2Normal();
    break;
    case 3:
    //Do something
    Serial.print ("B01-A->TB02");
    //Point 9A Reverse P1
      P1Reverse();
    //Point 9B Reverse P2
      P2Reverse();
    break;
    case 4:
    //Do something
    Serial.print ("B01-B->TB01");
    //Point 9A Reverse P1
      P1Reverse();
    //Point 9B Reverse P2
      P2Reverse();
    break;
    case 5:
    //Do something
    Serial.print ("B01-B->TB02");  
    //Point 9A Normal P1
      P1Normal();
    //Point 9B Normal P2
      P2Normal();
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
