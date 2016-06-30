#include "fan.h"
#include "finger.h"
#include <stdio.h>
//#include <iostream>



int ledPin = 13;

void setup()
{
  pinMode (ledPin, OUTPUT);
}

void loop()
{
    Finger finger1(THUMB, 1, SINE, 50, 1.5, 0.0);
    finger1.setVoltage(0);
    finger1.test();
    /*Fan fan1(1, false);
    //fan1.activate();
    fan1.setFanSpeed(true);
    fan1.activate();*/
}
