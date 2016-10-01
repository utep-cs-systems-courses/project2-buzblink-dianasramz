#include <msp430.h>
#include "switches.h"
#include "led.h"
static char 
switch_set_interrupt_sense()
{
  char p1val = P1IN;
  /* update switch interrupt sensitivity */
  P1IES |= (p1val & SWITCHES);	/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */
  return p1val;
}

void 
switch_init()			/* setup switch */
{  
  P1REN |= SWITCHES;		/* enables resistors for switches */
  P1IE = SWITCHES;		/* enable interrupts from switches */
  P1OUT |= SWITCHES;		/* pull-ups for switches */
  P1DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_set_interrupt_sense();
  switch_interrupt_handler();	/* to initially read the switches */
}

void
switch_interrupt_handler()
{
  char p1val = switch_set_interrupt_sense();
  green_led_state = (p1val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  leds_changed = 1;
  led_update();
}
