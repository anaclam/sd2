import processing.serial.*;
import controlP5.*;
import java.lang.Float;
import java.lang.StringBuilder;

ControlP5 cp5;
Serial myPort;
public static int thumb;
public static int index, middle,ring,pinky,volt_curr,up,down,left,right;

void setup() {
  //Size of the window
  size(650,600);
  println(Serial.list());
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  //Text Fields
  cp5 = new ControlP5(this);
  cp5.addTextfield("Value").setPosition(20, 100).setSize(200, 40).setAutoClear(false);
  //cp5.addTextfield("Current (mA)").setPosition(20, 170).setSize(200, 40).setAutoClear(false);
  cp5.addBang("Submit").setPosition(300,100).setSize(80, 40);
  
  //Volatge/Current Toggle
  cp5.addToggle("Volt_Curr")
     .setPosition(230,115)
     .setSize(45,20)
     .setValue(true)
     .setMode(ControlP5.SWITCH)
     ; 
  //Finger Toggles
  cp5.addToggle("Thumb")
     .setPosition(40,300)
     .setSize(50,20)
     .setValue(false)
     .setMode(ControlP5.SWITCH)
     ;
  cp5.addToggle("Index")
     .setPosition(40,350)
     .setSize(50,20)
     .setValue(false)
     .setMode(ControlP5.SWITCH)
     ;
  cp5.addToggle("Middle")
     .setPosition(40,400)
     .setSize(50,20)
     .setValue(false)
     .setMode(ControlP5.SWITCH)
     ;
  cp5.addToggle("Ring")
     .setPosition(40,450)
     .setSize(50,20)
     .setValue(false)
     .setMode(ControlP5.SWITCH)
     ;
  cp5.addToggle("Pinky")
     .setPosition(40,500)
     .setSize(50,20)
     .setValue(false)
     .setMode(ControlP5.SWITCH)
     ;
     
  //Direction Toggles   
  cp5.addToggle("Up")
     .setPosition(100,300)
     .setSize(50,20)
     .setValue(false)
     .setMode(ControlP5.SWITCH)
     ;
  cp5.addToggle("Down")
     .setPosition(100,350)
     .setSize(50,20)
     .setValue(false)
     .setMode(ControlP5.SWITCH)
     ;
  cp5.addToggle("Left")
     .setPosition(100,400)
     .setSize(50,20)
     .setValue(false)
     .setMode(ControlP5.SWITCH)
     ;
  cp5.addToggle("Right")
     .setPosition(100,450)
     .setSize(50,20)
     .setValue(false)
     .setMode(ControlP5.SWITCH)
     ;   
}
void draw() {
  
  background(162,162,162);
  fill (255,255,255);
}
/*Float Submit_Current() {
  
  String current = cp5.get(Textfield.class,"Current (mA)").getText();
  print(" Current = " + current + "mA");
  println();
  Float curr=Float.parseFloat(current);
  return curr;
}*/

Float Submit(){
  String value = cp5.get(Textfield.class,"Value").getText();
  print(" Value = " + value);
  println();
  Float value1=Float.parseFloat(value);
  
  StringBuilder sb = new StringBuilder();
  sb.append(thumb).append(",").append(index).append(",").append(middle).append(",").append(ring).append(",").append(pinky)
  .append(",").append(up).append(",").append(down).append(",").append(left).append(",").append(right)
  .append(",").append(value).append(",").append(volt_curr);
  print("Result = " + sb.toString());
  myPort.write(sb.toString());
  return value1;
}
//Voltage/Current Toggle
void Volt_Curr(boolean theFlag) {
  if(theFlag==true) {
     volt_curr= 0;
  } else {
    volt_curr= 1;
  }
} 

//Finger
void Thumb(boolean theFlag) {
  if(theFlag==true) {
     thumb= 1;
  } else {
    thumb= 0;
  }
  //println("a toggle event.");
}
void Index(boolean theFlag) {
  if(theFlag==true) {
     index= 2;
  } else {
    index= 0;
  }
  //println("a toggle event.");
}
void Middle(boolean theFlag) {
  if(theFlag==true) {
     middle= 3;
  } else {
    middle= 0;
  }
}  
void Ring(boolean theFlag) {
  if(theFlag==true) {
     ring= 4;
  } else {
    ring= 0;
  }
}
void Pinky(boolean theFlag) {
  if(theFlag==true) {
    pinky= 5;
  } else {
    pinky= 0;
  }
} 

//Directions
void Up(boolean theFlag) {
  if(theFlag==true) {
     up= 1;
  } else {
    up= 0;
  }
} 
void Down(boolean theFlag) {
  if(theFlag==true) {
     down= 1;
  } else {
    down= 0;
  }
}  
void Left(boolean theFlag) {
  if(theFlag==true) {
    left= 1;
  } else {
    left= 0;
  }
} 
void Right(boolean theFlag) {
  if(theFlag==true) {
    right= 1;
  } else {
    right= 0;
  }
}  