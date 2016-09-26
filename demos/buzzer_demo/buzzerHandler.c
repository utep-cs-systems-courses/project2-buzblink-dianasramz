#include <msp430.h>

static unsigned int frequency = 10000;
static unsigned char up = 1;

void buzzer_control();

void timerHandler(){
	if(up)
		frequency++;
	else
		frequency--;

	if(frequency > 10000 || frequency <= 1)
		up = 1 - up;

	buzzer_control();
}

void buzzer_control(){
	TA0CCR0 = frequency;
	TA0CCR1 = frequency >> 1;
}