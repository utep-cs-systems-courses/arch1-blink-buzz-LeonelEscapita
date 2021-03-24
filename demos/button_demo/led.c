#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  if (switch_state_changed && switch_state_down[0]) {
    char ledFlags = 0; /* by default, no LEDs on */

    ledFlags |= switch_state_down[0] ? LED_GREEN : 0;
    ledFlags |= switch_state_down[0] ? 0 : LED_RED;

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  
  if (switch_state_changed && switch_state_down[1]) {
    char ledFlags = 0; /* by default, no LEDs on */

    ledFlags |= switch_state_down[1] ? LED_GREEN : 0;
    ledFlags |= switch_state_down[1] ? LED_RED : 0;

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  
  if (switch_state_changed && switch_state_down[2]) {
    char ledFlags = 0; /* by default, no LEDs on */

    ledFlags |= switch_state_down[2] ? 0 : LED_GREEN;
    ledFlags |= switch_state_down[2] ? LED_RED : 0;

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  
  if (switch_state_changed && switch_state_down[3]) {
    char ledFlags = 0; /* by default, no LEDs on */

    ledFlags |= switch_state_down[3] ? 0 : LED_GREEN;
    ledFlags |= switch_state_down[3] ? 0 : LED_RED;

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  
  switch_state_changed = 0;
}

