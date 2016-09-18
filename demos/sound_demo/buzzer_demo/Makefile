# makfile configuration
COMMON_OBJECTS  = buzzer.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: buzzer.elf 

#additional rules for files
buzzer.elf: ${COMMON_OBJECTS}
	${CC} -mmcu=${CPU} -o $@ $^

install_c: buzzer.elf
	mspdebug rf2500 "prog buzzer.elf"

clean:
	rm -f *.o *.elf

#project dependencies
buzzer.o: buzzer.c