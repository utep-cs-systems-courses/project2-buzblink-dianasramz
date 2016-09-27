#include <msp430.h>
#include "buttons.h"

#define P2SwMask S1+S2

void main(void) {  
  WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
  P1DIR = BIT0 + BIT6;      // bits attached to leds are output

  P2REN |= P2SwMask;  /* resistors for switches */
  P2IE = P2SwMask;  /* enable interrupts from switches */
  P1OUT = 0; // leds start off
  or_sr(0x18);  // CPU off, GIE on
} 