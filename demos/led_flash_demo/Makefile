# Demo Makefile for old lab assignment lab 2-2.  
# Used for LED-flash tutorial
# 
# @author Adrian Veliz
# @author Eric Freudenthal
# @version 0.1.20130910
#


# makfile configuration
COMMON_OBJECTS	= interrupts.o sr.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: flash.elf 

#additional rules for files
flash.elf: ${COMMON_OBJECTS} flashMain.o stateMachines.o
	${CC} -mmcu=${CPU} -o $@ $^

install: flash.elf
	mspdebug rf2500 "prog flash.elf"

clean:
	rm -f *.o *.elf


#project dependencies
flashMain.o: flashMain.c

stateMachines.o: stateMachines.c

interrupts.o: interrupts.s

sr.o: sr.s
