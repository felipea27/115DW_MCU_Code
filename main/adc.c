#include <avr/io.h>
#include <util/delay.h>
#include <Arduino.h>
#include "adc.h"


void takeMeasurement(int measurement_array[], int samples, int cap_delay, int rstADC, int t_ref, int t_in, int v_toggle, int adc_ext_int)
{
  for(int i = 0; i < samples; i++)
  {
    {  
      //Discharge capacitor
      digitalWrite(rstADC, 1);
      delayMicroseconds(cap_delay); 
      digitalWrite(rstADC, 0);
      //Start t_ref counter
      while(t_ref < 220)
      {
        t_ref++;
        delayMicroseconds(1);
      }
      t_ref = 0;

      //Select Vin to be input to integrator:
      digitalWrite(v_toggle, HIGH);

      //count t_in
      while(adc_ext_int != 0)
      {
        t_in++;
        delayMicroseconds(1);
      }
      measurement_array[i] = t_in;
      t_in = 0;
    }
  }
  return;
}