String floatNumberStringInput;

const String deviceIdentifier = "3";
const int variableCount = 60;
float floatVariable[variableCount];

// Read String Variables
  String serialData;


void setup() {
  //I/O
  pinMode(3, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(44, OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(46, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);
  //Begin Serial
  Serial.begin(9600);
  Serial.setTimeout(10);
  //Two Outputs are sent to the software to Tell it to send all output states
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
    //Serial.print(i);Serial.print("=");Serial.print(floatVariable[i]);Serial.print(" ");
  }
  //Serial.println();

//Hardware Output
  //APU LED
    if(floatVariable[1] == 1) {digitalWrite(13, HIGH);}else{digitalWrite(13, LOW);}
    analogWrite(3, (floatVariable[2]/5.1));
    digitalWrite(42, floatVariable[42]);
    digitalWrite(43, floatVariable[43]);
    digitalWrite(44, floatVariable[44]);
    digitalWrite(45, floatVariable[45]);
    digitalWrite(46, floatVariable[46]);
    digitalWrite(47, floatVariable[47]);
    digitalWrite(48, floatVariable[48]);
    digitalWrite(49, floatVariable[49]);
    digitalWrite(50, floatVariable[50]);
    digitalWrite(51, floatVariable[51]);
    digitalWrite(52, floatVariable[52]);
    digitalWrite(53, floatVariable[53]);

  
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


