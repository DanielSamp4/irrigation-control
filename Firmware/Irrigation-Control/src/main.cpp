/**
 *	Firmware to run the project Irrigation-control 
 *	@file irrigation-control
 *	@author	daniel.sampaio0144@gmail.com
 *	@version	1.0
 *	@date	2022-06-19
 */

#include <Arduino.h>

#define LDR 35
#define Soil_Humidity 34
#define Solenoid 25

#define Condition_LDR 100 // here you put your conditions of LDR
#define Condition_Soil_Humidity 100 // here you put your conditions of Soil_Humidity

void setup() {
  Serial.begin(115200);
  pinMode(Solenoid, OUTPUT);
}

//some feature implamentation will be use sleep mode on  ESP32 to save energy for battery
void loop() {
if (analogRead(LDR) < Condition_LDR && analogRead(Soil_Humidity) > Condition_Soil_Humidity)
  digitalWrite(Solenoid,HIGH);
else  
  digitalWrite(Solenoid,LOW);
}