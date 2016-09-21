# makfile configuration
COMMON_OBJECTS  = zeldasLullaby.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: zeldasLullaby.elf 

#additional rules for files
zeldasLullaby.elf: ${COMMON_OBJECTS}
	${CC} -mmcu=${CPU} -o $@ $^

install: zeldasLullaby.elf
	mspdebug rf2500 "prog zeldasLullaby.elf"

clean:
	rm -f *.o *.elf

#project dependencies
zeldasLullaby.o: zeldasLullaby.c 
