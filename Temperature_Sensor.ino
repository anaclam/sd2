int sensor = A0;
float voltage;
float temperature;
void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  voltage=(analogRead(sensor) * 0.004882814);
  temperature = (voltage - 0.5)*100.0;

  Serial.print("voltage: ");
  Serial.println(voltage);
  Serial.print("deg C: ");
  Serial.println(temperature);

  delay(5000);

  int rawvoltage= analogRead(sensor);
  float volts= rawvoltage/205.0;//It is divided by 205 because a span of 1024 values occupies 5V, 
                                //or 1024/5= 205 per volt.
  float celsiustemp= 100.0 * volts - 50;
  float fahrenheittemp= celsiustemp * 9.0/5.0 + 32.0;
  Serial.println(analogRead(sensor));
  Serial.print(celsiustemp);
  Serial.println(" Celsius");
  Serial.print(fahrenheittemp);//
  Serial.println(" Fahrenheit");
  delay(300000);
}
