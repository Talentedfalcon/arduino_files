#include <Stepper.h>

int stepsPerRev=2048;
int motSpeed=10;
int stepDir=1;
Stepper myStepper(stepsPerRev,8,10,9,11);

int buttonPin=2;

int buttonValNew;
int buttonValOld;

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);
  pinMode(buttonPin,INPUT);
}

void loop() {
  myStepper.step(stepDir);
  
  buttonValNew=digitalRead(buttonPin);
  if(buttonValNew==LOW && buttonValOld==HIGH){
    stepDir=-stepDir;
  }
  buttonValOld=buttonValNew;
}
