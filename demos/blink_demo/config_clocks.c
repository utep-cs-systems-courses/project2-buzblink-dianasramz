/** 
 * Setup default clock speeds for msp430
 * 
 * @author Adrian Veliz
 * @author Eric Freudenthal
 * @version 0.1.20130815
 */
#include "msp430g2553.h"
void configureClocks() {
  // Set system DCO to 1MHz
  BCSCTL1 = CALBC1_1MHZ;
  DCOCTL = CALDCO_1MHZ;
  // Set LFXT1 to the VLO @ 12kHz
  BCSCTL3 |= LFXT1S_2;
}