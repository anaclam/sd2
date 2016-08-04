//
//  fan.cpp
//  
//
//  Created by Annie Wu on 6/27/16.
//
//

#include "Arduino.h"
#include "fan.h"

Fan::Fan(int pin_)
{
    _pin = pin_;
    Config set;
    tempThreshold = set.tempThreshold;
}

void Fan::setFanSpeed (int tempC_) {
    if (tempC_ <= tempThreshold)
    {
        off();
    }
    else on();
}

void Fan::on() {
    digitalWrite(_pin, HIGH);
}

void Fan::off()
{
    digitalWrite(_pin, LOW);
}
