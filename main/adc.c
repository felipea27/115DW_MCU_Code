#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <Arduino.h>
#include "globalDefs.h"
//#include "AverageValue.h"

float computeVin (float t_in)
{
  return -(t_in) / ((float)t_ref_final / 1000000) * (v_ref - v_plus)  + v_plus;
}

float averageArray(unsigned short* arr)
{
  int sample_size = sizeof(arr);  //May be errors with byte sizes and arr being a pointer to array
  int sum = 0;
  float avg_meas;
  for(int j = 0; j < sample_size; j++)
  {
    sum = sum + arr[j];
  }
  avg_meas = ((float) sum) / sample_size;
  return avg_meas;
}

void takeVtpMeasurement(unsigned short* measurements, int sample_size)
{
  unsigned short t_ref = 0;
  unsigned short t_in;
  unsigned short startTimeTref;
  unsigned short startTimeTin;
  unsigned short endTimeTin;
  //unsigned short measurements [sample_size];
  for(int i = 0; i < sample_size; i++)
  {  
    compFlag = 1;
    
    //Discharge capacitor
    digitalWrite(RST_ADC, HIGH);
    delayMicroseconds(rc_delay);
    digitalWrite(V_TOGGLE, HIGH);
    delayMicroseconds(rc_delay); 
    digitalWrite(RST_ADC, LOW);


    //Start t_ref counter
    startTimeTref = micros();
    while(t_ref < t_ref_final)
    { 
      t_ref = micros() - startTimeTref;
    }
    t_ref = 0;

    //Select Vin to be input to integrator:
    digitalWrite(V_TOGGLE, LOW);

    //count t_in
    startTimeTin = micros();
    while(compFlag == 1)
    {
      /*
      t_in++;
      delayMicroseconds(15);
      adc_ext_int = digitalRead(adc_ext_int_pin); //Need to replace this logic with an interrupt or a faster digitalRead function
      //adc_ext_int = (PIND >> 2 & B00000100 >> 2);
      */
    }
    endTimeTin = micros();
    t_in = endTimeTin - startTimeTin;
    measurements[i] = t_in;
    t_in = 0;
  }




/*
void takeVtpMeasurement(unsigned short* measurements, int sample_size, int cap_delay, int rstADC, int t_ref_final,
                       int v_toggle_pin, int adc_ext_int_pin, volatile bool* adc_ext_int)
{
  int t_ref = 0;
  unsigned short t_in;
  unsigned short startTimeTref;
  unsigned short startTimeTin;
  unsigned short endTimeTin;
  //unsigned short measurements [sample_size];
  for(int i = 0; i < sample_size; i++)
  {  
    *adc_ext_int = 1;
    
    //Discharge capacitor
    digitalWrite(rstADC, 1);
    delayMicroseconds(cap_delay);
    digitalWrite(v_toggle_pin, LOW);
    delayMicroseconds(cap_delay); 
    digitalWrite(rstADC, 0);


    //Start t_ref counter
    startTimeTref = millis();
    while(t_ref < t_ref_final)
    { 
      t_ref = millis() - startTimeTref;
    }
    t_ref = 0;

    //Select Vin to be input to integrator:
    digitalWrite(v_toggle_pin, HIGH);

    //count t_in
    startTimeTin = micros();
    while(*adc_ext_int != 0)
    {
      
      t_in++;
      delayMicroseconds(15);
      adc_ext_int = digitalRead(adc_ext_int_pin); //Need to replace this logic with an interrupt or a faster digitalRead function
      //adc_ext_int = (PIND >> 2 & B00000100 >> 2);
      
    }
    endTimeTin = micros();
    t_in = endTimeTin - startTimeTin;
    measurements[i] = t_in;
    t_in = 0;
  }
*/
  //average the measurements array
  //return averageArray(measurements);
}

//Interrupt service routine of ADC_EXT_INT, pin32 -- INT0/PD2
//If ADC_EXT_INT goes low, then set adc_ext_int_flag to low


//CLK_IO is used for counters

