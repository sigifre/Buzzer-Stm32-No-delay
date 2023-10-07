#ifndef BuzzerT_h
#define BuzzerT_h

#include "Arduino.h"

class BuzzerT{
private:

public:
	


uint8_t Play;
HardwareTimer *TIMER;
int *image[32][2];

uint8_t Pin;

unsigned long lastStart;
int Freq;
int Dura;

int  lastFreq;
int  lastConfig;
uint8_t counter;
uint8_t lastCounter;


uint32_t DutyCyc;
uint32_t PeriodCyc;
uint16_t Prescaler;
uint16_t Overflow;


BuzzerT(uint8_t Pin);
void Melody(int (&image)[32][2]);
void ConfigTimer(int  Freq);
void DisableBuzzer();
void EnableBuzzer();


};

#endif