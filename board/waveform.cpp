#include "Arduino.h"
#include "waveform.h"






Waveform::Waveform(int wf_, bool marker_, float val_, bool onOff_)
{
    _waveform = wf_;
    _inputMarker = marker_;
    _value = val_;
    _onOff = onOff_;
}

bool Waveform::isOn()
{
    return _onOff;
}

void Waveform::activate()
{
    _onOff = true;
}

void Waveform::deactivate()
{
    _onOff = false;
}

void Waveform::toggle()
{
    if (_onOff) _onOff = false;
    else _onOff = true;
}

void Waveform::setValue(float val_)
{
    _value = val_;
}

float Waveform::getValue()
{
    return _value;
}
