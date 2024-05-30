// header file for ADC functions
#include <avr/io.h>
#include <util/delay.h> 
#include <Arduino.h>



#ifndef ADC_INCLUDED
#define ADC_INCLUDED

void takeVtpMeasurement(unsigned short* measurements, int sample_size, volatile bool* adc_ext_int);
//void takeVtpMeasurement(unsigned short* measurements, int sample_size, int cap_delay, int rstADC, int t_ref_final, 
//                       int v_toggle, int adc_ext_int_pin, bool& adc_ext_int);

float computeVin(float t_in, int t_ref, float v_ref, float v_pos_rail);

float averageArray(unsigned short* arr);

#endif //ADC_H_INCLUDED
