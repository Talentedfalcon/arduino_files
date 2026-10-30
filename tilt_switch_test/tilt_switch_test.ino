int yellowPin=4;
int redPin=2;

int tiltPin=7;

void setup() {
  Serial.begin(9600);
  pinMode(yellowPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(tiltPin,INPUT);
  digitalWrite(tiltPin,HIGH);
}

void loop() {
  int isTilt=digitalRead(tiltPin);

  Serial.println(isTilt);
  if(isTilt){
    digitalWrite(redPin,HIGH);
    digitalWrite(yellowPin,LOW);
  }
  else{
    digitalWrite(yellowPin,HIGH);
    digitalWrite(redPin,LOW);
  }

  delay(100);
}