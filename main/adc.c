#include <avr/io.h>
#include <util/delay.h>
#include <Arduino.h>
//#include "AverageValue.h"

float computeVin (float t_in, int t_ref, float v_ref)
{
  return t_ref * (1.5 - v_ref) / t_in + 1.5;
}

float averageArray(int arr[])
{
  int sample_size = sizeof(arr);
  int sum = 0;
  float avg_meas;
  for(int j = 0; j < sample_size; j++)
  {
    sum = sum + arr[j];
  }
  avg_meas = ((float) sum) / sample_size;
  return avg_meas;
}


float takeVtpMeasurement(int sample_size, int cap_delay, int rstADC, int t_ref_final,
                       int v_toggle_pin, int adc_ext_int_pin)
{
  bool adc_ext_int;
  int t_ref = 0;
  int t_in = 0;
  int measurements [sample_size];
  for(int i = 0; i < sample_size; i++)
  {  
    adc_ext_int = 1;
    
    digitalWrite(v_toggle_pin, LOW);

    //Discharge capacitor
    digitalWrite(rstADC, 1);
    delayMicroseconds(cap_delay); 
    digitalWrite(rstADC, 0);


    //Start t_ref counter
    while(t_ref < t_ref_final)
    {
      t_ref++;
      delayMicroseconds(1);
    }
    t_ref = 0;

    //Select Vin to be input to integrator:
    digitalWrite(v_toggle_pin, HIGH);

    //count t_in
    while(adc_ext_int != 0)
    {
      t_in++;
      delayMicroseconds(1);
      adc_ext_int = digitalRead(adc_ext_int_pin); //Need to replace this logic with an interrupt or a faster digitalRead function
    }
    measurements[i] = t_in;
    t_in = 0;
  }

  //average the measurements array
  return averageArray(measurements);
}

