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

Input::Input()
{
  //
}

void Input::parse(String userInput)
{
    int commaSMAs = userInput.indexOf(',');
    int commaPulse = userInput.indexOf(',', commaSMAs+1);
    int commadC = userInput.indexOf(',', commaPulse+1);
    
    String smas_s = userInput.substring(0, commaSMAs);
    String pulse_s = userInput.substring(commaSMAs+1, commaPulse);
    String dutyCycle_s = userInput.substring(commaPulse+1, commadC);
    String delay_s = userInput.substring(commadC);
    
    SMAS = smas_s;
    
    if (pulse_s.toInt() == 0) pulse=false;
    else pulse=true;
    
    dutyCycle = dutyCycle_s.toInt();
    delay = delay_s.toInt();
}

String Input::getSMAS()
{
    return SMAS;
}

bool Input::isPulse()
{
    return pulse;
}

int Input::getDutyCycle()
{
    return dutyCycle;
}

int Input::getDelay()
{
    return delay;
}
