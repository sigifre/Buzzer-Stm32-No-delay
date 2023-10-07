#include <BuzzerT.h>
#include <Tones.h>


BuzzerT BuzzerA(PB9);
BuzzerT BuzzerB(PB9);
BuzzerT BuzzerC(PB9);

void setup(){
BuzzerA.Play=true;
}

void loop(){
BuzzerA.Melody(Startup);
BuzzerB.Melody(Track1);
BuzzerC.Melody(Track2);


if (millis() >  5000 && millis()<5005 ){BuzzerB.Play=true;}

if (millis() > 10000 && millis()<10005){BuzzerC.Play=true;}
	
if (millis() > 15000 && millis()<15005){BuzzerA.Play=true;}
}
