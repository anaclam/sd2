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
  // DO NOT REMOVE
  // must have default constructor to pass in object for InputHandler
}

Input::Input(String userInput)
{
    parse(userInput);
}

void Input::parse(String userInput)
{
    SMAS = userInput;
}

String Input::getSMAS()
{
    return SMAS;
}

