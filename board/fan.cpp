//
//  fan.cpp
//  
//
//  Created by Annie Wu on 6/27/16.
//
//

#include "Arduino.h"
#include "fan.h"

Fan::Fan(int fanID_, int fanSpeed_)
{
    _fanID = fanID_;
    _fanSpeed = fanSpeed_; 
}

/*void Fan::init(int fanID_, bool onOff_) {
    fanID = fanID_;
    fanSpeed = onOff_;
}*/

int Fan::getFanPin ()
{
    switch(_fanID){
        case 1: return 13; //running 13 to test.. should be 0;
        case 2: return 1;
        case 3: return 2;
        case 4: return 4;
       // default: std::cout << "FanID " << fanID << " does not exist.\n";
    }
}

int Fan::getFanSpeed()
{
    return _fanSpeed;
}

void Fan::setFanSpeed (int speed_) {
    _fanSpeed = speed_;
}

void Fan::activate () {
    int pin = getFanPin();
    if (_fanSpeed == false) digitalWrite(pin, LOW);
    else digitalWrite(pin, HIGH);
}
