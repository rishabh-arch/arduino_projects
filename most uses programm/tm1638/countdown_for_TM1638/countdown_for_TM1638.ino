
#include <TM1638.h>
#include <EEPROM.h>
// define a module on data pin 8, clock pin 9 and strobe pin 10
TM1638 module(3, 4, 5);
unsigned long a=10;
uint8_t EEPROMaddress = 130;

void setup()
{

}
void loop()
{
for (a=EEPROM.read(EEPROMaddress); a>=1; a--)
{
    
module.setDisplayToDecNumber(a,0,false);

 EEPROM.write(EEPROMaddress,a);
delay(1000);

}
module.setDisplayToString("       0");
delay(1000);
a = 10;
 EEPROM.write(EEPROMaddress,a);
}
