# makfile configuration
COMMON_OBJECTS  = blink.o config_clocks.o update_state.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: blink_c.elf 

#additional rules for files
blink_c.elf: ${COMMON_OBJECTS}
	${CC} -mmcu=${CPU} -o $@ $^

install_c: blink_c.elf
	mspdebug rf2500 "prog blink_c.elf"

clean:
	rm -f *.o *.elf

#project dependencies
blink.o: blink.c

config_clocks_.o: config_clocks_.c

led_c.o: led_c.c

update_state.o: update_state.c