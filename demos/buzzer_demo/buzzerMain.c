#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "switches.h"

int main(void) {
    configureClocks();
    led_init();
    switch_init();
    buzzer_init();
    //buzzer_set_period(1000);
    enableWDTInterrupts();

    or_sr(0x18);          // CPU off, GIE on
}
