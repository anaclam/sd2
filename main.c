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
    
    printf("\n\nThis is a Thumb with up and left activated, SQUAREWV, DC 25\n");
    finger finger2 = {1, {1, 0, 1, 0}, SQUARE, 25};
    printFingerInfo(finger2);

}

