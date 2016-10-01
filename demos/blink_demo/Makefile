# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: blink.elf 

#additional rules for files
blink.elf: ${COMMON_OBJECTS} blinkMain.o stateMachines.o led.o wdInterruptHandler.c ../lib/libTimer.a
	${CC} -mmcu=${CPU} -o $@ $^

load: blink.elf
	mspdebug rf2500 "prog blink.elf"

clean:
	rm -f *.o *.elf

led.o: led.c led.h

wdInterruptHandler.o: stateMachines.h

stateMachines.o: led.h stateMachines.h
