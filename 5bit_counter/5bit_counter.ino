int num_leds=5;

int pins[5]={2,3,4,5,6};
int output[5]={0,0,0,0,0};

void setup() {
  Serial.begin(9600);
  pinMode(pins[0],OUTPUT);
  pinMode(pins[1],OUTPUT);
  pinMode(pins[2],OUTPUT);
  pinMode(pins[3],OUTPUT);
  pinMode(pins[4],OUTPUT);
}

void translate_irl(){
  for(int i=0;i<num_leds;i++){
    digitalWrite(pins[i],output[i]);
    Serial.print(output[i]);
  }
  Serial.println("");
  return;
}

void loop() {
  output[0]+=1;
  for(int i=0;i<num_leds;i++){
    if(output[i]>1){
      output[i]=0;
      if(i+1<num_leds){
        output[i+1]+=1;
      }
    }
  }
  translate_irl();
  delay(500);
  // if(output[4]==0){
  //   output[4]=1;
  // }
  // else{
  //   if(output[3]==0){
  //     output[3]=1;
  //     output[4]=0;
  //   }
  //   else{
  //     if(output[2]==0){
  //       output[2]=1;
  //       output[3]=0;
  //       output[4]=0;
  //     }
  //     else{
  //       if(output[1]==0){
  //         output[1]=1;
  //         output[2]=0;
  //         output[3]=0;
  //         output[4]=0;
  //       }
  //       else{
  //         if(output[0]==0){
  //           output[0]=1;
  //           output[1]=0;
  //           output[2]=0;
  //           output[3]=0;
  //           output[4]=0;
  //         }
  //         else{
  //           output[0]=0;
  //           output[1]=0;
  //           output[2]=0;
  //           output[3]=0;
  //           output[4]=0;
  //         }
  //       }
  //     }
  //   }
  // }
}
