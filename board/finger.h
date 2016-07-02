//
//  finger.h
//  
//
//  Created by Annie Wu on 6/30/16.
//
//

#ifndef finger_h
#define finger_h

#include "Arduino.h"
#include <stdio.h>

//-------//
// enums //
//-------//
enum ID {THUMB=1, INDEX=2, MIDDLE=3, RING=4, PINKY=5};

enum Binary {b0000, b0001, b0010, b0011,
                   b0100, b0101, b0110, b0111,
                   b1000, b1001, b1010, b1011,
                   b1100, b1101, b1110, b1111};

enum WaveformType {SINE, SQUARE, TRIANGLE, PULSE};

class Finger
{
  private:
    int _id;                        // ID
    int _activatedDirections;       // BINARY: up|down|left|right
    int _waveform;                  // WAVEFORM
    int _dutyCycle;                 // 1-100, as percent
    float _voltage;
    float _current;
  public:
    Finger(int id_, int dirs_, int wf_, int dC_, float vtg_, float curr_);
    // ADD MORE CONSTRUCTOR OPTIONS !!! ***
    void setID(int id_);
    int getID();
    void setDirections(int dirs_);
    int getDirections();
    void setWaveform(int wf_);
    int getWaveform();
    void setDutyCycle(int dc_);
    int getDutyCycle();
    void setVoltage(float vtg_);
    float getVoltage();
    void setCurrent(float curr_);
    float getCurrent();
    
    void test();
};


#endif /* finger_h */
