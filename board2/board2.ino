#include "fan.h"
#include "tempSensor.h"

#include "Input.h"
#include "InputHandler.h"
#include "Activator.h"

#include <stdio.h>

//------------------//
// Pin designations //
//------------------//
// Need RX and TX (DP 0, 1) for serial port communication
// USAGE: User sets constant in Activator.cpp switching method

int fan1 = 15; // Analog pin 1
int fan2 = 2;
int fan3 = 3;
int fan4 = 4;

int tempSensor1 = 19;
int tempSensor2 = 18;
int tempSensor3 = 17;
int tempSensor4 = 16;

int up = 5;
int down = 6;
int left = 9;
int right = 10;

int thumb = 7;
int index = 8;
int middle = 11;
int ring = 12;
int pinky = 13;

const int directionPin[4] = {5, 6, 9, 10}; // UDLR
const int fingerPin[5] = {7, 8, 11, 12, 13}; //TIMRP

String userInput;
String prevInput;
String globalUserInput;

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
      if(byteRead>47 && byteRead< 50)
      {
         userInput = userInput+ (byteRead-48);
      } 
      else if(byteRead== 32)
      {
        userInput+=" ";  
      }
      else if(byteRead==53)
      {
        userInput.trim();
        
        Serial.println("\nuserInput: ");
        Serial.println(userInput);
        Serial.println("\nprevInput: ");
        Serial.println(prevInput);
        
        if (prevInput != userInput)
        {
          globalUserInput = userInput;
          Serial.println("Different!");
          prevInput = userInput;
          userInput="";
        }
        else 
        {
          Serial.println("Same");
          userInput="";
        }
      }
   } 
  
   //Serial.println(globalUserInput);
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
