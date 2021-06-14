//RFID
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <TM1638.h>
#include <EEPROM.h>
 
#define SS_PIN 10
#define RST_PIN 9
#define LED_G 4 //define green LED pin
#define LED_R 5 //define red LED
#define BUZZER 2 //buzzer pin
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Servo myServo; //define servo name
 TM1638 module(3, 4, 5);
int a,x=0,z=10;
uint8_t EEPROMaddress = 130;
void setup() 
{
  pinMode(2,OUTPUT);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  myServo.attach(3); //servo pin
  myServo.write(0); //servo start position
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  Serial.println("Put your card to the reader...");
  Serial.println();
}
void loop() 
{
  
  byte key1;
  // read the buttons from the first module
  key1 = module.getButtons();
  if(key1==1){
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
module.setDisplayToString("0");
  }
  
if(key1==4){
z = z+1;
module.setDisplayToDecNumber(z,0,false);
delay(300);
}
if(key1==8){
z=z-1;
module.setDisplayToDecNumber(z,0,false);
delay(300);
}

x = EEPROM.read(EEPROMaddress);
EEPROM.write(EEPROMaddress,x);
 String number2 = String(x,DEC);
Serial.println(number2);
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
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.println(content);
  String content2=content.substring(1);
  Serial.println(content2);
  delay(1000);
  

if(content2=="b0 51 6b 2a"){

 x=x+1;
 EEPROM.write(EEPROMaddress,x);
String number2 = String(x,DEC);
Serial.println(number2);
module.setDisplayToString(number2);

for (a=z; a>=1; a--)
{
    digitalWrite(2, HIGH);
module.setDisplayToDecNumber(a,0,false);
module.setDisplayToString(number2);
delay(1000);
key1 = module.getButtons();
if(key1==32){
  break; }
}
}



  
digitalWrite(2, LOW);
}
