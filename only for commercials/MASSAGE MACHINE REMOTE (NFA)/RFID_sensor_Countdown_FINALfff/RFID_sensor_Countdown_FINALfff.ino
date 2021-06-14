//BOBBY VIDEO GAMES
#include <SPI.h>
#include <MFRC522.h>
#include <TM1638.h>
#include <EEPROM.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 TM1638 module(3, 4, 5);
long int a,x=0,z=300 ,relay=4,NOC=1;
uint8_t EEPROMaddress = 130;

void setup() 
{Serial.begin(9600);
  delay(50000);
  pinMode(2,OUTPUT);
  pinMode(6,OUTPUT);
     // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  digitalWrite(2,LOW); 
  digitalWrite(6,LOW);
  delay(1000);
  digitalWrite(2,HIGH);
  digitalWrite(6,HIGH);
delay(2000);
digitalWrite(2,LOW);
  digitalWrite(6,LOW);
  delay(1000);
  digitalWrite(2,HIGH);
  digitalWrite(6,HIGH);
delay(10000);
}
void loop() 
{
    

    module.setDisplayToDecNumber(z,0,false);
x = EEPROM.read(EEPROMaddress);
EEPROM.write(EEPROMaddress,x);
 String number2 = String(x,DEC);
module.setDisplayToString(number2);
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  String content= "";
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {  content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  String content2=content.substring(1);
  delay(1000);
  
if(content2=="34 a9 3d b6"){  //5c Time

z = z+300;
relay=relay+1;
if(z>1800){
  z=300;
  relay =4;
  }

}
if(content2=="a4 da 3d b6"){  //5c Time

z = z+300;
relay=relay+1;
if(z>1800){
  z=300;
   relay =4;
  }

}

if(content2=="b0 51 6b 2a"){ //4c START
digitalWrite(2,LOW);
delay(800);
digitalWrite(2,HIGH);
delay(1000);
for(int j=0;j<relay;j++){
digitalWrite(6,LOW);
delay(500);
digitalWrite(6,HIGH);
delay(500);
}

 x=x+NOC;
 if(x>250){
   for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
x=1;
  }
  
 EEPROM.write(EEPROMaddress,x);
String number2 = String(x,DEC);
module.setDisplayToString(number2);

for (a=z; a>=1; a--)
{
module.setDisplayToDecNumber(a,0,false);
module.setDisplayToString(number2);

   delay(1000);
}
digitalWrite(2,LOW);
delay(300);
digitalWrite(2,HIGH);
delay(300);
digitalWrite(2,LOW);
delay(300);
digitalWrite(2,HIGH);
}
if(content2=="84 44 1e b6"){ //4c START
digitalWrite(2,LOW);
delay(800);
digitalWrite(2,HIGH);
delay(1000);
for(int j=0;j<relay;j++){
digitalWrite(6,LOW);
delay(500);
digitalWrite(6,HIGH);
delay(500);
}

 x=x+NOC;
 if(x>250){
   for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
x=1;
  }
  
 EEPROM.write(EEPROMaddress,x);
String number2 = String(x,DEC);
module.setDisplayToString(number2);

for (a=z; a>=1; a--)
{
module.setDisplayToDecNumber(a,0,false);
module.setDisplayToString(number2);

   delay(1000);
}
digitalWrite(2,LOW);
delay(300);
digitalWrite(2,HIGH);
delay(300);
digitalWrite(2,LOW);
delay(300);
digitalWrite(2,HIGH);
}
if(content2=="d9 d1 91 d5"){ //4c START
digitalWrite(2,LOW);
delay(800);
digitalWrite(2,HIGH);
delay(1000);
for(int j=0;j<relay;j++){
digitalWrite(6,LOW);
delay(500);
digitalWrite(6,HIGH);
delay(500);
}
//BOBBY VIDEO GAMES
 x=x+NOC;
 if(x>250){
   for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
x=1;
  }
  
 EEPROM.write(EEPROMaddress,x);
String number2 = String(x,DEC);
module.setDisplayToString(number2);

for (a=z; a>=1; a--)
{
module.setDisplayToDecNumber(a,0,false);
module.setDisplayToString(number2);

   delay(1000);
}
//BOBBY VIDEO GAMES
digitalWrite(2,LOW);
delay(300);
digitalWrite(2,HIGH);
delay(300);
digitalWrite(2,LOW);
delay(300);
digitalWrite(2,HIGH);
}
if(content2=="5a 59 75 3c"){ //4c START
digitalWrite(2,LOW);
delay(800);
digitalWrite(2,HIGH);
delay(1000);
for(int j=0;j<relay;j++){
digitalWrite(6,LOW);
delay(500);
digitalWrite(6,HIGH);
delay(500);
}
//BOBBY VIDEO GAMES
 x=x+NOC;
 if(x>250){
   for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
x=1;
  }
  
 EEPROM.write(EEPROMaddress,x);
String number2 = String(x,DEC);
module.setDisplayToString(number2);

for (a=z; a>=1; a--)
{
module.setDisplayToDecNumber(a,0,false);
module.setDisplayToString(number2);

   delay(1000);
}
digitalWrite(2,LOW);
delay(300);
digitalWrite(2,HIGH);
delay(300);
digitalWrite(2,LOW);
delay(300);
digitalWrite(2,HIGH);
}
}

//BOBBY VIDEO GAMES
