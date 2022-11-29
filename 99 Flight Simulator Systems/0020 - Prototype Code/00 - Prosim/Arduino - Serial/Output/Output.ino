#include "LedControl.h"

LedControl lcdOne=LedControl(48,52,50,1);

String floatNumberStringInput;

const String deviceIdentifier = "2";
const int variableCount = 3;
float floatVariable[variableCount];

// Read String Variables
  String serialData;


void setup() {
  //I/O
  pinMode(13, OUTPUT);
  //Begin Serial
  Serial.begin(9600);
  Serial.setTimeout(10);
  //Two Outputs are sent to the software to Tell it to send all output states
  //LCD's  
  lcdOne.shutdown(0,false);
  lcdOne.setIntensity(0,8);
  lcdOne.clearDisplay(0);
  Serial.print("0000:");
  delay(1000);
  Serial.print("0001:");
}

void loop() {
//Serial Recieve
  //Pull data
    while (Serial.available() > 0) { //Check if Data Is Avail
    serialData = Serial.readString();} //Read Data to serialData
  
  for(int i = 0; i < variableCount; i++){
    if (i < 10){
      floatVariable[i] = floatNumber(deviceIdentifier + "00" + String(i), serialData, floatVariable[i]);
    } else if (i >= 10 && i < 100) {
      floatVariable[i] = floatNumber(deviceIdentifier + "0" + String(i), serialData, floatVariable[i]);
    } else if (i >= 100 && i < 1000) {
      floatVariable[i] = floatNumber(deviceIdentifier + String(i), serialData, floatVariable[i]);
    }
    //Debug Ouput
    Serial.print(i);Serial.print("=");Serial.print(floatVariable[i]);Serial.print(" ");
  }
  //Debug Ouput 
  Serial.println();
//Hardware Output
  //APU LED
    if(floatVariable[1] == 1) {digitalWrite(13, HIGH);}else{digitalWrite(13, LOW);}
  //lcd one output
  printLcdOne(floatVariable[0]);
// DEBUG OUTPUT
 
delay(1); //Stability Delay
}


float floatNumber(String floatNumberStringInput, String serialData, float carryOver) {
  String tmpData;
  String tmpDataAdd;
  String str;
  String result;
  int tmpIndexStart;
  int tmpIndexEnd;
  int tmpIndexDiff;
  if (strstr(serialData.c_str(), floatNumberStringInput.c_str()) != NULL){
    tmpIndexStart = serialData.indexOf(floatNumberStringInput + "=") + 5;
    tmpIndexEnd = serialData.indexOf(":", tmpIndexStart); 
    tmpIndexDiff = tmpIndexEnd - tmpIndexStart - 1;
    if (serialData.indexOf(floatNumberStringInput + "=") != -1){ 
      for(tmpIndexDiff; tmpIndexDiff >= 0; tmpIndexDiff--) { 
        tmpData = serialData.charAt(tmpIndexStart + tmpIndexDiff); 
        tmpDataAdd = tmpData + tmpDataAdd;
    }}
    if(tmpDataAdd == NULL) {} 
    else{result = tmpDataAdd; tmpDataAdd = "";tmpData = "";} 
    return result.toFloat();
  } else {
    return carryOver;
  }
}

void printLcdOne(int v) {  
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
        lcdOne.setChar(0,3,'-',false);  } 
    else {
        //print a blank in the sign column  
        lcdOne.setChar(0,3,' ',false);  
    }  
    //Now print the number digit by digit 
    lcdOne.setDigit(0,2,(byte)hundreds,false);
    lcdOne.setDigit(0,1,(byte)tens,false); 
    lcdOne.setDigit(0,0,(byte)ones,false); 
    
} 
