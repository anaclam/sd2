//
//  Input.cpp
//  
//
//  Created by Annie Wu on 7/16/16.
//
//

#include "Input.h"
Input::Input()
{
  //
}

Input::Input(String userInput)
{
    parse(userInput);
    //shutoffActivated = false;
}

void Input::parse(String userInput)
{
    int comma = userInput.indexOf(',');
    
    String smas_s = userInput.substring(0, comma);
    String shutoff_s = userInput.substring(comma);
    
    SMAS = smas_s;
    timeUntilAutoShutoff = shutoff_s.toInt();
}

String Input::getSMAS()
{
    return SMAS;
}

int Input::getTimeUntilAutoShutoff()
{
    return timeUntilAutoShutoff;
}
