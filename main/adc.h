// header file for ADC functions
#include <avr/io.h>
#include <util/delay.h> 
#include <Arduino.h>



#ifndef ADC_INCLUDED
#define ADC_INCLUDED


float takeVtpMeasurement(int sample_size, int cap_delay, int rstADC, int t_ref_final, 
                       int v_toggle, int adc_ext_int_pin);

float computeVin(float t_in, int t_ref, float v_ref);

float averageArray(int arr[]);

#endif //ADC_H_INCLUDED
