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

class InputHandler
{
private:
  Input input;
public:
  InputHandler(Input input_);
  void compute();
};

#endif /* InputHandler_h */

