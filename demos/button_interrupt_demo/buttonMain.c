#include <msp430.h>
#include "led.h"
#include "switches.h"

void main(void) {  
  WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
  led_init();

  switch_init();
  led_update();		/* important to initialize switches first! */

  or_sr(0x18);  // CPU off, GIE on
} 
