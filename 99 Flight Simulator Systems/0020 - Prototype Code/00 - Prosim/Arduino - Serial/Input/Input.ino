#include <LedControl.h>

/* binary test*/

LedControl lc=LedControl(A2,A0,A1,1);

int i = 0;
int j = 0;
void setup() {
  pinMode(22, OUTPUT); 
  pinMode(23, INPUT_PULLUP);
  pinMode(24, OUTPUT); 
  pinMode(25, INPUT_PULLUP);
  pinMode(26, OUTPUT); 
  pinMode(27, INPUT_PULLUP);
  pinMode(28, OUTPUT); 
  pinMode(29, INPUT_PULLUP);
  pinMode(30, OUTPUT); 
  pinMode(31, INPUT_PULLUP);
  pinMode(32, OUTPUT); 
  pinMode(33, INPUT_PULLUP);
  pinMode(34, OUTPUT); 
  pinMode(35, INPUT_PULLUP);
  pinMode(36, OUTPUT); 
  pinMode(37, INPUT_PULLUP);
  pinMode(38, OUTPUT); 
  pinMode(39, INPUT_PULLUP);
  pinMode(40, OUTPUT); 
  pinMode(41, INPUT_PULLUP);
  pinMode(42, OUTPUT); 
  pinMode(43, INPUT_PULLUP);
  pinMode(44, OUTPUT); 
  pinMode(45, INPUT_PULLUP);
  pinMode(46, OUTPUT); 
  pinMode(47, INPUT_PULLUP);
  pinMode(48, OUTPUT); 
  pinMode(49, INPUT_PULLUP);
  pinMode(53, INPUT_PULLUP);

  pinMode(2, OUTPUT); 
  pinMode(3, INPUT_PULLUP);
  pinMode(4, OUTPUT); 
  pinMode(5, INPUT_PULLUP);
  pinMode(6, OUTPUT); 
  pinMode(7, INPUT_PULLUP);
  pinMode(8, OUTPUT); 
  pinMode(9, INPUT_PULLUP);
  pinMode(10, OUTPUT); 
  pinMode(11, INPUT_PULLUP);
  pinMode(12, OUTPUT); 
  pinMode(13, INPUT_PULLUP);
  pinMode(14, OUTPUT); 
  pinMode(15, INPUT_PULLUP);
  pinMode(16, OUTPUT); 
  pinMode(17, INPUT_PULLUP);
  pinMode(18, OUTPUT); 
  pinMode(19, INPUT_PULLUP);
  pinMode(20, OUTPUT); 
  pinMode(21, INPUT_PULLUP);


  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);

  //Begin Serial
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
//Serial Output
  //APU Start 1005-OFF 1004-ON        
    if(digitalRead(23) == LOW){
      i = 1;
    }
    if(digitalRead(25) == LOW){
      i = i +2;
    }
    if(digitalRead(27) == LOW){
      i = i+4;
    }
    if(digitalRead(29) == LOW){
      i = i+8;
    }
    if(digitalRead(31) == LOW){
      i = i+16;
    }
    if(digitalRead(33) == LOW){
      i = i+32;
    }
    if(digitalRead(35) == LOW){
      i = i+64;
    }
    if(digitalRead(37) == LOW){
      i = i+128;
    }
    if(digitalRead(39) == LOW){
      i = i+256;
    }
    if(digitalRead(41) == LOW){
      i = i+512;
    }
    if(digitalRead(43) == LOW){
      i = i+1024;
    }
    if(digitalRead(45) == LOW){
      i = i+2048;
    }
    if(digitalRead(47) == LOW){
      i = i+4096;
    }
    if(digitalRead(49) == LOW){
      i = i+8192;
    }


    if(digitalRead(3) == LOW){
      j = 1;
    }
    if(digitalRead(5) == LOW){
      j = j+2;
    }
    if(digitalRead(7) == LOW){
      j = j+4;
    }
    if(digitalRead(9) == LOW){
      j = j+8;
    }
    if(digitalRead(11) == LOW){
      j = j+16;
    }
    if(digitalRead(13) == LOW){
      j = j+32;
    }
    if(digitalRead(15) == LOW){
      j = j+64;
    }
    if(digitalRead(17) == LOW){
      j = j+128;
    }
    if(digitalRead(19) == LOW){
      j = j+256;
    }
    if(digitalRead(21) == LOW){
      j = j+512;
    }
    
  if(digitalRead(53) == LOW){
    Serial.print(i);Serial.print("=");Serial.print(j);Serial.println(":");}
  printNumber(i);
  printNumberTwo(j);
  i=0;
  j=0;
  
delay(1);
}
void printNumber(int v) {  
    int ones;  
    int tens;  
    int hundreds;
    int thousands;

    boolean negative=false;

    if(v < -9999 || v > 9999)  
        return;  
    if(v<0) {  
        negative=true; 
        v=v*-1;  
    }
    ones=v%10;  
    v=v/10;  
    tens=v%10;  
    v=v/10; 
    hundreds=v%10;
    v=v/10;
    thousands=v;  
    //Now print the number digit by digit 
    lc.setDigit(0,7,(byte)thousands,false);
    lc.setDigit(0,6,(byte)hundreds,false);
    lc.setDigit(0,5,(byte)tens,false); 
    lc.setDigit(0,4,(byte)ones,false); 
    
} 
void printNumberTwo(int v) {  
    int ones;  
    int tens;  
    int hundreds;
    int thousands;

    boolean negative=false;

    if(v < -9999 || v > 9999)  
        return;  
    if(v<0) {  
        negative=true; 
        v=v*-1;  
    }
    ones=v%10;  
    v=v/10;  
    tens=v%10;  
    v=v/10; 
    hundreds=v%10;
    v=v/10;
    thousands=v;  
    //Now print the number digit by digit 
    lc.setDigit(0,3,(byte)thousands,false);
    lc.setDigit(0,2,(byte)hundreds,false);
    lc.setDigit(0,1,(byte)tens,false); 
    lc.setDigit(0,0,(byte)ones,false); 
} 