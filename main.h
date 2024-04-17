#include <16F877A.h>
#device ADC=10
#use delay(crystal=4000000)
#FUSES NOWDT //No Watch Dog Timer
#FUSES HS //High speed Osc (> 4mhz for PCM/PCH) (>10mhz for PCD)
#FUSES NOBROWNOUT //No brownout reset
#FUSES NOLVP //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O



