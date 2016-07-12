#include "Arduino.h"
#include "waveform.h"


const int Waveform::_period = 1000;

Waveform::Waveform()
{

}


Waveform::Waveform(int wf_, int dC_, bool marker_, float val_, bool onOff_)
{
    _waveform = wf_;
    _dutyCycle = dC_;
    _inputMarker = marker_;
    _value = val_;
    _onOff = onOff_;
}

void pulse(int dC_, SMA sma_)
{
    if(dC_ >= 1 && dC_<=99)
    {
        //if 50 *1000
    }
}


bool Waveform::isOn()
{
    return (_value > 0);
}

void Waveform::turnOff()
{
   // if (isOn) _value = 0;
}

void Waveform::setValue(float val_)
{
    _value = val_;
}

float Waveform::getValue()
{
    return _value;
}

void Waveform::sine()
{
    // sine wave
    
}

