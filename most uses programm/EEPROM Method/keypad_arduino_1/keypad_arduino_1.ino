#include <EEPROM.h>

long int a,x=0,z=300;
uint8_t EEPROMaddress = 130;

void setup() 
{
}
void loop() 
{   
 //method for clear EEPROM
   for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }

// method for insert old value  
 EEPROM.write(EEPROMaddress,x);
String number2 = String(x,DEC);
module.setDisplayToString(number2);

}
