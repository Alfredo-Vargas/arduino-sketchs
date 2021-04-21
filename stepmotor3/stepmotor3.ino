#define ARRAY_SIZE 4
#define DELAY 1000

const byte pinValue[ARRAY_SIZE] = {8, 9 , 10 , 11}; //pin assignment 
/*  byte:    _ _  _ _      _ _  _ _
 *          LED4  LED3     LED2 LED1
 */
byte pattern1 = 3, pattern2 = 15;

byte state = 0;     // state 0 is clockwise rotation, state 1 is counter-clockwise rotation
int step_counter = 0;
const byte D = 2, mask = 1;     // D is the displacement of the rotation
String raw_steps;  
short int steps;  // number of steps to be rotated (-4096 to 4096) equivalent to (-360 to 360) degrees

void setup(){
  Serial.begin(9600);
  for (int i = 0; i < ARRAY_SIZE; i++)
    pinMode(pinValue[i], OUTPUT);
  Serial.print(F("Please introduce the number of steps to be performed: "));
}

byte LeftRotate(byte number, const byte d){    
  return ((number<<d) | (number >> (8 * sizeof(number) - d)));
}

byte RightRotate(byte number, const byte d){    
  return ((number>>d) | (number << (8 * sizeof(number) - d)));
}

void writeToMotor(byte pattern){
  for (int i = 0; i < ARRAY_SIZE; i++){
   byte shifted_pattern = RightRotate(pattern, 2 * i); //RightRotate is clockwise
   digitalWrite(pinValue[i], shifted_pattern & mask); 
  }
}

void loop(){
  if (Serial.available() > 0){
    raw_steps = Serial.readStringUntil('\n');
    steps = raw_steps.toInt();
    state = steps >= 0 ? 0 : 1;
    step_counter = 0;
    Serial.println();
  }   

  if (state == 0)
  {   
    pattern1 = LeftRotate(pattern1, D);
    pattern2 = LeftRotate(pattern2, D); 
  }
  else
  {   
    pattern1 = RightRotate(pattern1, D);
    pattern2 = RightRotate(pattern2, D);       
  }

  if ((abs(steps) - step_counter) > 0)
  {
    Serial.println(abs(steps) - step_counter);
    writeToMotor(pattern1);
    delay(DELAY);
    writeToMotor(pattern2);
    delay(DELAY);
    step_counter += 2;
  }
}
