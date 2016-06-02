/** fingers.c
*
*
*/

#include <fingers.h>
#include <stdio.h>



struct finger()
{
    // Array ActivatedDirections [Up, Down, Left, Right]
    // Will have a value of true or false for each one. Always size 4.
    // Default values is false for all, aka nothing is activated.
    boolean ActivatedDirections [4] = [false, false, false, false];
    //char waveform[]; // DECLARE AN ENUM FOR THIS LATER
    int waveform; // make enum for this*********
    int dutyCycle = 0 // Default dutyCycle 0 aka nothing
    boolean ActivationStatus = false; // default should be deactivated
}

boolean getActivationStatus(struct finger finger_)
{
    return finger_.ActivationStatus;
}

void setDutyCycle(struct finger finger_, int dutyCycle_)
{
    finger.dutyCycle = dutyCycle_;
}

void setWaveform(struct finger finger_, int waveformEnum_)
{
    finger.waveform = waveformEnum_;
}

void setDirections(struct finger finger_, boolean directions_ [4])
{
    finger_.ActivatedDirections = directions_;
    if (finger_.ActivatedDirections != [false, false, false, false])
    {
        finger_.ActivationStatus = true;
    }
    else
    {
        finger_.ActivationStatus = false;
    }
}

void getPosition(struct finger finger_)
{
    // not sure how to implement yet... will probably need some kind of
    // feedback from waveform or something....
}