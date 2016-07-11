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

class Finger
{
  private:
    int _id;                        // ID
    int _activatedDirections;       // BINARY: up|down|left|right
  public:
    Finger(int id_, int dirs_);
    //Finger(int id_, int dirs_, int wf_, int dC_, float vtg_, float curr_);
    // ADD MORE CONSTRUCTOR OPTIONS !!! ***
    void setID(int id_);
    int getID();
    void setDirections(int dirs_);
    int getDirections();

    void test();
};


#endif /* finger_h */
