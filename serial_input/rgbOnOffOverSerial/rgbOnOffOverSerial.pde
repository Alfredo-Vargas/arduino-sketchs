import processing.serial.*;

//select serial port:
int keuze_seriele_poort = 1;

Serial myPort;  
int val = 0;  
boolean overButtonR = false;
boolean overButtonG = false;
boolean overButtonB = false;
boolean overButtonC = false;
boolean overButtonY = false;
boolean overButtonM = false;
boolean overButtonW = false;
boolean overButtonRoff = false;
boolean overButtonGoff = false;
boolean overButtonBoff = false;
boolean overButtonCoff = false;
boolean overButtonYoff = false;
boolean overButtonMoff = false;
boolean overButtonWoff = false;

void setup() {
  size(430 , 150);
  //start serial port selection
  val = Serial.list().length;
  if(val == 0){
    println("Error: no serial port found!");
    exit();
    return;
  }else if(keuze_seriele_poort >= val){
    println("Error: wrong serial port selected!");
    exit();
    return;
  }else if(val > 1){
    println("Warning! More than 1 serial port found:");
    for(int i = 0; i < val; i++){
      print(i);
      print(": ");
      println(Serial.list()[i]);
    }
  }
  print("Serial port ");
  print(keuze_seriele_poort);
  print(" selected: ");
  println(Serial.list()[keuze_seriele_poort]);
  //Open port at 9600 baud rate
  myPort = new Serial(this, Serial.list()[keuze_seriele_poort], 9600);
  
  textAlign(CENTER);
  background(200);
  
  fill(255,0,0);
  rect(10,10,50,50); //red
  fill(0,255,0);
  rect(70,10,50,50); //green
  fill(0,0,255);
  rect(130,10,50,50); //blue
  fill(0,255,255);
  rect(190,10,50,50); //cyan
  fill(255,255,0);
  rect(250,10,50,50); //yellow
  fill(255,0,255);
  rect(310,10,50,50); //magenta
  fill(255,255,255);
  rect(370,10,50,50); //magenta
  
  fill(0);
  stroke(255, 0, 0);
  rect(10,70,50,50); //red
  stroke(0,255,0);
  rect(70,70,50,50); //green
  stroke(0,0,255);
  rect(130,70,50,50); //blue
  stroke(0, 255, 255);
  rect(190,70,50,50); //cyan
  stroke(255, 255, 0);
  rect(250,70,50,50); //yellow
  stroke(255, 0, 255);
  rect(310,70,50,50); //magenta
  stroke(255, 255, 255);
  rect(370,70,50,50); //magenta
} 

void mousePressed() {
  if (overButtonR)
    myPort.write("r=1\n");
  if (overButtonG)
    myPort.write("g=1\n");
  if (overButtonB)
    myPort.write("b=1\n");    
  if (overButtonRoff)
    myPort.write("r=0\n");
  if (overButtonGoff) 
    myPort.write("g=0\n");
  if (overButtonBoff)
    myPort.write("b=0\n");
  if (overButtonC)
    myPort.write("c=1\n");
  if (overButtonY)
    myPort.write("y=1\n");
  if (overButtonM)
    myPort.write("m=1\n");    
  if (overButtonCoff)
    myPort.write("c=0\n");
  if (overButtonYoff) 
    myPort.write("y=0\n");
  if (overButtonMoff)
    myPort.write("m=0\n");    
  if (overButtonW)
    myPort.write("w=1\n");
  if (overButtonWoff)
    myPort.write("w=0\n"); 
}

void draw() {

}

void mouseMoved() { 
  checkButtons(); 
}
  
void mouseDragged() {
  checkButtons(); 
}

void checkButtons() {
  print(mouseX);
  print(" ");
  println(mouseY);

  if (mouseX > 10 && mouseX < 60 && mouseY > 10 && mouseY < 60) {
    overButtonR = true;   
    text("  Rood aan  ",95,140);
  } else {
    overButtonR = false;
  }
  if (mouseX > 70 && mouseX < 120 && mouseY > 10 && mouseY < 60) {
    overButtonG = true;   
    text("  Groen aan  ",95,140);
  } else {
    overButtonG = false;
  }
  if (mouseX > 130 && mouseX < 180 && mouseY > 10 && mouseY < 60) {
    overButtonB = true;   
    text("  Blauw aan  ",95,140);
  } else {
    overButtonB = false;
  }
  
  if (mouseX > 10 && mouseX < 60 && mouseY > 70 && mouseY < 120) {
    overButtonRoff = true;   
    text("  Rood uit  ",95,140);
  } else {
    overButtonRoff = false;
  }
  if (mouseX > 70 && mouseX < 120 && mouseY > 70 && mouseY < 120) {
    overButtonGoff = true;   
    text("  Groen uit  ",95,140);
  } else {
    overButtonGoff = false;
  }
  if (mouseX > 130 && mouseX < 180 && mouseY > 70 && mouseY < 120) {
    overButtonBoff = true;   
    text("  Blauw uit  ",95,140);
  } else {
    overButtonBoff = false;
  }
  /*CYM W*/
  if (mouseX > 190 && mouseX < 240 && mouseY > 10 && mouseY < 60) {
    overButtonC = true;   
    text("  Cyan aan  ",95,140);
  } else {
    overButtonC = false;
  }
  if (mouseX > 250 && mouseX < 300 && mouseY > 10 && mouseY < 60) {
    overButtonY = true;   
    text("  Yellow aan  ",95,140);
  } else {
    overButtonY = false;
  }
  if (mouseX > 310 && mouseX < 360 && mouseY > 10 && mouseY < 60) {
    overButtonM = true;   
    text("  Magenta aan  ",95,140);
  } else {
    overButtonM = false;
  }
  if (mouseX > 370 && mouseX < 420 && mouseY > 10 && mouseY < 60) {
    overButtonW = true;   
    text("  White aan  ",95,140);
  } else {
    overButtonW = false;
  }
  
  if (mouseX > 190 && mouseX < 240 && mouseY > 70 && mouseY < 120) {
    overButtonCoff = true;   
    text("  Cyan uit  ",95,140);
  } else {
    overButtonCoff = false;
  }
  if (mouseX > 250 && mouseX < 300 && mouseY > 70 && mouseY < 120) {
    overButtonYoff = true;   
    text("  Yellow uit  ",95,140);
  } else {
    overButtonYoff = false;
  }
  if (mouseX > 310 && mouseX < 360 && mouseY > 70 && mouseY < 120) {
    overButtonMoff = true;   
    text("  Magenta uit  ",95,140);
  } else {
    overButtonMoff = false;
  }
  if (mouseX > 370 && mouseX < 420 && mouseY > 70 && mouseY < 120) {
    overButtonWoff = true;   
    text("  White uit  ",95,140);
  } else {
    overButtonWoff = false;
  }
  
  if(!(overButtonR || overButtonG || overButtonB || overButtonRoff || overButtonGoff || overButtonBoff || overButtonC || overButtonCoff || overButtonY || overButtonYoff || overButtonM || overButtonMoff || overButtonW || overButtonWoff)){
    fill(200);
    noStroke();
    rect(60,130,70,20);
    stroke(0);
    fill(0);
  }
}
