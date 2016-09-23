#include <msp430.h>

static unsigned char led_state = 0;
static unsigned char count = 0;

void led_control();

int timerHandler(){
	count++;
	if(count >= 100){
		led_state = 1 - led_state;
		count = 0;
		led_control();
	} 
}

void led_control(){
	char ledFlags = 0;
	if(led_state)
		ledFlags |= BIT6;
	P1OUT &= (0xff-(BIT6+BIT0)) | ledFlags; // clear bit for off leds
	P1OUT |= ledFlags;        // set bit for on leds
}