//Alternate LEDs from Off, Green, and Red

#include <msp430.h>

void configureClocks(void)    /* set master clock to 1MHz */
{ 
  BCSCTL1 = CALBC1_1MHZ;   // Set range 
  DCOCTL = CALDCO_1MHZ;    
  BCSCTL2 &= ~(DIVS_3);    // SMCLK = DCO / 8 = 1MHz 
} 

int main(void) {
  WDTCTL = WDTPW + WDTHOLD; /* Disable Watchdog Timer */
  configureClocks();	
  CCTL0 = CCIE;       // Timer A interrupt enabled
        // Timer A control:
        //  Timer clock source 2: system clock
  TACTL = TASSEL_2 + MC_1;      //  Mode Control 1: continuously 0...CCR0
  CCR0 = 10000;       // Interrupt every 10,000 cycles (1MHz/10,000)
  P1DIR = BIT0 + BIT6; /* LED bits are for output */

  or_sr(0x18);
  
  return 0;
}