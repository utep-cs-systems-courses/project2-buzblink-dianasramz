# Demo Makefile for lab 2-2.  
# Used for button interrupt driven demo
#
# @author Adrian Veliz
# @author Eric Freudenthal
# @version 0.1.20130910
#


# makfile configuration
COMMON_OBJECTS  = interrupts.o sr.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: a-button.elf 

#additional rules for files
a-button.elf: ${COMMON_OBJECTS} buttonIOA.o buttonMain.o
	${CC} -mmcu=${CPU} -o $@ $^

install: a-button.elf
	mspdebug rf2500 "prog a-button.elf"

clean:
	rm -f *.o *.elf


#project dependencies
buttonMain.o: buttonMain.c

buttonIOA.o: buttonIOA.c

interrupts.o: interrupts.s

sr.o: sr.s
