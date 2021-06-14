#include <TM1638.h>
// define a module on data pin 8, clock pin 9 and strobe pin 10
TM1638 module(8, 9, 7);
unsigned long a=1,a2=1,a3=100;
byte key1,key2,key3,key4;
  // read the buttons from the first module

void setup()
{
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
module.setDisplayToDecNumber(a3,0,0);
}
void loop()
{
   key2 = module.getButtons(); 
   
   if(key2==8){
    a3 = a3+5;
    module.setDisplayToDecNumber(a3,0,0);
    delay(300);
    }
    else if(key2==16){
      a3 = a3-5;
      module.setDisplayToDecNumber(a3,0,0);
      delay(300);
      }
   if(key2==1){
    digitalWrite(10, LOW);
for (a=a3; a>=1; a--)
{
module.setDisplayToDecNumber(a,0,0);
delay(100);
  key1 = module.getButtons(); 
  if(key1==2){
    digitalWrite(10, HIGH);
 break;
  } 
}
digitalWrite(10, HIGH);
   }
    key3 = module.getButtons(); 
   if(key3==4){
    digitalWrite(10, LOW);
for (a2=a; a2>=1; a2--)
{
module.setDisplayToDecNumber(a2,0,0);
delay(100);
  key4 = module.getButtons(); 
  if(key4==2){
    a = a2;
    digitalWrite(10, HIGH);
 break;
 
  } 
}
digitalWrite(10, HIGH);
   }
}
