# makfile configuration
COMMON_OBJECTS  = sr.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf 

#additional rules for files
button.elf: ${COMMON_OBJECTS} button_interrupt.o buttonMain.o
	${CC} -mmcu=${CPU} -o $@ $^

install: button.elf
	mspdebug rf2500 "prog button.elf"

clean:
	rm -f *.o *.elf

#project dependencies
buttonMain.o: buttonMain.c

button_interrupt.o: button_interrupt.c

sr.o: sr.s