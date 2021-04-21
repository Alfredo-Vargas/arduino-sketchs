#include <LiquidCrystal_I2C.h>
#include "chars.h"
#define DELAY 1000

LiquidCrystal_I2C lcd(0x27,16,2);

String loading_number;
String blank_line = "                ";     // string of 16 spaces
byte number = 0, counter1 = 4, counter2 = 1;

void setup() {
  lcd.init();       
  lcd.clear();         
  lcd.backlight();
  for (int i = 0; i < 4; i++){
    lcd.createChar(i + 3, loading_bar[i]);  // we create the chars for the growing bar effect
  }
  for (int i = 0; i < 3; i++)               // we create the chars for the bar frame
    lcd.createChar(i, bar_frame[i]);
  for (int i = 0; i < 16; i++){             // we print the bar frame in the LCD once
    lcd.setCursor(i, 1);
    if (i == 0) {lcd.write(byte(0));}
    else if (i == 15) {lcd.write(byte(2));}
    else
      lcd.write(byte(1));
  } // end of the LCD frame printed
  lcd.setCursor(0,0);
  lcd.print("loading 0%");
}

void deleteCarriageReturn(byte line){       // deletes a line and puts back the cursor at the beginning
  lcd.setCursor(0, line);
  lcd.print(blank_line);
  lcd.setCursor(0, line);
}

void printPercentage(byte number){        // this function prints the percentage of given number in the first line of the LCD
  loading_number = "loading ";
  loading_number += String(number);
  loading_number += "%";
  deleteCarriageReturn(0);
  lcd.setCursor(0,0);
  lcd.print(loading_number);
}


void loop() {
  while (number < 100){
    delay(DELAY);
    switch(number){
      case 0: {
        number += 6;
        lcd.setCursor(0, 1);
        lcd.write(byte(3));
        break;
        }
      case 90: {
        number += 10;
        lcd.setCursor(15, 1);
        lcd.write(byte(6));
        break;
      }
      default: {
        number += 3;
        lcd.setCursor(counter2, 1);
        lcd.write(byte(counter1));
        if ((counter1 % 2) == 1)    // every two iterations we shift the position of the printing of the cell
          counter2++; 
        counter1++;
        if (counter1 == 6)          // to cycle between the two values of loading_bar which makes the effect
          counter1 = 4;
      }
    }
    printPercentage(number);
  }
  lcd.setCursor(0,0);
  lcd.print("loading complete");
  delay(10 * DELAY);    
}
