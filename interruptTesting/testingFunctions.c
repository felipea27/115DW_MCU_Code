#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <Arduino.h>
#include "globalDefs.h"


void testInterrupt(volatile bool* testBool)
{
  //*testBool = 1;
  while(*testBool != 0)
  {

  }
}

