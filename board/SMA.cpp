//
//  SMA.cpp
//  
//
//  Created by Annie Wu on 7/11/16.
//
//

#include "SMA.h"

const int SMA::_fingers[] = {7, 8, 11, 12, 13};
const int SMA::_directions[] = {5, 6, 9, 10};

SMA::SMA(int finger_, int dir_)
{
    _finger = finger_;
    _direction = dir_;
}

int SMA::getFinger()
{
    return _finger;
}

int SMA::getDirection()
{
    return _direction;
}

void SMA::turnOn()
{
    digitalWrite(_directions[_direction], HIGH);
    digitalWrite(_fingers[_finger], LOW);
}

void SMA::turnOn(int delay_)
{
    digitalWrite(_directions[_direction], HIGH);
    digitalWrite(_fingers[_finger], LOW);
    delay(delay_);
}

void SMA::turnOff()
{
    digitalWrite(_directions[_direction], LOW);
    digitalWrite(_fingers[_finger], HIGH);
}

void SMA::turnOff(int delay_)
{
    digitalWrite(_directions[_direction], LOW);
    digitalWrite(_fingers[_finger], HIGH);
    delay(delay_);
}