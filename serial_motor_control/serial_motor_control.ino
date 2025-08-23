#include <Servo.h>

// #define VRX_Pin A0
// #define VRY_Pin A1

Servo servo1Down;
Servo servo2Up;
Servo servo3Left;
Servo servo4Right;

int pos[2]={0,0};
int threshold[2]={80,60};

int x_offset=0;
int y_offset=0;

String message;

void rotateServo(Servo servo,int target,int time_delay){
  int currentPos=servo.read();
  if (currentPos < target) {
    for (int pos = currentPos; pos <= target; pos++) {
      servo.write(pos);
      delay(time_delay);
    }
  } else {
    for (int pos = currentPos; pos >= target; pos--) {
      servo.write(pos);
      delay(time_delay);
    }
  }
}

void setup() {
  Serial.begin(9600);
  servo1Down.attach(6);
  servo2Up.attach(9);
  servo3Left.attach(10);
  servo4Right.attach(11);

  // rotateServo(servo1Down,0,5);
  // rotateServo(servo2Up,0,5);
  // rotateServo(servo3Left,0,5);
  // rotateServo(servo4Right,0,5);
  servo1Down.write(pos[0]);
  servo2Up.write(pos[0]);
  servo3Left.write(pos[1]);
  servo4Right.write(pos[1]);
  delay(15);
}

void loop() {
  message=Serial.readString();


  if(message[0]=='S'){
    int pos_id=0;
    int value=0;
    int isNegative=0;

    for(int i=1;i<message.length();i++){
      if(isdigit(message[i])){
        if(value!=0){
          value*=10;
        }
        value+=message[i]-'0';
      }
      else if(message[i]=='-'){
        isNegative=1;
      }
      else{
        if(isNegative)
          pos[pos_id]=-min(threshold[pos_id],value);
        else
          pos[pos_id]=min(threshold[pos_id],value);
        pos[pos_id++];

        isNegative=0;
        value=0;
      }
    }
    if(isNegative)
      pos[pos_id]=-min(threshold[pos_id],value);
    else
      pos[pos_id]=min(threshold[pos_id],value);

    Serial.print(pos[0]);
    Serial.print(" ");
    Serial.println(pos[1]);

    // Control up-down motion. Down is +ve
    if(pos[0]>=0){
      if(servo2Up.read()!=0){
        rotateServo(servo2Up,0,5);
      }
      rotateServo(servo1Down,pos[0],5);
    }
    else{
      if(servo1Down.read()!=0){
        rotateServo(servo1Down,0,5);
      }
      rotateServo(servo2Up,-pos[0],5);
    }

    //Control left-right motion. Right is +ve
    if(pos[1]>=0){
      if(servo3Left.read()!=0){
        rotateServo(servo3Left,0,5);
      }
      rotateServo(servo4Right,pos[1],5);
    }
    else{
      if(servo4Right.read()!=0){
        rotateServo(servo4Right,0,5);
      }
      rotateServo(servo3Left,-pos[1],5);
    }

    // servo1Down.write(pos[0]);
    // servo2Up.write(pos[1]);
    // servo3Left.write(pos[2]);
    // servo4Right.write(pos[3]);
  }
}