//
//  Input.hpp
//  
//
//  Created by Annie Wu on 7/14/16.
//
//

#ifndef Input_h
#define Input_h

#include <stdio.h>

// will contain all the information parsed from the string input

class Input
{
private:
    String _input;
public:
    Input(String _input);
    String getInput();
    //void setInput(String input_);
};

#endif /* Input_h */
