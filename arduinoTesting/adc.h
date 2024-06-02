// header file for ADC functions
#include <avr/io.h>
#include <util/delay.h> 
#include <Arduino.h>



#ifndef ADC_INCLUDED
#define ADC_INCLUDED

float measureVtp();

void takeVtpMeasurement(unsigned short* measurements, int sample_size);
//void takeVtpMeasurement(unsigned short* measurements, int sample_size, int cap_delay, int rstADC, int t_ref_final, 
//                       int v_toggle, int adc_ext_int_pin, bool& adc_ext_int);

float computeVin(float t_in);

float averageArray(unsigned short* arr);

#endif //ADC_H_INCLUDED
