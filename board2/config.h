//
//  config.h
//  
//
//  Created by Annie Wu on 8/3/16.
//
//
// Note it is not the best practice to make all variables of a class public, 
// but we are making an exception because this is just to configure variables 
// so that they only need to be set once
//
// Add values in config.cpp
// If you want to add a new variable, remember you must declare it in this header
// as well as in the source file.


#ifndef config_h
#define config_h
#include <Arduino.h>
#include <stdio.h>

class Config
{
public:
    int up;
    int down;
    int left;
    int right;
    
    int thumb;
    int index;
    int middle;
    int ring;
    int pinky;
    
    int fan1;
    int fan2;
    int fan3;
    int fan4;
    
    int tempSensor1;
    int tempSensor2;
    int tempSensor3;
    int tempSensor4;
    
    boolean inverted; // HIGH for Directions and LOW for Fingers
                      // However, our circuit has a active LOW for directions and HIGH for fingers
                      // so we use the inverted flag to use the correct logic without having to change
                      // this everywhere
    int timeToCompleteSwitching;
    int tempThreshold;
    //int directionPins[4];
    //int fingerPins[5];
    
    Config();
};
#endif /* config_h */
