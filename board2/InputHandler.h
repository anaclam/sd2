//
//  InputHandler.h
//  
//
//  Created by Annie Wu on 7/16/16.
//
//

#ifndef InputHandler_h
#define InputHandler_h

#include <stdio.h>
#include <Arduino.h>
#include "Input.h"

//enum directionPins { UP=5, DOWN=6, LEFT=9, RIGHT=10 };
//enum fingerPins { THUMB=7, INDEX=8, MIDDLE=11, RING=12, PINKY=13 };

class InputHandler
{
private:
  Input input;
public:
  InputHandler(Input input_);
  //InputHandler();
  
  void compute();
    // calls something to parseSMA String
    // creates activator
    // activates
};

#endif /* InputHandler_h */

