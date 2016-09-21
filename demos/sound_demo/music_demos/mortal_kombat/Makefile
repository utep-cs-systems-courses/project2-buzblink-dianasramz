# makfile configuration
COMMON_OBJECTS  = mortal_kombat.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: mortal_kombat.elf 

#additional rules for files
mortal_kombat.elf: ${COMMON_OBJECTS}
	${CC} -mmcu=${CPU} -o $@ $^

install_c: mortal_kombat.elf
	mspdebug rf2500 "prog mortal_kombat.elf"

clean:
	rm -f *.o *.elf

#project dependencies
mortal_kombat.o: mortal_kombat.c