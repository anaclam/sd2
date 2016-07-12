//
//  SMA.cpp
//  
//
//  Created by Annie Wu on 7/11/16.
//
//

#include "SMA.h"

SMA(int finger_, int dir_)
{
    _finger = finger_;
    _direction = dir_;
}

int getFinger()
{
    return _finger;
}

int getDirection()
{
    return _direction;
}