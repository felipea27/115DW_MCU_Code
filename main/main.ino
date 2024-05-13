#include <avr/io.h>
#include <util/delay.h>

//Assign pin numbers variables
const int start_btn = 12;
const int degree_btn = 13;
const int reset = 29; 
const int adc_ext_int = 32;

const int rstADC = 23;
const int v_toggle = 24;

const int cap_delay = 1; //1uS
const int t_ref_final = 220; //220 uS
int t_ref = 0;  //Vref timer
int t_in = 0;   //Vin timer
bool take_measurement = 0;
bool comp_out = 1;
int i = 0;
int measurements [100];
bool start_btn_flag = HIGH;



void setup() {
  // put your setup code here, to run once:
  //Declare pins as inputs
  pinMode(start_btn, INPUT);
  pinMode(adc_ext_int, INPUT);

  //Declare pins as outputs
  pinMode(rstADC, OUTPUT);
  pinMode(v_toggle, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  start_btn_flag = digitalRead(start_btn);
  if(start_btn_flag == LOW)
  {
    for(; i < 100; i++)
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
      measurements[i] = t_in;
      t_in = 0;
    }
  }
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


