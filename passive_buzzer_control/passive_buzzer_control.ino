int buzzerPin=2;
int potPin=A0;
int potVal=0;

int notes[]={277,311,350,370,415,466,523};

void setup() {
  pinMode(potPin,INPUT);
  pinMode(buzzerPin,OUTPUT);
  tone(buzzerPin,500,1000);
}

void loop() {
  potVal=analogRead(potPin);
  int chosenNote=(potVal/1023.)*6;
  
  tone(buzzerPin,notes[chosenNote]);
  delay(500);
}
