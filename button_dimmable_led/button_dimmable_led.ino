int buttonPinDown=2;
int buttonPinUp=3;
int LEDPin=5;

int decrease=LOW;
int increase=LOW;
int LEDVal=0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPinDown,INPUT);
  pinMode(buttonPinUp,INPUT);
  pinMode(LEDPin,OUTPUT);
}

void loop() {
  if(digitalRead(buttonPinDown)){
    if(LEDVal>=5){
      LEDVal-=5;
    }
  }
  else if(digitalRead(buttonPinUp)){
    if(LEDVal<255){
      LEDVal+=5;
    }
  }
  analogWrite(LEDPin,LEDVal);
  Serial.println(LEDVal);
  delay(100);
}
