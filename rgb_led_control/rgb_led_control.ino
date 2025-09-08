int redPin=3;
int greenPin=5;
int bluePin=6;

int redVal=0;
int greenVal=0;
int blueVal=0;
int increment=5;

String selection;

void setup() {
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void getNumbers(String selection){
  int vals[3];
  int start_index=0;
  int end_index=0;
  int j=0;

  while(j<3){
    end_index=selection.indexOf(' ',end_index+1);
    vals[j]=selection.substring(start_index,end_index).toInt();
    if(vals[j]>255){
      vals[j]=255;
    }
    if(vals[j]<0){
      vals[j]=0;
    }
    j++;
    start_index=end_index+1;
  }
  redVal=vals[0];
  greenVal=vals[1];
  blueVal=vals[2];
}

void loop() {
  if(Serial.available()){
    selection=Serial.readString();
  }
  if(selection=="cycle\n"){
    if(redVal>=0 && redVal<255){
      redVal+=increment;
    }
    else{
      if(greenVal>=0 && greenVal<255){
        greenVal+=increment;
      }
      else{
        if(blueVal>=0 && blueVal<255){
          blueVal+=increment;
        }
        else{
          increment=-increment;
          redVal+=increment;
          greenVal+=increment;
          blueVal+=increment;
        }
      }
    }
  }
  else if(selection=="zero\n" || selection=="clear\n"){
    redVal=0;
    greenVal=0;
    blueVal=0;
  }
  else{
    getNumbers(selection);
  }

  // Serial.print(selection);
  // Serial.print(redVal);
  // Serial.print(", ");
  // Serial.print(greenVal);
  // Serial.print(", ");
  // Serial.println(blueVal);
  analogWrite(redPin,redVal);
  analogWrite(greenPin,greenVal);
  analogWrite(bluePin,blueVal);
  delay(50);
}
