#include "msp430.h"
#include "delay.h"
#include "sound.h"
#include <stdlib.h>

#define LULLABY_LENGTH  50



void sound(struct note *, int);
struct note newNote(long, char, long);
struct note newRest(long);
void initalize_zeldasLullaby_1();
void initalize_zeldasLullaby_2();

static struct note *zeldasLullaby;

/* The following notes are the only ones used for this melody */
const struct note B_2_HALF = {_B, 2, HALF};
const struct note D_3_QUARTER = {_D, 3, QUARTER};
const struct note A_2_HALF = {_A, 2, HALF};
const struct note G_2_EIGHTH = {_G, 2, EIGHTH};
const struct note A_2_EIGHTH = {_A, 2, EIGHTH};
const struct note A_2_THREE = {_A, 2, 3*QUARTER};
const struct note A_3_HALF = {_A, 3, HALF};
const struct note G_3_QUARTER = {_G, 3, QUARTER};
const struct note D_3_HALF = {_D, 3, HALF};
const struct note C_3_EIGHTH = {_C, 3, EIGHTH};
const struct note B_2_EIGHTH = {_B, 2, EIGHTH};
const struct note D_4_SEVEN = {_D, 4, 7*QUARTER};
const struct note D_4_HALF = {_D, 4, HALF};
const struct note C_4_EIGHTH = {_C, 4, EIGHTH};
const struct note B_3_EIGHTH = {_B, 3, EIGHTH};
const struct note G_3_HALF = {_G, 3, HALF};
const struct note C_4_HALF = {_C, 4, HALF};
const struct note A_3_EIGHTH = {_A, 3, EIGHTH};
const struct note E_3_HALF = {_E, 3, HALF};
const struct note C_4_QUARTER = {_C, 4, QUARTER};
const struct note G_4_SIX = {_G, 4, 6*QUARTER};
const struct note REST_4 = {_C, 10, WHOLE};

int main() {
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

    zeldasLullaby = malloc(sizeof(struct note) * (LULLABY_LENGTH/2));
    while(1){
        initalize_zeldasLullaby_1();
        sound(zeldasLullaby, LULLABY_LENGTH/2);
        initalize_zeldasLullaby_2();
        sound(zeldasLullaby, LULLABY_LENGTH/2);
        // free(zeldasLullaby);
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

void initalize_zeldasLullaby_1(){
    zeldasLullaby[0] = B_2_HALF;
    zeldasLullaby[1] = D_3_QUARTER;

    zeldasLullaby[2] = A_2_HALF;
    zeldasLullaby[3] = G_2_EIGHTH;
    zeldasLullaby[4] =  A_2_EIGHTH;

    zeldasLullaby[5] = B_2_HALF;
    zeldasLullaby[6] = D_3_QUARTER;

    zeldasLullaby[7] = A_2_THREE;

    zeldasLullaby[8] = B_2_HALF;
    zeldasLullaby[9] = D_3_QUARTER;

    zeldasLullaby[10] = A_3_HALF;
    zeldasLullaby[11] = G_3_QUARTER;

    zeldasLullaby[12] = D_3_HALF;
    zeldasLullaby[13] = C_3_EIGHTH;
    zeldasLullaby[14] = B_2_EIGHTH;

    zeldasLullaby[15] = A_2_THREE;

    zeldasLullaby[16] = B_2_HALF;
    zeldasLullaby[17] = D_3_QUARTER;

    zeldasLullaby[18] = A_2_HALF;
    zeldasLullaby[19] = G_2_EIGHTH;
    zeldasLullaby[20] =  A_2_EIGHTH;

    zeldasLullaby[21] = B_2_HALF;
    zeldasLullaby[22] = D_3_QUARTER;

    zeldasLullaby[23] = A_2_THREE;

    zeldasLullaby[24] = B_2_HALF;
}

void initalize_zeldasLullaby_2(){
    //zeldasLullaby = malloc(sizeof(struct note) * (LULLABY_LENGTH/2));

    zeldasLullaby[0] = D_3_QUARTER;

    zeldasLullaby[1] = A_3_HALF;
    zeldasLullaby[2] = G_3_QUARTER;

    zeldasLullaby[3] = D_4_SEVEN;

    zeldasLullaby[4] = D_4_HALF;
    zeldasLullaby[5] = C_4_EIGHTH;
    zeldasLullaby[6] = B_3_EIGHTH;
    zeldasLullaby[7] = C_4_EIGHTH;
    zeldasLullaby[8] = B_3_EIGHTH;

    zeldasLullaby[9] = G_3_HALF;
    zeldasLullaby[10] = C_4_HALF;

    zeldasLullaby[11] = B_3_EIGHTH;
    zeldasLullaby[12] = A_3_EIGHTH;
    zeldasLullaby[13] = B_3_EIGHTH;
    zeldasLullaby[14] = A_3_EIGHTH;
    zeldasLullaby[15] = E_3_HALF;

    zeldasLullaby[16] = D_4_HALF;
    zeldasLullaby[17] = C_4_EIGHTH;
    zeldasLullaby[18] = B_3_EIGHTH;
    zeldasLullaby[19] = C_4_EIGHTH;
    zeldasLullaby[20] = B_3_EIGHTH;

    zeldasLullaby[21] = G_3_QUARTER;
    zeldasLullaby[22] = C_4_QUARTER;
    zeldasLullaby[23] = G_4_SIX;
    zeldasLullaby[24] = REST_4;
}