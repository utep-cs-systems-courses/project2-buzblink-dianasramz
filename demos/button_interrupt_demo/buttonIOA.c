#include <msp430.h>

// for button state machine
#define waitForUp 0
#define waitForDn 1

void led_control(void);

unsigned char buttonState = waitForDn;

static unsigned char red_counter = 0;

void btn_interrupt_handler()	/* called when p1 interrupt occurs - for buttons */
{
  if (buttonState == waitForUp) {	/* button is only input on P1, so don't need to check P1IN */
    buttonState = waitForDn;
    P1IES |= BIT3;		/* interrupt sensitive to button down */
  } else {			/* button UP */
    buttonState = waitForUp;
    P1IES &= ~BIT3;		/* interrupt sensitive to button up */
  }
  P1IFG &= ~BIT3;		/* clear interrupt */
  led_control();
}

void led_control()		/* not a state machine:
				   set LEDs from state variables */
{
  char ledFlags = 0;		/* by default, no LEDs on */
  if (buttonState == waitForDn)	     /* button is up (waiting for down) */
    ledFlags = BIT0;		     // red led  
  else 
    ledFlags = BIT6;		     // green led 
  P1OUT &= (0xff-(BIT0+BIT6)) | ledFlags; // clear bits for off leds
  P1OUT |= ledFlags;		     // set bits for on leds
}
