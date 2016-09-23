#include <msp430.h>

// P1 connections:
//    P1.0 red led (1 = 0N)
//	P1.3 button (zero if down, needs resistor pull up)
//	P1.6 green led (1=ON)


void main(void) 
{  
  WDTCTL = WDTPW + WDTHOLD;	// Stop watchdog timer

  P1DIR = BIT0 + BIT6;	   	// bits attached to leds are output
  P1REN = BIT3;			// enable resistor for switch
  P1OUT = BIT3 + BIT0;		// pull up resistor for switch, red led on

  P1IE = BIT3;		   	// switch interrupt (bit 3) enabled
  P1IES = BIT3;		 	// switch interrupt high-low transition (wait for down)
  P1IFG &= ~BIT3;	   	// switch interrupt pending flag cleared
  or_sr(BIT5|BIT4|BIT3);	// OSC off (5) CPU off (4) , GIE (3)
} 



