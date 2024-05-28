#include <avr/io.h>
#include <util/delay.h>

#ifndef GLOBAL_DEFS_INCLUDED
#define GLOBAL_DEFS_INCLUDED

//Assign pin numbers variables
#define START_BTN_PIN (12)
#define DEGREE_BTN_PIN (13)
#define RST_PIN (29)
#define ADC_EXT_INT (32)
#define V_TH_PIN (26) //ADC3 of MCU

#define RST_ADC (23)
#define V_TOGGLE (24)

//Defining OLED constants:

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

//Define I2C pins and change/overrride them in either Wire.h or somewhere in our code

const int cap_delay = 1200; //1200 uS
const int t_ref_final = 10; //10 mS
const float v_ref = 1.15;
const float v_ref_int = 5.0;


#endif