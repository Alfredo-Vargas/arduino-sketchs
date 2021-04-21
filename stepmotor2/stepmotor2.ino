#define ARRAY_SIZE 4
#define DELAY 10
#define BIG_DELAY 5000

const byte pinValue[ARRAY_SIZE] = {8, 9 , 10 , 11}; //pin assignment 
/*  byte:    _ _  _ _      _ _  _ _
 *          LED4  LED3     LED2 LED1
 */
byte pattern1 = 3, pattern2 = 15;
/*  binary cycle pattern1 = 3 with left rotation
 *  0000 0011 --> 0000 1100 --> 0011 0000 --> 1100 0000 (dec. seq. 3, 12, 48, 192)
 *  binary cycle pattern2 = 15 with left rotation
 *  0000 1111 -> 0011 1100 --> 1111 0000 -->  1100 0011 (dec. seq. 15, 60, 240, 195)
 */
byte state = 0;     // state 0 is clockwise rotation, state 1 is counter-clockwise rotation
int step_counter = 0;
const byte D = 2, mask = 1;     // D is the displacement of the rotation   

void setup(){
  for (int i = 0; i < ARRAY_SIZE; i++)
    pinMode(pinValue[i], OUTPUT);
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
  if (step_counter == 1024) // number of steps to reach a 90 degrees rotation
  {
    state = !state;         //change direction of rotation
    step_counter = 0;       //restart step counter
    delay(BIG_DELAY);
  }
  else
  {
      writeToMotor(pattern1);
      delay(DELAY);
      writeToMotor(pattern2);
      delay(DELAY); 
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
  }
  step_counter += 2;
}
