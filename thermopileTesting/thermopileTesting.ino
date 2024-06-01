#include <avr/io.h>
#include <avr/interrupt.h>
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


void setup() {
  pinMode(V_TH_PIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  vThermistor = measureVth();
  Serial.print(vThermistor);

}

