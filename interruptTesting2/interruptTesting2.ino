#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <Arduino.h>
#include "globalDefs2.h"
#include "testFunctions2.h"
#include "testFunctions2.c"

volatile bool compFlag = 1;

void setup() {
  // put your setup code here, to run once
  
  //Declare pins as inputs
  pinMode(ADC_EXT_INT, INPUT);
  attachInterrupt(digitalPinToInterrupt(ADC_EXT_INT), ISR_adcExtInt, FALLING);

  Serial.begin(9600);

  Serial.println("comparator value before interrupt: ");
  Serial.println(compFlag);

}

void loop() {
  testInterrupt();

  Serial.print("Interrupt triggered, new compFlag: ");
  Serial.println(compFlag);
}

void ISR_adcExtInt()
{
  compFlag = 0;
}

//REGISTER AND PORT CONFIGURATIONS:
//Configure PB6 for external clk input

//Configure PB7 for external clk input

//Configure PC0 to be an output pin, stays high and gets driven low upon activation. Enable pull up resistor

//Reset ADC -- drive PC0 low for 1 clk cycle

//Configure PC1 to be an output pin, stays low and gets driven high upon activation.

//Toggle ADC input -- drive PC1 high for a CLK cycle. 

//Configure PD2 to be an input (or interrupt) pin (experiment with timing on both)
//Need to set PD2 to 0: DDRD |= 0000000;

//Configure PB0 to be an input pin

//Connect timer T0 to a certain CLK

//Prescale CLK to 1MHz

//Read PD2 pin

//Read PB0 pin
/*
void setupTC0()
{
  //set TC0 register to correct timer prescale
  //In the TCCR0B register
  //CS0 = //desired prescalar, bottom 3 bits of TCCR0B register.

  001 -> no prescalar
  010 -> clk_io / 8
  011 -> clk_io / 64
  100 -> clk_io / 256
  101 0> clk_io / 1024


//Set the value of the OCR0A to the overflow value of TC0

  //Enable interrupt that corresponds to OCF0A flag. 
    // Set the OCIE0A [1] bit to 1 in the TIMSK0 register to high.
    // Also need to set the I bit in the status I register to 1
  TIMSK0 |= 0x02; //Set the second bit to high
  sei();
  

  //OCF0A flag goes up when TCNT0 goes to 0x00, so OCF0A becomes high when timer is at Tclk * (OCR0A + 1)
  //TOV0 goes up when TC0 overflows, gets cleared with the timer interrupt
}

void enableTC0()
{
  //Minimizing Power consumption register (PRR0), PRTIM0 bit = 0
  //TCNT0 = timer T0 value, this is an 8 bit register

  //OCR0A = timer max number <-- sets the maximum value of the timer. Default is MAX = 255
}
*/
