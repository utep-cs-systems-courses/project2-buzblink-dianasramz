#include <libTimer.h>
#include <msp430.h>
#include "buzzer.h"		/* for setPeriod */
#include "led.h"		/* for led_control() */

int main() {
    configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
    
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
    buzzer_advance_frequency();
 
    /* setup green led */
    P1DIR |= BIT6;		/* Green LED (P1.6) for output */
    P1OUT &= ~BIT6;		/* Turn off green LED */
    led_update();

    enableWDTInterrupts();	/* enable wd timer */

    or_sr(0x18);		/* CPU off, GIE on */
}




