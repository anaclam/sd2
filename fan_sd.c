
LiquidCrystal lcd(7,6,5,4,3,2);

struct fan
{
	
	int tempPin;   
	int fan;       
	int led;       
	int temp;
	int tempMin;   
	int tempMax;   
	int fanSpeed;
	int fanLCD;
}; 


main()
{
	struct fan fan_run;
	
	fan_run.tempPin = A1;		// the output pin of LM35
	fan_run.fan = 11;   		// the pin where fan is
	fan_run.led = 8;			// led pin
	fan_run.tempMin = 30;		// the temperature to start the fan
	fan_run.tempMax = 70;		// the maximum temperature when fan is at 100%
	
	
	
	void setup() {
	pinMode(fan_run.fan, OUTPUT);
	pinMode(fan_run.led, OUTPUT);
	pinMode(fan_run.tempPin, INPUT);
	lcd.begin(16,2);  //check to see if this line is needed?
	}
	
	void loop() {

    fan_run.temp = readTemp();     // get the temperature
    if(fan_run.temp < fan_run.tempMin) {   // if temp is lower than minimum temp
       fan_run.fanSpeed = 0;      // fan is not spinning
       digitalWrite(fan, LOW);
    }
    if((fan_run.temp >= fan_run.tempMin) && (fan_run.temp <= fan_run.tempMax)) {  // if temperature is higher than minimum temp
       fan_run.fanSpeed = map(fan_run.temp, fan_run.tempMin, fan_run.tempMax, 32, 255); // the actual speed of fan
       fan_run.fanLCD = map(fan_run.temp, fan_run.tempMin, fan_run.tempMax, 0, 100);  // speed of fan to display on LCD
       analogWrite(fan_run.fan, fan_run.fanSpeed);  // spin the fan at the fanSpeed speed
    } 

    if(fan_run.temp > fan_run.tempMax) {        // if temp is higher than tempMax
     digitalWrite(fan_run.fan, HIGH); //fan spinning fast
     digitalWrite(fan_run.led, HIGH);  // turn on led
    } else {                    // else turn of led
     digitalWrite(fan_run.led, LOW);
    }

    lcd.print("TEMP: ");
    lcd.print(fan_run.temp);      // display the temperature
    lcd.print("C ");
    lcd.setCursor(0,1);   // move cursor to next line
    lcd.print("FANS: ");
    lcd.print(fan_run.fanLCD);    // display the fan speed
    lcd.print("%");
    delay(200);
    lcd.clear();
}

	int readTemp() {  // get the temperature and convert it to celsius
    fan_run.temp = analogRead(tempPin);
    return fan_run.temp * 0.48828125;
}}







