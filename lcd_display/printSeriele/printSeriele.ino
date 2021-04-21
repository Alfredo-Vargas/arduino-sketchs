#include <LiquidCrystal_I2C.h>
#define L 16   // horizontal length of display

LiquidCrystal_I2C lcd(0x27,16,2);

String string;                              // full string read from Serial Monitor
String blank_line = "                ";     // string of 16 spaces
String string1 = blank_line;
String string2 = blank_line;
byte line = 0;                              // LCD line

void setup() {
  Serial.begin(9600);
  lcd.init();                               // initialize LCD 
  lcd.clear();                              // clears the whole LCD display
  lcd.backlight();                          // activates the backlight
  lcd.setCursor(0, line);                   // put cursor at the beginning
}
void deleteCarriageReturn(byte line){       // deletes a line and puts back the cursor at the beginning
  lcd.setCursor(0, line);
  lcd.print(blank_line);
  lcd.setCursor(0, line);
}

void printFromSerial(String string1, String string2){
  deleteCarriageReturn(0);
  lcd.print(string1);
  deleteCarriageReturn(1);
  lcd.print(string2);
}

/*
FIRST CASE:   both lines are blank lines
SECOND CASE:  only second line is blank
THIRD CASE:   only third line is blank
*/

void loop() {
  if (Serial.available() > 0){
    string = Serial.readStringUntil('\n');
    if (string2 == blank_line){
      if (string1 == blank_line){         // FIRST CASE
        if (string.length() <= L)
          string1 = string;
        else {
          string1 = string;
          string2 = string.substring(L);
        }
      } // end second if
      else {                              // SECOND CASE
        if (string.length() <= L)
          string2 = string;
        else {
          string1 = string;
          string2 = string.substring(16);
        }
      } // end second else
    } // end first if
    else {                                // THIRD CASE
      if (string.length() <= L){
        string1 = string2;
        string2 = string;
      }
      else {
        string1 = string;
        string2 = string.substring(L);
      }
    }
  printFromSerial(string1, string2);
  }
}
