#define ARRAY_SIZE 4
#define DELAY 1000
//#define PATTERN1
#define PATTERN2

const byte pinValue[ARRAY_SIZE] = {8, 9 , 10 , 11}; //pin assignment
/*  byte:    _ _  _ _      _ _  _ _
 *          LED4  LED3     LED2 LED1
 */

#ifdef PATTERN1
byte pattern = 192;
/*  A cycle with pattern = 192 and RightRotation will produce the following sequence in binary: 
 *   1100 0000 -> 0011 0000 -> 0000 1100 -> 0000 0011 --> ...
 *  and in decimal:
 *  192 --> 48 --> 12 --> 3 --> ... */
#endif

#ifdef PATTERN2
byte pattern = 15;
/*  A cycle with pattern = 15 and LeftRotation will produce the following sequence in binary: 
 *  0000 1111 -> 0011 1100 --> 1111 0000 -->  1100 0011 -> ...
 *  and in decimal:
 *  15 --> 60 --> 240 --> 195 --> ...*/   
#endif
    
const byte D = 2, mask = 1;   // rotations are in step of 2 (8 bits / 4 steps) and the mask is 1 (HIGH or LOW)
     
void setup(){
  for (int i = 0; i < ARRAY_SIZE; i++)
    pinMode(pinValue[i], OUTPUT);
}

byte RightRotate(byte number, const byte d){    // d is the displacement of the rotation
  return ((number>>d) | (number << (8 * sizeof(number) - d)));
}

byte LeftRotate(byte number, const byte d){    // d is the displacement of the rotation
  return ((number<<d) | (number >> (8 * sizeof(number) - d)));
}

void writeToMotor(byte pattern){
  for (int i = 0; i < ARRAY_SIZE; i++){
    byte shifted_pattern = RightRotate(pattern, 2 * i);     
    digitalWrite(pinValue[i], shifted_pattern & mask); 
  }
}

void loop(){
  writeToMotor(pattern);
  delay(DELAY);
  #ifdef PATTERN1
  pattern = RightRotate(pattern, D);
  #endif
  #ifdef PATTERN2
  pattern = LeftRotate(pattern, D);
  #endif
}
