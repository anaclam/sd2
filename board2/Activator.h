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
#include "Input.h"

// ENUM for pins
const int directionPins[4] = {5, 6, 9, 10}; // UDLR
const int fingerPins[5] = {7, 8, 11, 12, 13}; //TIMRP

enum DIRECTION { UP=5, DOWN=6, LEFT=9, RIGHT=10 };
enum FINGER { THUMB=7, INDEX=8, MIDDLE=11, RING=12, PINKY=13 };

class Activator
{
private:
    String SMAS;
    
    int getActivatedPins(int delayTime);
    void activatePins(int finger, String fingerString, int delayTime);
    int switching();
    void allSmasOff();
    int countSMAsOn();
public:
    Activator(String smas);

    void activate(); // for each in array, calls sma translator and activates that sma


};

#endif
