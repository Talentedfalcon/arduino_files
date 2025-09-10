### Brief:
- Uses a passive buzzer along with the `tone()` function in arduino to play a sheet 

### Circuit Diagram:
- 

### Usage:
- Copy a music sheet _(only sheets which don't have RH/LH)_ from [Piano Letter Notes](https://pianoletternotes.blogspot.com/) into ___sheet.txt___
- Run ___sheet-to-program-mod.py___
- Now ensure that the Arduino is connected and run ___notes_input.py___

### Notes-Frequency(Hz) Map:
```ino
/*
{octave}->{{flat},{sharp}}->{{c,d,e,f,g,a,b},{c#,d#,0,f#,g#,a#,0}}
*/

static int notes[6][2][7]={
  {{32,36,41,43,48,55,61},{34,38,0,46,51,58,0}},
  {{65,73,82,87,97,110,123},{69,77,0,92,103,116,0}},
  {{130,146,164,174,195,220,246},{138,155,0,184,207,233,0}},
  {{261,293,329,349,391,440,493},{277,311,0,369,415,466,0}},
  {{523,587,659,698,783,880,987},{554,622,0,739,830,932,0}},
  {{1046,1174,1318,1396,1567,1760,1975},{1108,1244,0,1479,1661,1864,0}}
};
```

##### Current sheet - Bad Apple (Teppei Okada)