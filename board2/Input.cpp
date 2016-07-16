//
//  Input.cpp
//  
//
//  Created by Annie Wu on 7/16/16.
//
//

#include "Input.h"
Input::Input(String userInput)
{
    parse(userInput);
}

Input::parse(String userInput)
{
    int comma = userInput.indexOf(',');
    int nextComma = userInput.indexOf(',', comma+1);
}

Input::String getSMAs()
{
    return SMAS;
}

Input::bool isPulse()
{
    return pulse;
}

Input::int getDutyCycle()
{
    return dutyCycle;
}

Input::int getDelay()
{
    return delay;
}