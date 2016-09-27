# arch1-project2
msp430 blink demo

# Description

This demo code illustrates timer interrupts, utilizing Timer A of the MSP430. The master clock of the MSP430 gets configured to 1MHz. Every 10,000 clock cycles, the timer interrupt handler is called and every second the green LED alternates between turning off and on. 