# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: buzzer.elf 

#additional rules for files
buzzer.elf: ${COMMON_OBJECTS} buzzer.o toggle_green.o buzzerMain.o stateMachines.o led.o switches.o p2_interrupt_handler.o wdInterruptHandler.o ../lib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^

load: buzzer.elf
	msp430loader.sh  $^

clean: $^
	rm -f *.o *.elf

buzzer.c: buzzer.h
buzzerMain.c: buzzer.h

led.o: led.c led.h

toggle_green.o: toggle_green.s stateMachines.h

wdInterruptHandler.o: stateMachines.h

p2_interrupt_handler.o: switches.h

stateMachines.o: led.h stateMachines.h

switches.o: led.h switches.h
