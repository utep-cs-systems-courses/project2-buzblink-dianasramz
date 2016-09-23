#include <msp430.h>

static unsigned char red_led_state = 0;
static unsigned char count_red = 0;
static unsigned char green_led_state = 0;
static unsigned char count_green = 0;

void led_control();

void timerHandler(){
  count_red++;
  count_green++;

  if(count_red >= 100){
    red_led_state = 1 - red_led_state;
    count_red = 0;
    led_control();
  } 

  if(count_green >= 25){
    green_led_state = 1 - green_led_state;
    count_green = 0;
    led_control();
  }
}

void led_control(){
  char ledFlags = 0;
  if(green_led_state)
    ledFlags |= BIT0;
  if(red_led_state)
    ledFlags |= BIT6;
  P1OUT &= (0xff-(BIT6+BIT0)) | ledFlags; // clear bit for off leds
  P1OUT |= ledFlags;        // set bit for on leds
}