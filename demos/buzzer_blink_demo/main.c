#include <msp430.h>

void configureClocks(){
  BCSCTL1 = CALBC1_16MHZ;  // Set DCO to 16 Mhz
  DCOCTL = CALDCO_16MHZ;
    
  BCSCTL2 &= ~(SELS);     // SMCLK source = DCO
  BCSCTL2 |= DIVS_3;      // SMCLK = DCO / 8
}
 
int main() {
    configureClocks();

    // interacting with the watchdog always
    // requires sending WDTPW to the register
    // otherwise device is reset              
    WDTCTL = WDTPW |      // Watchdog password 
             WDTTMSEL |   // Set watchdog in interval mode 
             WDTCNTCL;    // Clear watchdog count


    IE1 |= WDTIE;                       // Enable WDT interrupt
    
    P2SEL &= ~(BIT6 | BIT7); // setup P2.6 & P2.7 as GPIO
    P2OUT &= ~BIT6;
    P2DIR = BIT6;
 
    P2SEL |= BIT6;   // buzzer TA0.1 - P2.6
    TA0CCR0 = 0; // frequency timer
    TA0CCR1 = 0;
    TA0CTL = TASSEL_2 + MC_1 + ID_2; // SMCLK, upmode, /4
    TA0CCTL1 = OUTMOD_3;
    

    CCTL0 = CCIE;           // Timer A interrupt enabled
                // Timer A control:
                //  Timer clock source 2: system clock
    TACTL = TASSEL_2 + MC_1;      //  Mode Control 1: continuously 0...CCR0
    CCR0 = 16000;         // Interrupt every 16,000 cycles (16MHz/16,000)

    P1DIR |= BIT6;        // BIT6 as output
    P1OUT &= ~BIT6;       // Turn off LED 
    
    or_sr(0x18);          // CPU off, GIE on
}
