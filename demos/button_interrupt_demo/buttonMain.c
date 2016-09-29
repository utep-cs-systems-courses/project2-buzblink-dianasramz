#include <msp430.h>
#include "led_control.h"

#define P1SwMask BIT3

void main(void) {  
  WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
  P1DIR = BIT0 + BIT6;      // bits attached to leds are output

  P1REN |= P1SwMask;  /* resistors for switch */
  P1IE = P1SwMask;  /* enable interrupts from switch */
  P1OUT |= P1SwMask; /* pull-ups for switch */
  or_sr(0x18);  // CPU off, GIE on
  led_control();
} 
