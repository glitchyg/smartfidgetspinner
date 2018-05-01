// IdleAnimation.h

#ifndef _IDLEANIMATION_h
#define _IDLEANIMATION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Spinner.h"
#include "Settings.h"
#include "SPI.h"
#include "pt.h"

//-----------------------------------------------------------------------------------------------------------
static int IdleAnimationUpdate(pt * pt, SpinData * spinData)
{
  static unsigned long timestamp = 0;
  static unsigned long updateDelay;
  static unsigned long counter;

  PT_BEGIN(pt);

  // Calculate how long between each update
  updateDelay = 250000;

  // Define these here so we don't wast cyles
  static unsigned int byteIndex = 0;

  timestamp = micros();
  while (true) {
    for (byteIndex = 0; byteIndex < 254; byteIndex++) {
      digitalWrite(slaveSelectPin, LOW);
      SPI.transfer(counter); //Blue 
      SPI.transfer(0);
      SPI.transfer(0);
      digitalWrite(slaveSelectPin, HIGH);
      counter++;
      PT_WAIT_UNTIL(pt, ((micros() - timestamp) >= updateDelay) || micros() < timestamp); // 'micros() < timestamp' accounts for overflow
      timestamp = micros(); // Put it at the end so we can account for the loop of the next one in our timming.
    }
  }

  PT_END(pt);
}

#endif

