#include <LiquidCrystal_I2C.h>
#define DELAY 4000

LiquidCrystal_I2C lcd(0x27,16,2);

String blank_line = "                ";     // string of 16 spaces

void setup() {
  lcd.init(); //initialize LCD 
  lcd.clear();         
  lcd.backlight(); //schakel backlight in
  lcd.print("Dag Wereld!");
}

void printNum(int number, byte display_size, char given_char){
  String given_string, real_string;
  given_string = String(number);
  int left_size = display_size - given_string.length();
  for (int i = 0; i < left_size; i++)
    real_string += given_char;
  real_string += number;
  lcd.print(real_string);
}

void loop() {
  lcd.setCursor(0, 1); //in het begin van de 2de lijn gaan staan
  printNum(123, 4, '#');
  lcd.print(blank_line);
  delay(DELAY);
}
