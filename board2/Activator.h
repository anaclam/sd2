//
//  Activator.h
//  
//
//  Created by Annie Wu on 7/16/16.
//
//

#ifndef Activator_h
#define Activator_h

#include <stdio.h>
#include <Arduino.h>

// ENUM for pins
class Activator
{
private:
    //int directionPins[];
    //int fingerPins[];

    String SMAS[];
    
    SMATranslator();
    switching();
public:
    Activator(String smas);

    activate(); // for each in array, calls sma translator and activates that sma
};

#endif /* Activator_h */

/*
 
 int up = 5;
 int down = 6;
 int left = 9;
 int right = 10;
 
 int thumb = 7;
 int index = 8;
 int middle = 11;
 int ring = 12;
 int pinky = 13;
 
 */