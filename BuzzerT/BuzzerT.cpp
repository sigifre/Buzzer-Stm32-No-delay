#include "Arduino.h"
#include "BuzzerT.h"

BuzzerT::BuzzerT(uint8_t Pin) {	
this->Pin = Pin;
pinMode(Pin, PWM);
DisableBuzzer();
TIMER = new HardwareTimer(4);
}


void BuzzerT::Melody(int (&image)[32][2]){
//Serial.print("Enabled "); Serial.println(String(Enabled));

if (Play) {
Freq = (int)image[counter][0];	
//Serial.print("Freq ");Serial.println(String(Freq));

Dura = (int)image[counter][1];
//Serial.print("Dura ");Serial.println(String(Dura));

			if (Freq != lastFreq) {
				if (Freq>0) {
								if (Freq != lastConfig) {
									ConfigTimer(Freq); 
									lastConfig=Freq; 
		             } 
		             EnableBuzzer();
					} else {DisableBuzzer();}
				lastFreq=Freq;
				lastStart=millis();
		}
	
		if (millis()>= (lastStart+Dura)) {
			counter++;Serial.println(String(counter));
			if (counter==32) {DisableBuzzer(); Play=false;  counter=0;}
		}
}
	
}


void BuzzerT::ConfigTimer(int Freq){
TIMER->pause();	
PeriodCyc = (1000000/Freq) * (F_CPU/1000000.0);// ciclos por us del STM32
#define MAX_RELOAD ((1 << 16) - 1)//timer 16 bits resolution
Prescaler = (PeriodCyc / MAX_RELOAD) + 1.0;
TIMER->setPrescaleFactor(Prescaler);
Overflow = (PeriodCyc + (Prescaler / 2.0)) / Prescaler;
TIMER->setOverflow(Overflow);
DutyCyc = Overflow/2;
TIMER->refresh();
TIMER->resume();
}

void BuzzerT::DisableBuzzer(){pwmWrite(Pin,0      );}
void BuzzerT:: EnableBuzzer(){pwmWrite(Pin,DutyCyc);}


