//
//  Input.h
//  
//
//  Created by Annie Wu on 7/16/16.
//
//

#ifndef Input_h
#define Input_h

#include <stdio.h>
#include <Arduino.h>

class Input
{
private:
    String SMAS;
    bool pulse;
    int dutyCycle;
    int delay;
    
    void parse(String userInput);
    
public:
    Input();
    Input(String userInput);
    String getSMAs();
    bool isPulse();
    int getDutyCycle();
    int getDelay();
};

#endif /* Input_h */
