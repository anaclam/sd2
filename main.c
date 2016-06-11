// main.c

#include <stdio.h>
#include "logger.c"
#include "fingers.c"
#include <string.h>
#include <stdlib.h>



//------//
// main //
//------//
int main()
{
    logThis("Running main.c \n");
    
    finger thisFinger = finger_default;
    
    printf("This is the default finger\n");
    printFingerInfo(thisFinger);
    
    printf("\n\nThis is a Thumb with up and left activated, SQUAREWV, DC 25, 1.3v\n");
    finger finger2 = {1, {1, 0, 1, 0}, SQUARE, 25, 1.6};
    printFingerInfo(finger2);
    
    finger2.voltageInput = 6.6;
    printf("\nFinger2 updated\n");
    printFingerInfo(finger2);
    
    updateVoltage(&finger2, 8.9);
    //updateActivatedDirections(&finger2, &[5,4,3,2]);
    printf("\n\n");
    printFingerInfo(finger2);
}

