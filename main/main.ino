#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"
#include "adc.c"
#include "globalDefs.h"



const int sampleSize = 100;
bool take_measurement = 0;
bool comp_out = 1;
bool start_btn_flag = HIGH;
int avg_meas_time;
float avg_v_in;
//bool adc_int_flag = 1;


void setup() {
  // put your setup code here, to run once:
  //Declare pins as inputs
  pinMode(START_BTN_PIN, INPUT);
  pinMode(ADC_EXT_INT, INPUT);

  //Declare pins as outputs
  pinMode(RST_ADC, OUTPUT);
  pinMode(V_TOGGLE, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  start_btn_flag = digitalRead(START_BTN_PIN);
  if(start_btn_flag == LOW)
  {
    avg_meas_time = takeVtpMeasurement(sampleSize, cap_delay, RST_ADC, t_ref_final, V_TOGGLE, ADC_EXT_INT);
    avg_v_in = computeVin(avg_meas_time, t_ref_final, v_ref);
  }

  //start_btn_flag = HIGH;  manually set start_btn_flag to high to 
  
}


//REGISTER AND PORT CONFIGURATIONS:
//Configure PB6 for external clk input

//Configure PB7 for external clk input

//Configure PC0 to be an output pin, stays high and gets driven low upon activation. Enable pull up resistor

//Reset ADC -- drive PC0 low for 1 clk cycle

//Configure PC1 to be an output pin, stays low and gets driven high upon activation.

//Toggle ADC input -- drive PC1 high for a CLK cycle. 

//Configure PD2 to be an input (or interrupt) pin (experiment with timing on both)

//Configure PB0 to be an input pin

//Connect timer T0 to a certain CLK

//Prescale CLK to 1MHz

//Read PD2 pin

//Read PB0 pin


