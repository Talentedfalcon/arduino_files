#include <Servo.h>

#define VRX_Pin A0
#define VRY_Pin A1

Servo servox1;
Servo servox2;
Servo servoy1;
Servo servoy2;

int pos[4]={90,90,90,90};

int x_offset=0;
int y_offset=0;

void setup() {
  Serial.begin(9600);
  servox1.attach(6);
  servox2.attach(9);
  servoy1.attach(10);
  servoy2.attach(11);

  x_offset=analogRead(VRX_Pin);
  y_offset=analogRead(VRY_Pin);

  servox1.write(pos[0]);
  servox2.write(pos[1]);
  servoy1.write(pos[2]);
  servoy2.write(pos[3]);
  delay(15);
}

int x_val=0;
int y_val=0;

void loop() {
  x_val=analogRead(VRX_Pin)-x_offset;
  y_val=analogRead(VRY_Pin)-y_offset;

  Serial.print(x_val);
  Serial.print(", ");
  Serial.print(y_val);
  Serial.println();

  if(x_val>300){
    pos[0]=min(pos[0]+1,180);
    pos[1]=max(pos[1]-1,0);
  }
  if(x_val<-300){
    pos[0]=max(pos[0]-1,0);
    pos[1]=min(pos[1]+1,180);
  }

  if(y_val>300){
    pos[2]=min(pos[2]+1,180);
    pos[3]=max(pos[3]-1,0);
  }
  if(y_val<-300){
    pos[2]=max(pos[2]-1,0);
    pos[3]=min(pos[3]+1,180);
  }
  servox1.write(pos[0]);
  servox2.write(pos[1]);
  servoy1.write(pos[2]);
  servoy2.write(pos[3]);
  
  delay(15);
}