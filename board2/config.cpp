//
//  config.cpp
//  
//
//  Created by Annie Wu on 8/3/16.
//
//

#include "config.h"

Config::Config()
{
  up = 4;
  down = 5;
  left = 6;
  right = 7; 
  
  thumb = 8;
  index = 9;
  middle = 10;
  ring = 11;
  pinky = 12;
  
  fan1 = 15; 
  fan2 = 2;
  fan3 = 3;
  fan4 = 13;
  
  tempSensor1 = 19;
  tempSensor2 = 18;
  tempSensor3 = 17;
  tempSensor4 = 16;
  
  inverted = false;
  timeToCompleteSwitching = 100; 
  tempThreshold = 100; //Fahrenheit
}


