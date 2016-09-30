# makfile configuration
COMMON_OBJECTS  = sr.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: buzzerBlink.elf 

#additional rules for files
buzzerBlink.elf: ${COMMON_OBJECTS} main.o blinkHandler.o buzzerHandler.o
	${CC} -mmcu=${CPU} -o $@ $^

install: buzzerBlink.elf
	mspdebug rf2500 "prog $^"

clean:
	rm -f *.o *.elf

#project dependencies
main.o: main.c

buzzerHandler.o: buzzerHandler.c

blinkHandler.o: blinkHandler.c
sr.o: sr.s
