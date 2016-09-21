#include "msp430.h"
 
#define C_0 61156
#define Db_0 57723
#define D_0 54484
#define Eb_0 51426
#define E_0 48539
#define F_0 45815
#define Gb_0 43244
#define G_0 40816
#define Ab_0 38526
#define A_0 36364
#define Bb_0 34322
#define B_0 32396

// 120 BPM
#define DELAY 16000000

#define WHOLE DELAY/2
#define HALF DELAY/4
#define QUARTER DELAY/8
#define EIGTH DELAY/8
#define SIXTEENTH DELAY/32
#define THIRTYSECOND DELAY/3264

 
const unsigned int whole_notes[28] = { // 4 octaves, no flats
    C_0, D_0, E_0, F_0, G_0, A_0, B_0, 
    C_0 >> 1, D_0 >> 1, E_0 >> 1, F_0 >> 1, 
    G_0 >> 1, A_0 >> 1, B_0 >> 1, 
    C_0 >> 2, D_0 >> 2, E_0 >> 2, F_0 >> 2, 
    G_0 >> 2, A_0 >> 2, B_0 >> 2, 
    C_0 >> 3, D_0 >> 3, E_0 >> 3, F_0 >> 3, 
    G_0 >> 3, A_0 >> 3, B_0 >> 3 
};
 
void sound(char, unsigned int, char);

/* Plays a snippet of the song from Midway Games' game Mortal Kombat */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    BCSCTL1 = CALBC1_16MHZ; // Set DCO clock to 16MHz
    DCOCTL = CALDCO_16MHZ;
 
    P2SEL &= ~(BIT6 | BIT7); // setup P2.6 & P2.7 as GPIO
    P2OUT &= ~BIT6;
    P2DIR = BIT6;
 
    P2SEL |= BIT6;   // buzzer TA0.1 - P2.6
    TA0CCR0 = 0; // frequency timer
    TA0CCR1 = 0;
    TA0CTL = TASSEL_2 + MC_1 + ID_2; // SMCLK, upmode, /4
    TA0CCTL1 = OUTMOD_3;
  
    while (1) {
        char d = 'q';
        char i;

        for(i=0; i < 2; i++){
            sound('a', 2, d);
            sound('a', 2, d);
            sound('c', 3, d);
            sound('a', 2, d);
            sound('d', 3, d);
            sound('a', 2, d);
            sound('e', 3, d);
            sound('d', 3, d);

            sound('c', 3, d);
            sound('c', 3, d);
            sound('e', 3, d);
            sound('c', 3, d);
            sound('g', 3, d);
            sound('c', 3, d);
            sound('e', 3, d);
            sound('c', 3, d);

            sound('g', 2, d);
            sound('g', 2, d);
            sound('b', 2, d);
            sound('g', 2, d);
            sound('c', 3, d);
            sound('g', 2, d);
            sound('d', 3, d);
            sound('c', 3, d);

            sound('f', 2, d);
            sound('f', 2, d);
            sound('a', 2, d);
            sound('f', 2, d);
            sound('c', 3, d);
            sound('f', 2, d);
            sound('b', 2, d);
            sound('c', 3, d);
       }
        sound('a', 2, 'e');
        sound('r', 2, 'q');
        sound('a', 2, 'e');
        sound('r', 2, 'q');
        sound('a', 2, 'e');
        sound('r', 2, 'q');
        sound('a', 2, 'e');
        sound('r', 2, 'q');
        sound('g', 2, 'q');
        sound('b', 2, 'q');

        sound('a', 2, 'e');
        sound('r', 2, 'q');
        sound('a', 2, 'e');
        sound('r', 2, 'q');
        sound('a', 2, 'e');
        sound('r', 2, 'q');
        sound('a', 2, 'e');
        sound('r', 2, 'q');
        sound('g', 2, 'q');
        sound('d', 2, 'q');

        sound('a', 2, 'e');
        sound('r', 2, 'q');
        sound('a', 2, 'e');
        sound('r', 2, 'q');
        sound('a', 2, 'e');
        sound('r', 2, 'q');
        sound('a', 2, 'e');
        sound('r', 2, 'q');
        sound('g', 2, 'q');
        sound('b', 2, 'q');

        sound('a', 2, 'e');
        sound('r', 2, 'q');
        sound('a', 2, 'e');
        sound('r', 2, 'q');
        sound('a', 2, 'e');
        sound('r', 2, 'e');
        sound('a', 2, 's');
        sound('r', 2, 'e');
        sound('a', 2, 's');
        sound('r', 2, 'e');
        sound('a', 2, 's');
        sound('r', 2, 'e');
        sound('a', 2, 's');
        sound('r', 2, 'q');
        
        sound('r', 2, 'w');
    }
}

/* This function takes in a note, musical A-G, at a specific octave
    and duration, from a 32nd note to a whole note, and outputs sound.
    Char 'r' is reserved for rests, or no sound */
void sound(char note, unsigned int octave, char duration){
    switch(note){
        case 'c':
            TA0CCR0 = whole_notes[0 + 7*octave];
            TA0CCR1 = whole_notes[0+7*octave] >> 1;
            break;

        case 'd':
            TA0CCR0 = whole_notes[1 + 7*octave];
            TA0CCR1 = whole_notes[1 + 7*octave] >> 1;
            break;

        case 'e':
            TA0CCR0 = whole_notes[2 + 7*octave];
            TA0CCR1 = whole_notes[2 + 7*octave] >> 1;
            break;

        case 'f':
            TA0CCR0 = whole_notes[3 + 7*octave];
            TA0CCR1 = whole_notes[3 + 7*octave] >> 1;
            break;

        case 'g':
            TA0CCR0 = whole_notes[4 + 7*octave];
            TA0CCR1 = whole_notes[4 + 7*octave] >> 1;
            break;

        case 'a':
            TA0CCR0 = whole_notes[5 + 7*octave];
            TA0CCR1 = whole_notes[5 + 7*octave] >> 1;
            break;

        case 'b':
            TA0CCR0 = whole_notes[6 + 7*octave];
            TA0CCR1 = whole_notes[6 + 7*octave] >> 1;
            break;

        case 'r':
            TA0CCR0 = B_0 >> 10; //inaudible, used for rests
            TA0CCR1 = B_0 >> 1;
            break;
    }
    
    if(duration == 'w') __delay_cycles(WHOLE);
    else if(duration == 'h') __delay_cycles(HALF);
    else if(duration == 'q') __delay_cycles(QUARTER);
    if(duration == 'e') __delay_cycles(EIGTH);
    if(duration == 's') __delay_cycles(SIXTEENTH);
    if(duration == 't') __delay_cycles(THIRTYSECOND);
    
    TA0CCR0 = B_0 >> 10;
    TA0CCR1 = B_0 >> 1;
}