#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"
#include "adc.c"

#define START_BTN_PIN (7)
//#define DEGREE_BTN_PIN (13)
//#define RST_PIN (29)
#define ADC_EXT_INT (8)

#define RST_ADC (12)
#define V_TOGGLE (13)

const int sampleSize = 100;
bool start_btn_flag = HIGH;
int avg_meas_time;
float avg_v_in;

const int cap_delay = 1; //1uS
const int t_ref_final = 220; //220 uS
const float v_ref = 1.15;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115000);
  pinMode(START_BTN_PIN, INPUT);
  pinMode(ADC_EXT_INT, INPUT);

  //Declare pins as outputs
  pinMode(RST_ADC, OUTPUT);
  pinMode(V_TOGGLE, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  start_btn_flag = digitalRead(7);
  if(start_btn_flag == LOW)
  {
    avg_meas_time = takeVtpMeasurement(sampleSize, cap_delay, RST_ADC, t_ref_final, V_TOGGLE, ADC_EXT_INT);
    avg_v_in = computeVin(avg_meas_time, t_ref_final, v_ref);
    Serial.print("Avg measurement time: ");
    Serial.println(avg_meas_time);
    Serial.print("Average Vin: ");
    Serial.println(avg_v_in);
  }
  Serial.println("Test complete");
}
