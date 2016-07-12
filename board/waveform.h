#ifndef waveform_h 
#define waveform_h 
 
 
#include "Arduino.h" 
#include <stdio.h> 
#include <stdbool.h>

enum Binary {b0000, b0001, b0010, b0011,
                   b0100, b0101, b0110, b0111,
                   b1000, b1001, b1010, b1011,
                   b1100, b1101, b1110, b1111};

enum WaveformType {SINE, SQUARE, TRIANGLE, PULSE};

class Waveform
{
private:
    const static int _fingers[]; // holds ints for finger pins
    const static int _directions[]; // holds ints for direction pins
    const static int _period; 
    int _waveform;     // remember WaveformType enum SINE, SQUARE, TRIANGLE, PULSE
    int _dutyCycle;    // value should be between 0 and 255 (0= always off, 255 always on)
    bool _inputMarker; // true=voltage, false=current
    float _value;      // user provided voltage or current
    bool _onOff;       // true=ON, false=OFF
    
public:
    Waveform();
    Waveform(int wf_, int dC_, bool marker_, float val_, bool onOff_);
    // may need more constructors?
    
    void pulse(int dC_, SMA sma_);
    
    bool isOn();
    void turnOff();
    void setValue(float val_);
    float getValue();

    void sine(); //just to see if works. future, will need to set period and ampl.
};


#endif /* waveform_h */
