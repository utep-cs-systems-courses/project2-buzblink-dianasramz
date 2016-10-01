# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf 

#additional rules for files
button.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o led.o switches.o buttonMain.o ../lib/libTimer.a
	${CC} -mmcu=${CPU} -o $@ $^

load: button.elf
	mspdebug rf2500 "prog button.elf"

clean:
	rm -f *.o *.elf

