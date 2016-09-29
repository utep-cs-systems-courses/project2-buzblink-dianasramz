#include <msp430.h>

static unsigned char red_led_state = 0;
static unsigned char count_red = 0;
static unsigned char green_led_state = 0;
static unsigned char count_green = 0;

void led_control(){
  count_red++;
  if(count_red >= 4){
    red_led_state = 1 - red_led_state;
    count_red = 0;
  }

  char ledFlags = 0;
  if(green_led_state)
    ledFlags |= BIT6;

  if(red_led_state)
    ledFlags |= BIT0;
  
  P1OUT &= (0xff-(BIT6+BIT0)) | ledFlags; // clear bit for off leds
  P1OUT |= ledFlags;        // set bit for on leds
}

__interrupt(TIMER0_A0_VECTOR) TIMER_A0(){
  count_green++;
  if(count_green >= 25){
    green_led_state = 1 - green_led_state;
    count_green = 0;
    led_control();
  }
}