#include <avr/io.h>
#include <util/delay.h>
#include <Arduino.h>
#include "globalDefs.h"
#include "adc.h"


float measureVth()
{
  int v_th_adc = analogRead(V_TH_PIN);
  float v_th = v_th_adc * (v_ref_int / 1023);
  return v_th_adc;
}

float avgVth(float* arrVth)
{
  int sample_size = sizeof(arrVth);
  float sum = 0;
  float avg_meas;
  for(int j = 0; j < sample_size; j++)
  {
    sum = sum + arrVth[j];
  }
  avg_meas = sum / sample_size;
  return avg_meas;
}


float r_thermistor(float averageVth)
{
  //return the thermistor resistance 
  return averageVth / i_bg;
}

float t_amb(float avgVth)
{
  
  //return some equation with r_thermistor(avgVth)
}