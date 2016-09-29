#include <msp430.h>
#include "buttons.h"

void led_control(){
  char ledFlags = 0; /* by default, no LEDs on */

  if(!((P1IN & (~P1IN | S2)) == S2)) // S1 pressed
    ledFlags = BIT0;    // red led

  P1OUT &= (0xff-(BIT0+BIT6)) | ledFlags; // clear bits for off leds
  P1OUT |= ledFlags;         // set bits for on leds
}

/* Switch on P1 (S2) */
__interrupt(PORT1_VECTOR) Port_1(){
  led_control();
}