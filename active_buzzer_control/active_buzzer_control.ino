int buzzerPin=2;
int potPin=A0;
int potVal=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(potPin,INPUT);
  pinMode(buzzerPin,OUTPUT);
}

void playBuzzer(){
  for(int i=0;i<100;i++){
    int delayT=(rand()%30);
    digitalWrite(buzzerPin,HIGH);
    delay(delayT);
    digitalWrite(buzzerPin,LOW);
    delay(delayT);
  }
}

void loop() {
  potVal=analogRead(potPin);
  if(potVal>800){
    playBuzzer();
  }
  Serial.println(potVal);
}
