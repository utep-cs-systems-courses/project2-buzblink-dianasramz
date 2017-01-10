#include <msp430.h>
#include "buzzer.h"
#include "led.h"

void decisecond() 
{
  static char cnt = 0;		/* # deciseconds/frequecy change */
  if (++cnt > 2) {		
    buzzer_advance_frequency();
    cnt = 0;
  }
}

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char second_count = 0, decisecond_count = 0;
  if (++second_count == 250) {
    led_toggle();
    second_count = 0;
  }
  if (++decisecond_count == 25) {
    buzzer_advance_frequency();
    decisecond_count = 0;
  }
  led_update();
}
