//12 pre-defined pitches
#define _C 61156
#define _Db 57723
#define _D 54484
#define _Eb 51426
#define _E 48539
#define _F 45815
#define _Gb 43244
#define _G 40816
#define _Ab 38526
#define _A 36364
#define _Bb 34322
#define _B 32396

//120 BMP
#define FREQUENCY 16000000
#define QUARTER FREQUENCY/32
#define WHOLE QUARTER*4
#define HALF QUARTER*2
#define EIGHTH QUARTER/2
#define SIXTEENTH QUARTER/4

struct note {
  long pitch;
  char octave;
  long duration;
};