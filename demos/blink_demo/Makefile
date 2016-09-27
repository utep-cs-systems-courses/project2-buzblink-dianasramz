# makfile configuration
COMMON_OBJECTS  = sr.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: blink.elf 

#additional rules for files
blink.elf: ${COMMON_OBJECTS} blinkMain.o stateMachines.o
	${CC} -mmcu=${CPU} -o $@ $^

install: blink.elf
	mspdebug rf2500 "prog blink.elf"

clean:
	rm -f *.o *.elf

#project dependencies
blinkMain.o: blinkMain.c

stateMachines.o: stateMachines.c

sr.o: sr.s