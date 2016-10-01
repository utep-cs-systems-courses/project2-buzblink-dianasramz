# arch1-project2
msp430 button interrupt demo

# Description

This program uses interrupts to detect when a switch is pressed or
released.

Press S1, and the green led is illuminated.  Releast it and the red
one is illuminated instead.

# Suggested exploratory projects

_LED toggle:_  A great initial project would be to modify this program to
implement a state machine that "toggled" between the red and green LED
each time the button is pressed, and kept that LED illuminated until
the next time the button was pressed.

_Separation of duties:_ Input and output are not always so closely
connected.  Frequently an input begins a computation that
eventually results in an output.  For example, pressing "next song" on
a streming audio player begins a complicated multi-stage process that
eventually results in a different song being played.   Suggestion: start
with someting simple such as respond to the buttons using interrupts, but
not directly updating the LEDS, instead just update a state variable.
The code to update the LEDs could be driven by periodic interrupt that
either flashes the red or green led based on the value of the button
state variables.   

