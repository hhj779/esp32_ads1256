/*
 Name:		esp32_ads1256
 Created:	22/03/2023
 Author:	hhj
 reference :https://github.com/YordanYanakiev/ADS1256
*/

#include <Arduino.h>
#include <SPI.h>
#include "ADS1256.h"

/*
//Pin connection reference
PDWN -        GPIO 26
CS -          GPIO 25
DRDY -        GPIO 27
DOUT / MOSI - GPIO 12
DIN / MISO -  GPIO 13
CLK -         GPIO 14
GND -         GND //attention:ESP32 and ADS1256 must be together!!!
5V -          vin/5V
*/
#define PDWN 26 // Modify here to your wiring
#define CS 25
#define DRDY 27
#define DOUT 12
#define DIN 13
#define CLK 14
#define spdSPI 1700000

ADS1256 ads;
void setup()
{
	Serial.begin(115200);
	// ADS1256 pin connection
	ads.pinCS = CS;
	ads.pinDIN = DIN;
	ads.pinDOUT = DOUT;
	ads.pinRDY = DRDY;
	ads.pinRESET = PDWN;
	ads.pinSCLK = CLK;
	ads.speedSPI = spdSPI;
	ads.init();
}

void loop()
{
	// choose your Channel(1~8) here
	// If no parameters are passed, all channel voltages are read by default
	// ads.readInputToAdcValuesArrayChannel(1);
	ads.readInputToAdcValuesArrayChannel();
	delay(500);
	Serial.print(ads.adcValues[0] * 0.00000059453, 6); // The converted voltage value is output here
	Serial.println();
}
