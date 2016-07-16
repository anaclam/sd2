//
//  tempSensor.cpp
//  
//
//  Created by Annie Wu on 7/14/16.
//
//

#include "tempSensor.h"

TempSensor::TempSensor(int pin_)
{
    _pin = pin_;
}

float TempSensor::getTemp()
{
    int reading = analogRead(_pin);
    
    // reading * 5 to convert to vtg
    // subtract .5v offset
    // * 100 converts to 10mV per degree C
    _tempC = ((reading * 5.0) - .5) * 100;
    return _tempC;
}