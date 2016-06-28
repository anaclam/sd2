//#include <stdio.h>

//---------------------//
// typedefs and consts //
//---------------------//
typedef struct fan_s fan;
const int tempThreshold = 40;

//--------------//
// struct fan_s //
//--------------//
struct fan_s
{
    int fanId;
//	int sensorPin;
	int fanPin;
//	int temp;
	bool fanSpeed;
}; //no default case

//-----------------------//
// function declarations //
//-----------------------//
void printFanInfo(fan fan_);
int getTemp(int fanId_);
bool getFanSpeed(fan fan_);
void setFanSpeed(fan fan_);

//----------------------//
// function definitions //
//----------------------//
void printFanInfo(fan fan_)
{
    printf("\n");
    printf("Fan ID: %d \n", fan_.fanId);
    printf("Temp: %d \n", getTemp(fan_));
    printf("Fan Speed: %d \n", fan_.fanSpeed);
    
    printf("\n");
}

int getTemp(int fanId_)
{
    /* COMMENTED FOR TESTING ONLY
    //get temperature from tempsensor with same ID
    int temperature;
    int tempSensorPin;
    //select correct pin for fan
    // This is ugly but whatever
    if (fanId_==1) tempSensorPin = 5;
    else if (fanId_==2) tempSensorPin = 4;
    else if (fanId_==3) tempSensorPin = 3;
    else if (fanId_==4) tempSensorPin = 2;
    else printf("\n\n Error: Invalid fanID \n\n");

    temperature = analogRead(tempSensorPin);
    */
    
    /*TESTING*/
    int temperature = 30;
    
    return temperature;
    
}

bool getFanSpeed(fan fan_)
{
    return fan_.fanSpeed;
}

void setFanSpeed(fan fan_)
{
    int sensorTemp = getTemp(fan_.id);
    if (sensorTemp < tempThreshold)
    {
        fan_.fanSpeed = false;
        digitalWrite(fan_.fanPin, LOW);
    }
    else
    {
        fan_.fanSpeed = true;
        digitalWrite(fan_.fanPin, HIGH);
    }
    
    
}



//-------------//
// for arduino //
//-------------//

//	struct fan fan_run;

/*
	fan_run.tempPin = A1;		// the output pin of LM35
	fan_run.fan = 11;   		// the pin where fan is
*/
//    const int tempMin = 30;		// the temperature to start the fan
//	const int tempMax = 70;		// the maximum temperature when fan is at 100%

	
	
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