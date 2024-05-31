#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <Arduino.h>
#include "globalDefs.h"

#ifndef TESTING_FUNCTIONS_INCLUDED
#define TESTING_FUNCTIONS_INCLUDED

void testInterrupt(volatile bool* testBool);

#endif