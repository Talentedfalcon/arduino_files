#include <LiquidCrystal_I2C.h>

#define VRX_Pin A0
#define VRY_Pin A1

LiquidCrystal_I2C lcd(0x27,16,2);

byte Character[8] = {
  0b01110, 
  0b11111, 
  0b01110, 
  0b00100, 
  0b11111, 
  0b00100, 
  0b01010, 
  0b10001
};

int x_offset=0;
int y_offset=0;

void setup(){
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.createChar(0,Character);
  lcd.setCursor(0, 0);
  lcd.write(0);


  Serial.begin(9600);

  x_offset=analogRead(VRX_Pin);
  y_offset=analogRead(VRY_Pin);  
}

int i=0;

int x_val=0;
int y_val=0;
int threshold=200;

void loop(){
  x_val=analogRead(VRX_Pin)-x_offset;
  y_val=analogRead(VRY_Pin)-y_offset;

  Serial.print(x_val);
  Serial.print(", ");
  Serial.print(y_val);
  Serial.println();

  if(i<15 && x_val>=threshold){
    lcd.scrollDisplayRight();
    i++;
  }
  else if(i>0 && x_val<=-threshold){
    lcd.scrollDisplayLeft();
    i--;
  }

  if(y_val>=threshold){
    lcd.clear();
    lcd.setCursor(i, 1);
    lcd.write(0);
  }
  else if(y_val<=-threshold){
    lcd.clear();
    lcd.setCursor(i, 0);
    lcd.write(0);
  }

  delay(250);
}