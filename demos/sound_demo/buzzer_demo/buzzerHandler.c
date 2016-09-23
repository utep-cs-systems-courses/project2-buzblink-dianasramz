#include <msp430.h>

static unsigned char count = 0;
static unsigned int c = 1;
static unsigned char down = 1;

void buzzer_control();

void timerHandler(){
	count++;
	if(count >= 10){
		count = 0;

		if(down)
			c++;
		else
			c--;

		if(c > 1000 || c <= 1)
			down = 1 - down;

		buzzer_control();
	}
}

void buzzer_control(){
	TA0CCR0 = c;
	TA0CCR1 = c >> 1;
}