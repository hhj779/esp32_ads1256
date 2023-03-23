/*
 Name:		ADS1256.h
 Created:	11/21/2018 5:24:56 PM
 Author:	Yordan
 Editor:	http://www.visualmicro.com
*/

#ifndef _ADS1256_h
#define _ADS1256_h
#define SPI_SPEED 1700000

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "SPI.h"
#include "esp32-hal-gpio.h"

class ADS1256
{
public:
	int8_t pinSCLK = -1;
	int8_t pinDIN = -1;
	int8_t pinDOUT = -1;
	int8_t pinRDY = -1;
	int8_t pinCS = -1;
	int8_t pinRESET = -1;
	uint32_t speedSPI = -1;

	unsigned long adcValues[8];
	unsigned long adc_Raws[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	byte mux[8] = {0x08, 0x18, 0x28, 0x38, 0x48, 0x58, 0x68, 0x78};

	ADS1256();

	void init(int8_t _pinCS = -1, int8_t _pinRDY = -1, int8_t _pinRESET = -1, uint32_t _speedSPI = -1);
	void readInputToAdcValuesArrayChannel(int8_t Channel=-1);
	void Reset(int8_t _CS);
	void readInputPEAKSToAdcValuesArray(int repeats);

private:
};

#endif
