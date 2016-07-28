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
    //int timeUntilAutoShutoff;
    ///bool shutoffActivated; // default is false. If the shutoff is activated,
                           // will not activate anything until a new string from input is read,
                           // to prevent arduino loop from activating unintentaionlly
                           // Right now, needs different string to activate again
                           // Ideally would like to update logic so user can submit same string again to activate
    void parse(String userInput);
    
public:
    Input();
    Input(String userInput); // "0000 0000 0000 0000 0000, <timeTilShutoff>"
    String getSMAS();
    int getTimeUntilAutoShutoff();
};

#endif /* Input_h */
