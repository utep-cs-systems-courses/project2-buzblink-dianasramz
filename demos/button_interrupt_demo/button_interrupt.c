#include <msp430.h>
#include "buttons.h"

void led_control(){
  char ledFlags = 0; /* by default, no LEDs on */

  if(!((P2IN & (~P2IN | S1)) == S1)) // S1 pressed
    ledFlags = BIT0;    // red led

  if(!((P2IN & (~P2IN | S2)) == S2)) // S2 pressed
    ledFlags = BIT6;   // green led

  P1OUT &= (0xff-(BIT0+BIT6)) | ledFlags; // clear bits for off leds
  P1OUT |= ledFlags;         // set bits for on leds
}

/* Switches on P2 (S1 and S2) */
__interrupt(PORT2_VECTOR) Port_2(){
  led_control();
}