#ifndef waveform_h 
#define waveform_h 
 
 
#include "Arduino.h" 
#include <stdio.h> 


class Waveform {

private:
	int waveform;
	float voltage;
	float current;

public:
	Waveform();
	//Waveform(int wf_, float vtg_, float _curr);
	void activate (int wf_, float vtg_, float _curr);
	void deactivate (int wf_, float vtg_, float _curr);
	void toggle();

};


#endif /* waveform_h */