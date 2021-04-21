#define BLUE_LED 13
#define GREEN_LED 12
#define RED_LED 11

void setup() {
  //pin set-up
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  //Baud rate set-up
  Serial.begin(9600);
  //Optional Serial timeout
}
unsigned char input, state;
void loop() {
  //see exercise
  while(Serial.available() > 0)
  {
    input = Serial.read();
    state = Serial.parseInt();
  }
  switch(input)
  {
    case 'r': 
    {
      digitalWrite(RED_LED, state);
      break;
    }
    case 'g': 
    {
      digitalWrite(GREEN_LED, state);
      break;
    }
    case 'b': 
    {
      digitalWrite(BLUE_LED, state);
      break;
    }
  }
}
