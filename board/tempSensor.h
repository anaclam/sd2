//
//  tempSensor.hpp
//  
//
//  Created by Annie Wu on 7/14/16.
//
//

#ifndef tempSensor_h
#define tempSensor_h

#include <stdio.h>
#include <Arduino.h>

class TempSensor
{
private:
    int _pin;
    int _tempC;
public:
    TempSensor(int pin_);
    int getTemp();
};


#endif /* tempSensor_h */
