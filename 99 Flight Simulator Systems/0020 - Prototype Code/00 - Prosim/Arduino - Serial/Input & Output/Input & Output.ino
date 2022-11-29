#include "LedControl.h"

LedControl lc=LedControl(48,52,50,1);


String in1001;
float int1001;
String in1002;
float int1002;
String in1003;
float int1003;

String serialData;
String tmpData;
String tmpDataAdd;
String str;
int tmpIndexStart;
int tmpIndexEnd;
int tmpIndexDiff;

void setup() {
  //I/O
  pinMode(13, OUTPUT);
  pinMode(23, INPUT_PULLUP);
  //Begin Serial
  Serial.begin(9600);
  Serial.setTimeout(10);
  //LCD's  
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
  Serial.print("0000:");
  delay(1000);
  Serial.print("0001:");
}

void loop() {
//Serial Recieve
  //Pull data
    while (Serial.available() > 0) {
    serialData = Serial.readString();}
  //APU Start 1001
    tmpIndexStart = serialData.indexOf("1001=") + 5; //APU Start
    tmpIndexEnd = serialData.indexOf(":", tmpIndexStart);
    tmpIndexDiff = tmpIndexEnd - tmpIndexStart - 1;
    if (serialData.indexOf("1001=") != -1){
    for(tmpIndexDiff; tmpIndexDiff >= 0; tmpIndexDiff--) {
      tmpData = serialData.charAt(tmpIndexStart + tmpIndexDiff);  
      tmpDataAdd = tmpData + tmpDataAdd;
    }}
    if(tmpDataAdd == NULL) {}else{in1001 = tmpDataAdd; tmpDataAdd = "";tmpData = "";}
    int1001 = in1001.toFloat();
    
  //APU Avail 1002
      tmpIndexStart = serialData.indexOf("1002=") + 5; //APU Start
      tmpIndexEnd = serialData.indexOf(":", tmpIndexStart);
      tmpIndexDiff = tmpIndexEnd - tmpIndexStart - 1;
      if (serialData.indexOf("1002=") != -1){
      for(tmpIndexDiff; tmpIndexDiff >= 0; tmpIndexDiff--) {
        tmpData = serialData.charAt(tmpIndexStart + tmpIndexDiff);  
        tmpDataAdd = tmpData + tmpDataAdd;
      }}
      if(tmpDataAdd == NULL) {}else{in1002 = tmpDataAdd; tmpDataAdd = "";tmpData = "";}
      int1002 = in1002.toFloat();
      
  //APU N 1003  
      tmpIndexStart = serialData.indexOf("1003=") + 5; //APU Start
      tmpIndexEnd = serialData.indexOf(":", tmpIndexStart);
      tmpIndexDiff = tmpIndexEnd - tmpIndexStart - 1;
      if (serialData.indexOf("1003=") != -1){
      for(tmpIndexDiff; tmpIndexDiff >= 0; tmpIndexDiff--) {
        tmpData = serialData.charAt(tmpIndexStart + tmpIndexDiff);  
        tmpDataAdd = tmpData + tmpDataAdd;
      }}
      if(tmpDataAdd == NULL) {}else{in1003 = tmpDataAdd; tmpDataAdd = "";tmpData = "";}
      int1003 = in1003.toFloat();
          

//Hardware Output
  //APU N Display  
    printNumber(int1003);
  //APU LED
    if(int1001 == 1 || int1002 == 1) {
      digitalWrite(13, HIGH);
      }else{
      digitalWrite(13, LOW);
    }
//Serial Output
  //APU Start 1005-OFF 1004-ON        
    if(digitalRead(23) == HIGH) {Serial.print("1005:");}else{Serial.print("1004:");}

// DEBUG OUTPUT
/*
Serial.print("in1002 "); Serial.println(int1002);
Serial.print("in1003 "); Serial.println(int1003);
Serial.print("in1001 "); Serial.println(int1001);
delay(100);
*/
delay(1);
}

void printNumber(int v) {  
    int ones;  
    int tens;  
    int hundreds;

    boolean negative=false;

    if(v < -999 || v > 999)  
        return;  
    if(v<0) {  
        negative=true; 
        v=v*-1;  
    }
    ones=v%10;  
    v=v/10;  
    tens=v%10;  
    v=v/10; hundreds=v;  
    if(negative) {  
        //print character '-' in the leftmost column  
        lc.setChar(0,3,'-',false);  } 
    else {
        //print a blank in the sign column  
        lc.setChar(0,3,' ',false);  
    }  
    //Now print the number digit by digit 
    lc.setDigit(0,2,(byte)hundreds,false);
    lc.setDigit(0,1,(byte)tens,false); 
    lc.setDigit(0,0,(byte)ones,false); 
    
} 


