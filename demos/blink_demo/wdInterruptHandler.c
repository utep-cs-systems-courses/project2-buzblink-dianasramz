#include <msp430.h>
#include "stateMachines.h"

__interrupt(WDT_VECTOR) WDT(){	/* 62.5 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count == 30) {
    state_advance();
    blink_count = 0;
  }
}
