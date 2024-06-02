#include <avr/io.h>
#include <util/delay.h> 
#include <Arduino.h>
#include "globalDefs.h"
#include "adc.h"



#ifndef V_THERM_INCLUDED
#define V_THERM_INCLUDED

//Set convert pin 26 -- PC3 to be an ADC input
//void setupADC(int adc_pin_number);

int analogReadOvrd(int pin);

float measureVth();
float avgVth(float* arrVth);
float r_thermistor(float averageVth);
float t_amb(float avgVth);

#endif //V_THERM_INCLUDED