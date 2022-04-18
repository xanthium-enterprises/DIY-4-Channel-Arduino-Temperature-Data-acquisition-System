// Arduino based 4 channel DAQ system
// This sketch will read the temperature from a single channel and convert it to equivalent temperature   
// https://www.xanthium.in/lm-35-four-channel-arduino-data-acquisition-system-temperature-sensing
// Average Gain of LM35 amplifier board is 3.44


int AnalogPin_AN1 = A0;    // select the input pin for lm35
int AnalogPin_AN2 = A1;    // select the input pin for lm35
int AnalogPin_AN3 = A2;    // select the input pin for lm35
int AnalogPin_AN4 = A3;    // select the input pin for lm35

float SensorValue_AN1 = 0.0;
 
void setup() 
{
  Serial.begin(9600); //Data will be send to PC

}

void loop()
{
   SensorValue_AN1 = analogRead(AnalogPin_AN1);     // Read Analog Value from AN1 pin of the amplifier 
   Serial.print("ADC-> ");
   Serial.print( SensorValue_AN1 ); 
   Serial.print( " " );
   
   SensorValue_AN1 = SensorValue_AN1 * (5.0/1024.0);// 10 bit adc,1024 divisons,
   Serial.print("V-> ");
   Serial.print( SensorValue_AN1 ); 
   Serial.print( " " );
   
   
   SensorValue_AN1 = SensorValue_AN1/3.44;          // Dividing by the gain of 3.44
   SensorValue_AN1 = SensorValue_AN1 * 100;          // 
   Serial.print("Temp-> ");
   Serial.println( SensorValue_AN1 );
   delay(1000);

}
