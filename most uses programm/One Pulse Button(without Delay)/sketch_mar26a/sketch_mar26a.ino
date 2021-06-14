
int a = 0;
int sensor = 2;
int sen=1;
int buttonState1 = 0;
void setup() {
        pinMode(sensor, INPUT);
   Serial.begin(9600);
}

void loop() {
  
  buttonState1 = digitalRead(sensor);
 
  while(buttonState1== HIGH && sen ==1){
    Serial.println(a);
 sen=2;
    }
while(buttonState1== LOW && sen ==2){
    a=a+1;
     sen=1;
    break;
   
      }
  
  
}
