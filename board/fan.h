//
//  fan.h
//  
//
//  Created by Annie Wu on 6/30/16.
//
//

#ifndef fan_h
#define fan_h

#include "Arduino.h"
#include <stdio.h>
//#include <iostream>

class Fan
{
private:
    int _pin;
    void on();
    void off();
public:
    Fan(int pin_);
    void setFanSpeed(int tempC_);
};

#endif /* fan_h */
