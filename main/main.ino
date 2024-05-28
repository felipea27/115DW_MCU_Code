#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"
#include "adc.c"
#include "globalDefs.h"
#include "v_therm.h"

//Libraries for OLED communication:
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Create a display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int sampleSize = 100;
bool start_btn_flag = HIGH;
int avg_meas_time;
float avg_v_in;
float vThermistor = 0;
//bool adc_int_flag = 1;


void setup() {
  // put your setup code here, to run once:
  //Declare pins as inputs
  pinMode(START_BTN_PIN, INPUT);
  pinMode(ADC_EXT_INT, INPUT);
  pinMode(V_TH_PIN, INPUT);

  //Declare pins as outputs
  pinMode(RST_ADC, OUTPUT);
  pinMode(V_TOGGLE, OUTPUT);

  //Enable interrupts:
  //D7 bit of SREG (status register) enables all interrupts globally
  //Set D7 of SREG HIGH
  //Set relavent bit for interrupt pin in TIMSK register

  //Setup I2C connection with OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.display();
  delay(2000); // Pause for 2 seconds
  // Clear the buffer
  display.clearDisplay();
  display.setTextSize(1);                                  //Display the average BPM next to it
  display.setTextColor(WHITE); 
  display.setCursor(5, 15);
  display.println("Connecting with display");
  display.display();
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

  vThermistor = measureVth();

  start_btn_flag = digitalRead(START_BTN_PIN);
  if(start_btn_flag == LOW)
  {
    avg_meas_time = takeVtpMeasurement(sampleSize, cap_delay, RST_ADC, t_ref_final, V_TOGGLE, ADC_EXT_INT);
    avg_v_in = computeVin(avg_meas_time, t_ref_final, v_ref);
  }
  display.println("Average Vin: ");
  display.println(avg_v_in);
  display.clearDisplay();
  //start_btn_flag = HIGH;  manually set start_btn_flag to high 
  
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


