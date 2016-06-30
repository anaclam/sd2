//
//  finger.cpp
//  
//
//  Created by Annie Wu on 6/30/16.
//
//

#include "Arduino.h"
#include "finger.h"

Finger::Finger(int id_, int dirs_, int wf_, int dC_, float vtg_, float curr_)
{
    _id = id_;
    _activatedDirections = dirs_;
    _waveform = wf_;                  // WAVEFORM
    _dutyCycle = dC_;                 // 1-100, as percent
    _voltage = vtg_;
    _current = curr_;
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

void Finger::setWaveform(int wf_)
{
    _waveform = wf_;
}

int Finger::getWaveform()
{
    return _waveform;
}

void Finger::setDutyCycle(int dc_)
{
    _dutyCycle = dc_;
}

int Finger::getDutyCycle()
{
    return _dutyCycle;
}

void Finger::setVoltage(float vtg_)
{
    _voltage = vtg_;
}

float Finger::getVoltage()
{
    return _voltage;
}

void Finger::setCurrent(float curr_)
{
    _current = curr_;
}

float Finger::getCurrent()
{
    return _current;
}

void Finger::test()
{
    if (_voltage>0)
    {
        digitalWrite(13, HIGH);
    }
    else digitalWrite(13,LOW); 
}

