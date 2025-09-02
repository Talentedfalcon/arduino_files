int potPin=A1;
int potVal=0;
int LEDPin=3;
int LEDVal=0;

void setup(){
  Serial.begin(9600);
  pinMode(potPin,INPUT);
  pinMode(LEDPin,OUTPUT);
}

void loop(){
  potVal=analogRead(potPin);
  LEDVal=(255.0/1023.0)*potVal;
  analogWrite(LEDPin,LEDVal);
  Serial.println(potVal);
}