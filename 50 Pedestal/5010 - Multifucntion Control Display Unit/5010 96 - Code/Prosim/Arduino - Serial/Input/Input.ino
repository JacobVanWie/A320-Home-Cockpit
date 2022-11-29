#include <Keypad.h>


const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad lsKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  pinMode(23, INPUT_PULLUP);

  //Begin Serial
  Serial.begin(9600);
  Serial.setTimeout(10);

  Serial.print("0000:");
  delay(1000);
  Serial.print("0001:");
}

void loop() {
//Serial Output
  //APU Start 1005-OFF 1004-ON        
    if(digitalRead(23) == HIGH) {Serial.print("1005:");}else{Serial.print("1004:");}

  char lsKey = lsKeypad.getKey();
  if (lsKey != NO_KEY){
    Serial.println(lsKey);
  }


    Serial.println("");

delay(1);
}
