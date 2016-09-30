# arch1-project2
msp430 buzzer demo

# Description

This demo code demonstrates the buzzer and utilizes timer interrupts. The master clock is configured to 16 MHz and every 16,000 clock cycles, the timer interrupt handler is called. There is a preset frequency (10,000 MHz), that is incremented or decremented by one, depending on whether the frequency is in a state of going up or down. The result is an interesting sound. 