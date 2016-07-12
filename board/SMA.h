//
//  SMA.h
//  
//
//  Created by Annie Wu on 7/11/16.
//
//

#ifndef SMA_h
#define SMA_h

#include <stdio.h>

enum FINGER {THUMB=1, INDEX=2, MIDDLE=3, RING=4, PINKY=5};
enum DIRECTION {UP=1, DOWN=2, LEFT=3, RIGHT=4};

class SMA
{
private:
    const static int _fingers[]; // holds ints for finger pins
    const static int _directions[]; // holds ints for direction pins
    
    int _finger;
    int _direction;
    
public:
    SMA(int finger_, int dir_);
    int getFinger();
    int getDirection();
    void turnOn();
    void turnOn(int delay_);
    void turnOff();
    void turnOff(int delay_);
}


#endif /* SMA_h */
