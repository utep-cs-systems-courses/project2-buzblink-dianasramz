#include <msp430.h>
#include "led_control.h"

#define GREEN_LED BIT6
#define RED_LED BIT0
unsigned char leds_changed = 1;
unsigned char green_led_state;

void led_control(){
  if (leds_changed) {
    char ledFlags = 0; /* by default, no LEDs on */

    ledFlags |= green_led_state ? GREEN_LED : 0;
    ledFlags |= green_led_state ? 0 : RED_LED;

    P1OUT &= (0xff-(BIT0+BIT6)) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  leds_changed = 0;
}

