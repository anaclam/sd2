//
//  finger.cpp
//  
//
//  Created by Annie Wu on 6/30/16.
//
//

#include "Arduino.h"
#include "finger.h"

Finger::Finger(int id_, int dirs_)
{
    _id = id_;
    _activatedDirections = dirs_;
}

void Finger::setID(int id_)
{
    _id = id_;
}

int Finger::getID()
{
    return _id;
}

void Finger::setDirections(int dirs_)
{
    _activatedDirections = dirs_;
}

int Finger::getDirections()
{
    return _activatedDirections;
}

void Finger::test()
{
/*    if (_voltage>0)
    {
        digitalWrite(13, HIGH);
    }
    else digitalWrite(13,LOW); */
}

