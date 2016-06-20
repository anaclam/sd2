/** fingers.c
*
*
*/

//#include <fingers.h> /// planning to just not use header files
#include <stdio.h>
//#include <stdbool.h>


//#include <string.h>
//----------//
// typedefs //
//----------//
typedef struct finger_s finger;
typedef enum {SINE=0, SQUARE=1, TRIANGLE=2, PULSE=3} waveform_e;

//-----------------//
// struct finger_s //
//-----------------//
struct finger_s
{
    int id;                         // 1: TMB, 2: IND, 3: MID, 4: RNG, 5: PKY
    int ActivatedDirections[4];
    int waveform;                   // 0: SINE, 1: SQUARE, 2: TRIANGLE, 3: PULSE
    int dutyCycle;                  // 1-100: As percent
    float voltageInput;
} finger_default = {0, {0,0,0,0}, SINE, 0, 0.0}; //, false};

//-----------------------//
// function declarations //
//-----------------------//
void printFingerInfo(finger finger_);
char * whichFinger(finger finger_);
char * whichWaveform(finger finger_);
void printActivated(finger finger_);
char * whichDirection(int i);
bool isActive(finger finger_);
float getVoltage(finger finger_);

void updateID(finger *finger_, int id_);
//void updateActivatedDirections(finger *finger_, int activatedDirections_[4]);
void updateWaveform(finger *finger_, int waveform_);
void updateDutyCycle(finger *finger_, int dutyCycle_);
void updateVoltage(finger *finger_, float voltage_);


//---------------------//
// funtion definitions //
//---------------------//
void printFingerInfo(finger finger_)
{
    printf("\n");
    printf("--------- FINGER DETAILS: %s ---------\n", whichFinger(finger_));
    printf("Waveform: %s \n", whichWaveform(finger_));
    //printf("Activated Directions (U D L R): %d %d %d %d \n", finger_.ActivatedDirections[0], finger_.ActivatedDirections[1], finger_.ActivatedDirections[2], finger_.ActivatedDirections[3]);
    
    printf("Activated Directions: ");
    printActivated(finger_);

    //printf("whichActivated\n"); whichActivated(finger_);
    printf("Duty Cycle: %d \n", finger_.dutyCycle);
    printf("Activation Status: %d \n", isActive(finger_));
    printf("Input Voltage: %2.1f V", getVoltage(finger_));
    printf("\n");
}

char * whichFinger(finger finger_)
{
    switch (finger_.id)
    {
        case 1:
            return "TMB";
        case 2:
            return "IND";
        case 3:
            return "MID";
        case 4:
            return "RNG";
        case 5:
            return "PKY";
        default:
            return "---";
    }
}

char * whichWaveform(finger finger_)
{
    switch (finger_.waveform)
    {
        case 0:
            return "SINE";
        case 1:
            return "SQUARE";
        case 2:
            return "TRIANGLE";
        case 3:
            return "PULSE";
        default:
            return "-----";
    }
}

void printActivated(finger finger_)
{
    for (int i=0; i<4; i++)
    {
        if (finger_.ActivatedDirections[i])
        {
            printf(whichDirection(i));
            printf(" ");
        }
        else printf("- ");
    }
    printf("\n");
}

char * whichDirection(int i)
{
    switch (i)
    {
        case 0:
            return "U";
        case 1:
            return "D";
        case 2:
            return "L";
        case 3:
            return "R";
        default:
            return "-";
    }
}

bool isActive(finger finger_)
{
    for (int i=0; i<4; i++)
    {
        if (finger_.ActivatedDirections[i])
        {
            return true;
        }
    }
    return false;
}

float getVoltage(finger finger_)
{
    return finger_.voltageInput;
}

void updateID(finger *finger_, int id_)
{
    finger_->id = id_;
}

/*
void updateActivatedDirections(finger *finger_, int *activatedDirections_)
{
    for (int i=0; i<4; i++)
    {
        finger_->ActivatedDirections = activatedDirections_;
    }
}*/

void updateWaveform(finger *finger_, int waveform_)
{
    finger_->waveform = waveform_;
}

void updateDutyCycle(finger *finger_, int dutyCycle_)
{
    finger_->dutyCycle = dutyCycle_;
}

void updateVoltage(finger *finger_, float voltage_)
{
    finger_->voltageInput = voltage_;
}