#include <msp430.h>

unsigned char led_state = 0;
unsigned char count = 0;
unsigned char led_changed = 0;

void led_control();

void led_control(){
  if (1) {
	char ledFlags = 0;
	if(led_state)
		ledFlags |= BIT6;
	//P1OUT &= (0xff-(BIT6+BIT0)) | ledFlags; // clear bit for off leds
	P1OUT = ledFlags;        // set bit for on leds
	//P1OUT = BIT60;
	led_changed = 0;
  }
}

__interrupt(WDT_VECTOR) WDT(){

  count ++;
  if (count == 62) {
    led_state = 1 - led_state;
    led_changed = 1;
    count = 0;
  }
  led_control();
}

