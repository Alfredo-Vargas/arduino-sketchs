#include <LiquidCrystal_I2C.h>
#include "chars.h"

byte line;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();       
  lcd.clear();         
  lcd.backlight();
  for (int i = 0; i < 6; i++)
    lcd.createChar(i, thumbsup[i]);
}

void loop() {
  for (int i = 0; i < 6; i++){
    line = i < 3 ? 0 : 1;
    lcd.setCursor(i - line * 3, line);
    lcd.write(byte(i));
  }
}
