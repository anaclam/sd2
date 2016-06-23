import processing.serial.*;
Serial myPort;
void setup() {
  size(650,600);
  println(Serial.list());
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  
  background(162,162,162);
  fill (255,255,255);
  rect(210, 250, 50, 50,7);//Pinky
  rect(160, 250, 50, 50,7);//Ring
  rect(110, 250, 50, 50,7);//Middle
  rect(60, 250, 50, 50,7);//Index
  rect(10, 250, 50, 50,7);//Thumb
  triangle(610, 350, 550, 300,550,390);//Right
  triangle(390, 350, 450, 390,450,300);//Left
  triangle(500, 440, 450, 390,550,390);//Down
  triangle(500, 250, 450, 300,550,300);//Up
  textSize (15); // The arrow keys text size- 20
  fill (0,0,0); // painting it black.
  text("Pinky", 215, 280); 
  text("Ring", 167, 280);
  text("Middle",110, 280); 
  text("Index", 65, 280);
  text("Thumb", 10, 280);
  text("Right", 555, 350);
  text("Left", 412, 355);
  text("Down", 475, 410);
  text("Up", 490, 280);

}
void keyPressed() {
  switch (keyCode)
  {
   case UP: 
   myPort.write('1');
   println("UP!");
   fill(255,0,0);
   triangle(500, 250, 450, 300,550,300);
   break;
   
   case DOWN:
   myPort.write('2');
   println("DOWN!");
   fill(255,0,0);
   triangle(500, 440, 450, 390,550,390);
   break; 
   
   case LEFT:
   myPort.write('3');
   println("LEFT!");
   fill(255,0,0);
   triangle(390, 350, 450, 390,450,300);
   break;
   
   case RIGHT:
   myPort.write('4');
   println("RIGHT!");
   fill(255,0,0);
   triangle(610, 350, 550, 300,550,390);
   break;
   
   case 'Q':
   myPort.write('5');
   println("Thumb!");
   fill(255,0,0);
   rect(10, 250, 50, 50,7);
   break;
   
   case 'W':
   myPort.write('6');
   println("Index finger!");
   fill(255,0,0);
   rect(60, 250, 50, 50,7);
   break;
   
   case 'E':
   myPort.write('7');
   println("Middle finger!");
   fill(255,0,0);
   rect(110, 250, 50, 50,7);
   break;
   
   case 'R':
   myPort.write('8');
   println("Ring finger!");
   fill(255,0,0);
   rect(160, 250, 50, 50,7);
   break;
   
   case 'T':
   myPort.write('9');
   println("Pinky finger!");
   fill(255,0,0);
   rect(210, 250, 50, 50,7);
   break;
   
   case '0':
   myPort.write('0');
   break;
   default:
   break;
  } 
}