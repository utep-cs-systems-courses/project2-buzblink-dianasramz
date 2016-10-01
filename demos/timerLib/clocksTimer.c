#include <msp430.h>
#include "libTimer.h"

void configureClocks(){
  WDTCTL = WDTPW + WDTHOLD;//Disable Watchdog Timer
  BCSCTL1 = CALBC1_16MHZ;  // Set DCO to 16 Mhz
  DCOCTL = CALDCO_16MHZ;
    
  BCSCTL2 &= ~(SELS);     // SMCLK source = DCO
  BCSCTL2 |= DIVS_3;      // SMCLK = DCO / 8
}


// enable watchdog timer periodic interrupt
// period = SMCLOCK/32k
void enableWDTInterrupts()  
{
  WDTCTL = WDTPW |	     // passwd req'd.  Otherwise device resets
    WDTTMSEL |		     // watchdog interval mode 
    WDTCNTCL;		     // clear watchdog count
  IE1 |= WDTIE;		   // Enable watchdog interval timer interrupt
}


void timerAUpmode()
{
    TA0CCR0 = 0; // frequency timer
    TA0CCR1 = 0;
    TA0CTL = TASSEL_2 + MC_1 + ID_2; // SMCLK, upmode, /4
    TA0CCTL1 = OUTMOD_3;
    

    //    CCTL0 = CCIE;           // Timer A interrupt enabled
                // Timer A control:
                //  Timer clock source 2: system clock
    TACTL = TASSEL_2 + MC_1;      //  Mode Control 1: continuously 0...CCR0
    /*
  TA0CTL = TASSEL_2 + MC_1 + ID_2; // SMCLK, upmode, /4
  TACCTL0 = 0; //CCIE;           // Timer A interrupt enabled
  TACCTL1 = OUTMOD_3;
  TACCTL2 = 0; //CCIE;           // Timer A interrupt enabled
  // Timer A control:
  //  Timer clock source 2: system clock
  TACTL = TASSEL_2 + MC_1;      //  SMCLOCK, UP mode
    */
}


