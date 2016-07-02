#ifndef waveform_h 
#define waveform_h 
 
 
#include "Arduino.h" 
#include <stdio.h> 
#include <stdbool.h>

class Waveform
{
private:
    int _waveform;     // remember WaveformType enum SINE, SQUARE, TRIANGLE, PULSE
    bool _inputMarker; // true=voltage, false=current
    float _value;      // user provided voltage or current
    bool _onOff;       // true=ON, false=OFF
public:
    Waveform(int wf_, bool marker_, float val_, bool onOff_);
    // may need more constructors?
    
    bool isOn();
    
    void activate();
    void deactivate();
    void toggle();
    void setValue(float val_);
    float getValue();
};


#endif /* waveform_h */
