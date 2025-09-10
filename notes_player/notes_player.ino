int buzzerPin=2;

/*
octave->{flat},{sharp}->{c,d,e,f,g,a,b},{c#,d#,0,f#,g#,a#,0}
*/

static int notes[6][2][7]={
  {{32,36,41,43,48,55,61},{34,38,0,46,51,58,0}},
  {{65,73,82,87,97,110,123},{69,77,0,92,103,116,0}},
  {{130,146,164,174,195,220,246},{138,155,0,184,207,233,0}},
  {{261,293,329,349,391,440,493},{277,311,0,369,415,466,0}},
  {{523,587,659,698,783,880,987},{554,622,0,739,830,932,0}},
  {{1046,1174,1318,1396,1567,1760,1975},{1108,1244,0,1479,1661,1864,0}}
};

String currentNote;

int getNote(int octave,char note){
  if(octave<=0 || octave>=6){
    return -1;
  }

  int isSharp=0;
  if(isUpperCase(note)){
    isSharp=1;
    note+=32;
  }
  int noteIndex;

  switch(note){
    case 'c':
      noteIndex=0;
      break;
    case 'd':
      noteIndex=1;
      break;
    case 'e':
      noteIndex=2;
      break;
    case 'f':
      noteIndex=3;
      break;
    case 'g':
      noteIndex=4;
      break;
    case 'a':
      noteIndex=5;
      break;
    case 'b':
      noteIndex=6;
      break;
    case ' ':
      return 0;
    default:
      return -1;
  }
  return notes[octave][isSharp][noteIndex];
}

void TestNotes(){
  char noteSymbols[]={'c','C','d','D','e','f','F','g','G','a','A','b'};
  for(int i=0;i<6;i++){
    for(int j=0;j<12;j++){
      tone(buzzerPin,getNote(i,noteSymbols[j]));
      delay(1000);
      noTone(buzzerPin);
    }
    delay(10000);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzerPin,OUTPUT);
}

void loop() {
  Serial.println("READY");
  if(Serial.available()){
    currentNote=Serial.readStringUntil('\n');
    currentNote.trim();
    int freq=getNote(currentNote[0]-48,currentNote[1]);
    if(freq!=-1 && currentNote.length()==2){
      if(freq){
        tone(buzzerPin,freq);
      }
    }
    else{
      noTone(buzzerPin);
    }
    Serial.println(currentNote);
    delay(90);
  }
}
