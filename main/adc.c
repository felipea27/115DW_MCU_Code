#include <avr/io.h>
#include <util/delay.h>
#include <Arduino.h>


void takeMeasurement(int measurement_array[], int samples, int cap_delay, int rstADC, int t_ref, int t_ref_final,
                      int t_in, int v_toggle, int adc_ext_int_pin)
{
  bool adc_ext_int;
  for(int i = 0; i < samples; i++)
  {
    {  
      adc_ext_int = 1;
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
      digitalWrite(v_toggle, HIGH);

      //count t_in
      while(adc_ext_int != 0)
      {
        t_in++;
        delayMicroseconds(1);
        adc_ext_int = digitalRead(adc_ext_int_pin); //Need to replace this logic with an interrupt or a faster digitalRead function
      }
      measurement_array[i] = t_in;
      t_in = 0;
    }
  }
  return;
}