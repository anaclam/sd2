//
//  main.cpp
//  
//
//  Created by Annie Wu on 7/3/16.
//
//

#include "Arduino.h"
#include "test.h"
#include <iostream>
#include <string>

const int Test::_fingers[] = {7, 8, 11, 12, 13};
const int Test::_directions[] = {5, 6, 9, 10};
const int Test::_fans[] = {0, 1, 2, 4};

Test::Test()
{
}

void Test::off()
{
    for ( int i = 0; i<5 ; i++)
    {
        digitalWrite(_fingers[i], HIGH); //will ensure off
        for (int j = 0; j<4; j++)
        {
            digitalWrite(_directions[j], LOW); //will ensure off
        }
    }
}

void Test::on()
{
    Test::off();
    
    for (int i = 0; i<4 ; i++)
    {
        digitalWrite(_directions[i], HIGH); //turn on
        delay(480);
        for (int j = 0; j<5; j++)
        {
            digitalWrite(_fingers[j], LOW); //turn on
            delay(120);
        } 
    }
}

void Test::useString(String input_)
{
  input_ = "1,5,1,1.8,0";
  /*
  String finger = String::getValue(input_, ",", 0);
  String dir = getValue(input_, ",", 1);
  String wf_type = getValue(input_, ",", 2);
  String value = getValue(input_, ",", 3);
  String vtgOrCurr = getValue(input_, ",", 4);
  */
}

void Test::useFan(int fanNumber_)
{
  for (int i = 0; i<4 ; i++)
  {
    if (fanNumber_ != i) 
   {
    digitalWrite(_fans[i], LOW);
    //delay(500);
   } 
   else digitalWrite(_fans[i], HIGH);
   //delay(500);
  }
}
