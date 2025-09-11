int greenPin=2;
int redPin=3;
int photoResPin=A0;
int lightVal=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(photoResPin,INPUT);
}

void loop() {
  lightVal=analogRead(photoResPin);
  Serial.println(lightVal);
  if(lightVal>200){
    digitalWrite(greenPin,HIGH);
    digitalWrite(redPin,LOW);
  }
  else{
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
  }
}
