#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "globalDefs.h"


void testInterrupt(volatile bool* testBool)
{
  *testBool = 1;
  while(*testBool != 0)
  {

  }
  Serial.println("testBool changed to low, interrupt successfully triggered");
}

