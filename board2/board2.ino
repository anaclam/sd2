#include "fan.h"
#include "tempSensor.h"

#include "Input.h"
#include "InputHandler.h"
#include "Activator.h"
#include "config.h"

#include <stdio.h>

//------------------//
// Pin designations //
//------------------//
// Need RX and TX (DP 0, 1) for serial port communication
// USAGE: User sets constant in Activator.cpp switching method
//        User sets temperature in Fan.cpp
// The separation of functionality into multiple classes was to accomodate multiple 
// user input parameters, such as other waveforms, stringing multiple sequeces of SMAS together, 
// etc. This design allows expansion without further classes and keeps the overall flow consistent.
//
//const int DIRECTIONPINS[4] = {5, 6, 9, 10}; // UDLR
//int fingerPins[5] = {7, 8, 11, 12, 13}; //TIMRP
//int *dPtr = directionPins;
//int *fPtr = fingerPins;

//enum DIRECTION { UP=5, DOWN=6, LEFT=9, RIGHT=10 };
//enum FINGER { THUMB=7, INDEX=8, MIDDLE=11, RING=12, PINKY=13 };

Config set;

int fan1 = set.fan1;
int fan2 = set.fan2;
int fan3 = set.fan3;
int fan4 = set.fan4;

int tempSensor1 = set.tempSensor1;
int tempSensor2 = set.tempSensor2;
int tempSensor3 = set.tempSensor3;
int tempSensor4 = set.tempSensor4;
/*
int up = 4;
int down = 5;
int left = 6;
int right = 7;
*/

int up = set.up;
int down = set.down;
int left = set.left;
int right = set.right;

int thumb = set.thumb;
int index = set.index;
int middle = set.middle;
int ring = set.ring;
int pinky = set.pinky;

// Array of pin numbers for iteration
const int directionPin[4] = {up, down, left, right};
const int fingerPin[5] = {thumb, index, middle, ring, pinky};

// For use with UI
String userInput;
String prevInput;
String globalUserInput; // DO NOT REMOVE. 
// Unintuitive, but Arduino while loop destroys memory upon exit. 
// Must store string in global variable to access outside of loop. 
byte byteRead;

void setup()
{
  pinMode (fan1, OUTPUT);
  pinMode (fan2, OUTPUT);
  pinMode (fan3, OUTPUT);
  pinMode (fan4, OUTPUT);
  pinMode (up, OUTPUT);
  pinMode (down, OUTPUT);
  pinMode (left, OUTPUT);
  pinMode (right, OUTPUT);
  pinMode (thumb, OUTPUT);
  pinMode (index, OUTPUT);
  pinMode (middle, OUTPUT);
  pinMode (ring, OUTPUT);
  pinMode (pinky, OUTPUT);

  pinMode (tempSensor1, INPUT);
  pinMode (tempSensor2, INPUT);
  pinMode (tempSensor3, INPUT);
  pinMode (tempSensor4, INPUT);

  Serial.begin(9600);
}

void loop()
{

  // Serial read input 
  while (Serial.available())
  {

    byteRead=Serial.read();
    // decimal to char ascii
    if(byteRead>47 && byteRead< 50) // if byte represents a 0 or 1
    {
      userInput = userInput+ (byteRead-48);
    } 
    else if(byteRead== 32) // space
    {
      userInput+=" ";  
    }
    else if(byteRead==53) // 5 This is arbitrary and marks end of string from UI
    {
      userInput.trim();

      // Just feedback. Can remove if unwanted.
      Serial.println("\nuserInput: ");
      Serial.println(userInput);
      Serial.println("\nprevInput: ");
      Serial.println(prevInput);
      //

      // If different then store input in global variable for access outside of while loop
      if (prevInput != userInput)
      {
        globalUserInput = userInput;
        Serial.println("Different!");
        prevInput = userInput;
        userInput="";
      }

      // if not different do not update string
      else 
      {
        Serial.println("Same");
        userInput="";
      }
    }
  } 

  Input input(globalUserInput);
  InputHandler inputHandler(input);
  inputHandler.compute();

  // Temperature stuff
  TempSensor ts1(tempSensor1);
  TempSensor ts2(tempSensor2);
  TempSensor ts3(tempSensor3);
  TempSensor ts4(tempSensor4);

  Fan f1(fan1);
  Fan f2(fan2);
  Fan f3(fan3);
  Fan f4(fan4);

  f1.setFanSpeed(ts1.getTemp());
  f2.setFanSpeed(ts2.getTemp());
  f3.setFanSpeed(ts3.getTemp());
  f4.setFanSpeed(ts4.getTemp());
}

