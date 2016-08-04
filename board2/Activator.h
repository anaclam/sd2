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
#include "config.h"


class Activator
{
private:
    String SMAS;   
    int directionPins[4];
    int fingerPins[5];
    boolean inverted;
    int timeToCompleteSwitching;
    char on;
    char off;
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
