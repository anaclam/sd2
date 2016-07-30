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
    void parse(String userInput);
    
public:
    Input();
    Input(String userInput); 
    String getSMAS();
    int getTimeUntilAutoShutoff();
};

#endif 
