#include <avr/io.h>
#include <util/delay.h>

#ifndef GLOBAL_DEFS_INCLUDED
#define GLOBAL_DEFS_INCLUDED

//Assign pin numbers variables
#define START_BTN_PIN (12)
#define DEGREE_BTN_PIN (13)
#define RST_PIN (29)
#define ADC_EXT_INT (32)

#define RST_ADC (23)
#define V_TOGGLE (24)

const int cap_delay = 1; //1uS
const int t_ref_final = 220; //220 uS
const float v_ref = 1.15;


#endif