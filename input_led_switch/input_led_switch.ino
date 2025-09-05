int redLED=2;
int yellowLED=3;
int greenLED=4;

int redVal=0;
int yellowVal=0;
int greenVal=0;

String select;

void setup() {
  Serial.begin(9600);
  pinMode(redLED,OUTPUT);
  pinMode(yellowLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
}

void loop() {
  if(Serial.available()){
    select=Serial.readString();
    Serial.print(select);
    if(select=="red\n"){
      redVal=!redVal;
    }
    else if(select=="yellow\n"){
      yellowVal=!yellowVal;
    }
    else if(select=="green\n"){
      greenVal=!greenVal;
    }
    else if(select=="all\n"){
      redVal=1;
      yellowVal=1;
      greenVal=1;
    }
    else if(select=="clear\n"){
      redVal=0;
      yellowVal=0;
      greenVal=0;
    }
  }
  digitalWrite(redLED,redVal);
  digitalWrite(yellowLED,yellowVal);
  digitalWrite(greenLED,greenVal);
}
