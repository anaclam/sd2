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
    int _fanID;
    int _fanSpeed;
public:
    //void init(int, int);
    Fan(int id_, int speed_);
    int getFanPin();
    int getFanSpeed();
    void setFanSpeed(int);
    void activate();
};

#endif /* fan_h */
