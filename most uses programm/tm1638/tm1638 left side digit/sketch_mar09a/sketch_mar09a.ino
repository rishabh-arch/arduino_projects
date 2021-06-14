#include <TM1638.h>

TM1638 module(3, 4, 5);
int x = 123;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  x=x+2;
String number2 = String(x,DEC);
Serial.println(number2);
module.setDisplayToString(number2);
delay(1000);
  // put your main code here, to run repeatedly:

}
