#include <stdio.h>

typedef enum {=0, SQUARE=1, TRIANGLE=2, PULSE=3} waveform_e;

struct fan
{
	
	int tempPin;   
	int fan;       
	int led;       
	int temp;
	int tempMin;   
	int tempMax;   
	int fanSpeed; //what is the range for this variable
	int fanLCD;
}; 

	struct fan fan_run;
	
	fan_run.tempPin = A1;		// the output pin of LM35
	fan_run.fan = 11;   		// the pin where fan is
	fan_run.led = 8;			// led pin
	fan_run.tempMin = 30;		// the temperature to start the fan
	fan_run.tempMax = 70;		// the maximum temperature when fan is at 100%
	
	
	
/*	void setup() {
	pinMode(fan_run.fan, OUTPUT);
	pinMode(fan_run.led, OUTPUT);
	pinMode(fan_run.tempPin, INPUT);
	lcd.begin(16,2);  //check to see if this line is needed?
	}
	*/
	
	
	void runfan() {

    fan_run.temp = readTemp();     // get the temperature
    if(fan_run.temp < fan_run.tempMin) {   // if temp is lower than minimum temp
       //fan_run.fanSpeed = 0;      // fan is not spinning
       digitalWrite(fan, LOW);
    }
   /* if((fan_run.temp >= fan_run.tempMin) && (fan_run.temp <= fan_run.tempMax)) {  // if temperature is higher than minimum temp
       
	   
	   //fan_run.fanSpeed = map(fan_run.temp, fan_run.tempMin, fan_run.tempMax, 32, 255); // the actual speed of fan
	   //what range is 32-255(assume it's even)
       //fan_run.fanLCD = map(fan_run.temp, fan_run.tempMin, fan_run.tempMax, 0, 100);  // speed of fan to display on LCD
       analogWrite(fan_run.fan, fan_run.fanSpeed);  // spin the fan at the fanSpeed speed
    } 
*/
   // if(fan_run.temp > fan_run.tempMax) {        // if temp is higher than tempMax
     else{
		 
	 digitalWrite(fan_run.fan, HIGH); //fan spinning fast
     //digitalWrite(fan_run.led, HIGH);  // turn on led
    } 
	//else {                    // else turn of led
     //digitalWrite(fan_run.led, LOW);
    }

    printf("TEMP: ");
    printf(fan_run.temp);      // display the temperature
    printf("C ");
    printf("\n");
	//lcd.setCursor(0,1);   // move cursor to next line
    printf("FANS: ");
    printf(fan_run.fanLCD);    // display the fan speed
    printf("%");
    delay(200);
    //lcd.clear();
	}

	
	int readTemp() {  // get the temperature and convert it to celsius
    fan_run.temp = analogRead(tempPin);
	//I expect to get this in celsius
	//c=(f-32)* (5/9)
	//f=c(9/5) +32
    return fan_run.temp * 0.48828125;
	}