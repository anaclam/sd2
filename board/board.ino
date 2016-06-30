#include "fan.h"
#include <stdio.h>
//#include <iostream>



int ledPin = 13;

void setup()
{
  pinMode (ledPin, OUTPUT);
}

void loop()
{
    Fan fan1(1, false);
    fan1.activate();
}
