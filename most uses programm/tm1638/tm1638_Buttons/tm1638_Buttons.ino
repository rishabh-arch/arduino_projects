
#include "TM1638.h"
// define the first module
TM1638 module1(8, 9, 7);
void setup()
{
Serial.begin(9600);
}
void loop()
{
  byte key1;
  // read the buttons from the first module
  key1 = module1.getButtons();
  if(key1!=0){
  Serial.println(key1);
  delay(300);
  }
}
