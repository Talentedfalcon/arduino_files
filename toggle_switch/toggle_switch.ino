int buttonPin=2;
int LEDPin=3;

int buttonValOld=LOW;
int buttonValNew=LOW;
int LEDVal=LOW;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin,INPUT);
  pinMode(LEDPin,OUTPUT);
}

void loop() {
  buttonValNew=digitalRead(buttonPin);
  if(buttonValNew==HIGH && buttonValOld==LOW){
    LEDVal=!LEDVal;
    digitalWrite(LEDPin,LEDVal);
  }
  buttonValOld=buttonValNew;
  Serial.print(buttonValNew);
  Serial.print(",");
  Serial.println(buttonValOld);
  delay(100);
}
