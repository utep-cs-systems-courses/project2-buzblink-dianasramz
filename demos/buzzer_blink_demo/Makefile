# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS = ../lib/libTimer.a

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: buzzerBlink.elf 

#additional rules for files
buzzerBlink.elf: ${COMMON_OBJECTS} main.o led.o buzzer.o wdInterruptHandler.o ../lib/libTimer.a
	${CC} $(CFLAGS) $^ $(LDFLAGS) -o $@ 

install: buzzerBlink.elf
	mspdebug rf2500 "prog $^"

clean:
	rm -f *.o *.elf

