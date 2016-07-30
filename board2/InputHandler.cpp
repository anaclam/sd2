//
//  InputHandler.cpp
//  
//
//  Created by Annie Wu on 7/16/16.
//
//

#include "InputHandler.h"
#include "Activator.h"
#include <Arduino.h>

InputHandler::InputHandler(Input input_)
{
    input = input_;
}


void InputHandler::compute()
{
    Activator activator(input.getSMAS());
    activator.activate();
}
