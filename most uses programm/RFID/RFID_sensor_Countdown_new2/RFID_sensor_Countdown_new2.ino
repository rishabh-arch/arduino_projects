//RFID
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <TM1638.h>
#include <EEPROM.h>
 
#define SS_PIN 53
#define RST_PIN 49
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 TM1638 module(3, 4, 5);
int a,x=0,z=2;
uint8_t EEPROMaddress = 130;

void setup() 
{
  pinMode(2,OUTPUT);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
}
void loop() 
{   
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
  Serial.println(content2);

if(content2=="b0 51 6b 2a" || "d9 d1 91 d5"){
 x=x+1;
 if(x>5){
x=1;
  }
  
 EEPROM.write(EEPROMaddress,x);
String number2 = String(x,DEC);
module.setDisplayToString(number2);

for (a=z; a>=1; a--)
{
    digitalWrite(2, HIGH);
module.setDisplayToDecNumber(a,0,false);
module.setDisplayToString(number2);
delay(1000);
 
digitalWrite(2, LOW);
}
}
}
