// header file for ADC functions
#include <avr/io.h>
#include <util/delay.h> 
#include <Arduino.h>
//felipe


#ifndef ADC_INCLUDED
#define ADC_INCLUDED

void takeMeasurement(int measurement_array[], int samples, int cap_delay, int rstADC, int t_ref, int t_ref_final, int t_in, int v_toggle, int adc_ext_int_pin);

#endif //ADC_H_INCLUDED
