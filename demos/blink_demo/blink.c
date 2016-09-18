//Alternate LEDs from Off, Green, and Red

#include "msp430.h"
#include "config_clocks.h"
#include "update_state.h"

#define OFF 0
#define GREEN 1
#define RED 2

static unsigned char state = OFF;

int main(void) {
  WDTCTL = WDTPW + WDTHOLD; /* Disable Watchdog Timer */
  configureClocks();	
  P1DIR = BIT0 + BIT6; /* LED bits are for output */

  for (;;) {
    switch(state){
      case OFF:
        P1OUT = 0;
        break;
      case GREEN:
        P1OUT = BIT6;
        break;
      case RED:
        P1OUT = BIT0;
        break;
    } 
    state = update_state(state);
    __delay_cycles(1000000); /* Delay 1MHz clock speed 10^6 clock cycles, 1 sec */
  }
  return 0;
}