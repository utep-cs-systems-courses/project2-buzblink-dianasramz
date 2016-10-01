#ifndef led_included
#define  led_included

void led_init();		/*  */
void led_update();		/* update leds */

extern unsigned char leds_changed, green_led_state;

#endif
