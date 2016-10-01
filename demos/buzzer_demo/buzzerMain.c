#include <msp430.h>
#include "buzzer.h"
 
int main() {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    configureClocks();
 
    buzzer_init();

    or_sr(0x18);          // CPU off, GIE on
}
