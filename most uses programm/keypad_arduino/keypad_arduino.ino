#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
String keys1 = "";
String keys2 = "";
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8,9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  pinMode(10,OUTPUT);
  Serial.begin(9600);
}
  
void loop(){
  char key = keypad.getKey();
  keys2 = String(key);
  if(key){ 
 keys1 = keys1+keys2;
Serial.print(keys2);
  }
 if(keys1=="A"){
  Serial.println("RELAY IS ON");
  digitalWrite(10,HIGH);
    keys1="";
    
  }
  if(keys1=="B"){
  Serial.println("RELAY IS OFF");
  digitalWrite(10,LOW);
    keys1="";
    
  }

  
  // this checkes if 4 is pressed, then do something. Here  we print the text but you can control something.
}
        
