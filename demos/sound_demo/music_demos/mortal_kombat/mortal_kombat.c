#include "msp430.h"
#include "sound.h"
#include "delay.h"
#include <stdlib.h>
 
void sound(struct note *, int);
struct note newNote(long, char, long);
struct note newRest(long);

const struct note A_2_QUARTER = {_A, 2, QUARTER};
const struct note C_3_QUARTER = {_C, 3, QUARTER};
const struct note D_3_QUARTER = {_D, 3, QUARTER};
const struct note E_3_QUARTER = {_E, 3, QUARTER};

const struct note G_3_QUARTER = {_G, 3, QUARTER};
const struct note G_2_QUARTER = {_G, 2, QUARTER};
const struct note B_2_QUARTER = {_B, 2, QUARTER};
const struct note F_3_QUARTER = {_F, 3, QUARTER};

struct note *mortal_kombat;
void initialize_melody1();

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
  
    mortal_kombat = malloc(sizeof(struct note) * 24);
    while (1) {
        initialize_melody1();
        //sound(mortal_kombat, 24);
    }
}
/* Takes in a pointer to an array of note structures and iterates through,
playing each note for the appropriate duration of time */
void sound(struct note *music, int size){
    char i;
    for(i = 0; i < size; i++){
        TA0CCR0 = (music+i)->pitch >> (music+i)->octave;
        TA0CCR1 = ((music+i)->pitch >> (music+i)->octave) >> 1;
        delay_cycles((music+i)->duration);

        TA0CCR0 = 0;
        TA0CCR1 = 0;
    }
}

/* Returns a note structure of desired pitch, octave, and duration */
struct note newNote(long pitch, char octave, long duration){
    struct note n = {pitch, octave, duration};
    return n;
}

/* Returns a structure representing a 'rest' of specified duration */
struct note newRest(long duration){
    struct note r = {C, 10, duration}; //inaudible
    return r;
}

void initialize_melody1(){
    mortal_kombat[0] = A_2_QUARTER;
    mortal_kombat[1] = A_2_QUARTER;
    mortal_kombat[2] = C_3_QUARTER;
    mortal_kombat[3] = A_2_QUARTER;
    mortal_kombat[4] = D_3_QUARTER;
    mortal_kombat[5] = A_2_QUARTER;
    mortal_kombat[6] = E_3_QUARTER;
    mortal_kombat[7] = D_3_QUARTER;

    mortal_kombat[8] = C_3_QUARTER;
    mortal_kombat[9] = C_3_QUARTER;
    mortal_kombat[10] = E_3_QUARTER;
    mortal_kombat[11] = C_3_QUARTER;
    mortal_kombat[12] = G_3_QUARTER;
    mortal_kombat[13] = C_3_QUARTER;
    mortal_kombat[14] = E_3_QUARTER;
    mortal_kombat[15] = C_3_QUARTER;

    mortal_kombat[16] = G_2_QUARTER;
    mortal_kombat[17] = G_2_QUARTER;
    mortal_kombat[18] = B_2_QUARTER;
    mortal_kombat[19] = G_2_QUARTER;
    mortal_kombat[20] = C_3_QUARTER;
    mortal_kombat[21] = G_2_QUARTER;
    mortal_kombat[22] = D_3_QUARTER;
    mortal_kombat[23] = C_3_QUARTER;
}