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

#define WHOLE DELAY
#define HALF DELAY/2
#define QUARTER DELAY/4
#define EIGTH DELAY/8
#define SIXTEENTH DELAY/16
#define THIRTYSECOND DELAY/32

 
const unsigned int notes[48] = { // 4 octaves
    C_0, Db_0, D_0, Eb_0, E_0, F_0, Gb_0, G_0, Ab_0, A_0, Bb_0, B_0, //
    C_0 >> 1, Db_0 >> 1, D_0 >> 1, Eb_0 >> 1, E_0 >> 1, F_0 >> 1, //
    Gb_0 >> 1, G_0 >> 1, Ab_0 >> 1, A_0 >> 1, Bb_0 >> 1, B_0 >> 1, //
    C_0 >> 2, Db_0 >> 2, D_0 >> 2, Eb_0 >> 2, E_0 >> 2, F_0 >> 2, //
    Gb_0 >> 2, G_0 >> 2, Ab_0 >> 2, A_0 >> 2, Bb_0 >> 2, B_0 >> 2, //
    C_0 >> 3, Db_0 >> 3, D_0 >> 3, Eb_0 >> 3, E_0 >> 3, F_0 >> 3, //
    Gb_0 >> 3, G_0 >> 3, Ab_0 >> 3, A_0 >> 3, Bb_0 >> 3, B_0 >> 3 //
};
 
const unsigned int whole_notes[28] = { // 4 octaves, no flats
    C_0, D_0, E_0, F_0, G_0, A_0, B_0, 
    C_0 >> 1, D_0 >> 1, E_0 >> 1, F_0 >> 1, 
    G_0 >> 1, A_0 >> 1, B_0 >> 1, 
    C_0 >> 2, D_0 >> 2, E_0 >> 2, F_0 >> 2, 
    G_0 >> 2, A_0 >> 2, B_0 >> 2, 
    C_0 >> 3, D_0 >> 3, E_0 >> 3, F_0 >> 3, 
    G_0 >> 3, A_0 >> 3, B_0 >> 3 
};

const unsigned int my_notes[84] = {
    C_0, D_0, E_0, F_0, G_0, A_0, B_0, 
    C_0 >> 1, D_0 >> 1, E_0 >> 1, F_0 >> 1, G_0 >> 1, A_0 >> 1, B_0 >> 1, 
    C_0 >> 2, D_0 >> 2, E_0 >> 2, F_0 >> 2, G_0 >> 2, A_0 >> 2, B_0 >> 2, 
    C_0 >> 3, D_0 >> 3, E_0 >> 3, F_0 >> 3, G_0 >> 3, A_0 >> 3, B_0 >> 3, 
    C_0 >> 4, D_0 >> 4, E_0 >> 4, F_0 >> 4, G_0 >> 4, A_0 >> 4, B_0 >> 4,
    C_0 >> 5, D_0 >> 5, E_0 >> 5, F_0 >> 5, G_0 >> 5, A_0 >> 5, B_0 >> 5,
    C_0 >> 6, D_0 >> 6, E_0 >> 6, F_0 >> 6, G_0 >> 6, A_0 >> 6, B_0 >> 6,
    B_0 >> 6, A_0 >> 6, G_0 >> 6, F_0 >> 6, E_0 >> 6, D_0 >> 6, C_0 >> 6,
    B_0 >> 5, A_0 >> 5, G_0 >> 5, F_0 >> 5, E_0 >> 5, D_0 >> 5, C_0 >> 5,
    B_0 >> 4, A_0 >> 4, G_0 >> 4, F_0 >> 4, E_0 >> 4, D_0 >> 4, C_0 >> 4,
    B_0 >> 3, A_0 >> 3, G_0 >> 3, F_0 >> 3, E_0 >> 3, D_0 >> 3, C_0 >> 3,
    B_0 >> 2, A_0 >> 2, G_0 >> 2, F_0 >> 2, E_0 >> 2, D_0 >> 2, C_0 >> 2,
    B_0 >> 1, A_0 >> 1, G_0 >> 1, F_0 >> 1, E_0 >> 1, D_0 >> 1, C_0 >> 1,
    B_0, A_0, G_0, F_0, E_0, D_0, C_0,
};
 
void sound(char, unsigned int, char);

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
    
    int c = 0;
    while (1) {
        if(c == 84) c = 0;
        __delay_cycles(100000);
        TA0CCR0 = my_notes[c];
        TA0CCR1 = my_notes[c] >> 1;
        c++;
    }
}