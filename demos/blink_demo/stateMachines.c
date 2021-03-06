#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

char toggle_red()		/* always toggle! */
{ 
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

// My Changes

char toggle_red2()	  
{
  green_on = 0;
  
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    green_on = 1;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green2()
{
  static char state = 0;

  red_on = 0;
  
  switch (state) {
    case 0:
      green_on = 1;
      state = 1;
      break;
    case 1:
      green_on = 0;
      red_on = 1;
      state = 0;
      break;
    }
  return 1;
}


void state_advance1()		/* alternate between toggling red & green */
{
  char changed = 0;  

  static char state = 0;
  
  switch(state) {
   case 0: changed = toggle_red(); state = 1; break;
   case 1: changed = toggle_green(); state = 0; break;
  }

  led_changed = changed;
  led_update();
}

void state_advance2()		/* alternate between toggling red & green */
{
  char changed = 0;  

  static char state = 0;
  
  switch(state) {
   case 0: changed = toggle_red2(); state = 1; break;
   case 1: changed = toggle_green2(); state = 0; break;
  }

  led_changed = changed;
  led_update();
}

void state_advance()
{
  if(switch_state_down[0]) {
    state_advance1();
  }
  else if(switch_state_down[1]) {
    state_advance2();
  }
}

void state_advance_sl()
{
  if(switch_state_down[2]) {
    state_advance1();
  }
  else if(switch_state_down[3]) {
    state_advance2();
  }
}





