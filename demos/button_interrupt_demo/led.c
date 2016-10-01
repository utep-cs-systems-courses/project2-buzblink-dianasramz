#include <msp430.h>
#include "led.h"

#define GREEN_LED BIT6
#define RED_LED BIT0
#define LEDS (RED_LED | GREEN_LED)

unsigned char leds_changed = 1;
unsigned char green_led_state;

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
}

void led_update(){
  if (leds_changed) {
    char ledFlags = 0; /* by default, no LEDs on */

    ledFlags |= green_led_state ? GREEN_LED : 0;
    ledFlags |= green_led_state ? 0 : RED_LED;

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  leds_changed = 0;
}

