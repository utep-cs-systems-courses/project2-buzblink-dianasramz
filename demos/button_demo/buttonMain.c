#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"

void main(void) 
{  
  switch_init();
  led_init();

  or_sr(0x18);  // CPU off, GIE on
} 
