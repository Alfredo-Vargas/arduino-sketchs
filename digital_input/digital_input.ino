/*
 * Digital input
 * Input attached to pin 2 Led on pin 13
 * door: 
 */

#define LED 13
#define BUTTON 2
#define BOUNCETIME 20

unsigned char reading, state = LOW, previous = LOW;
long int time = 0;
 
void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  reading = digitalRead(BUTTON);
  // Condition that tests 3 things:
  // (I)  If someone has pressed the button
  // (II) If the previous reading was LOW (meaning at least two loops passed - trap activated!)
  // (III)If enough time has passed to discard the bouncing time of the switch
  if (reading == HIGH && previous == LOW)// && millis() - time > BOUNCETIME)
  {
    if (state == HIGH)
      state = LOW;
    else
      state = HIGH;
    time = millis();
  }
  digitalWrite(LED, state);
  previous = reading;
}
