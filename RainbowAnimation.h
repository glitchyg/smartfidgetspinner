// RainbowAnimation.h

#ifndef _RAINBOWANIMATION_h
#define _RAINBOWANIMATION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif


#include "Spinner.h"
#include "Settings.h"
#include "SPI.h"
#include "pt.h"

// Settings
const unsigned long rainbowLength = 128;
const unsigned long canvasSize = 256;



static int RainbowAnimationUpdate2(pt * pt, SpinData * spinData)
{
  static unsigned long timestamp = 0;
  static unsigned long updateDelay;

  PT_BEGIN(pt);

  if (!spinData->spinning || spinData->lastSpinTime == 0) {
    PT_EXIT(pt); //Early out if we are not spinning
  }

  // We can passgo at the start of a spin cycle
  if (spinData->passedGo) {
    spinData->passedGo = false; // Set to false so we don't early out
  }

  // Calculate how long between each update
  updateDelay = ((spinData->lastSpinTime) / canvasSize);

  // Define these here so we don't waste cyles
  static unsigned long rainbowIndex = 0;

  timestamp = micros();

  
  for (rainbowIndex = 0; rainbowIndex < 256; rainbowIndex++) {

    if (spinData->passedGo) {
      PT_EXIT(pt);
    }

    digitalWrite(slaveSelectPin, LOW);
    if (rainbowIndex <= 127) {
      SPI.transfer(B00011000); // Blue
      SPI.transfer(B00010110); // Green
      SPI.transfer(B00000011); // Red
    }
    else {
      digitalWrite(serReset, LOW);
      digitalWrite(serReset, HIGH);

      
      SPI.transfer(0);
      SPI.transfer(0);
      SPI.transfer(0);
      
    }
    digitalWrite(slaveSelectPin, HIGH);

    PT_WAIT_UNTIL(pt, ((micros() - timestamp) >= updateDelay) || spinData->passedGo || micros() < timestamp);

    timestamp = micros(); // Put it at the end so we can account for the loop of the next one in our timming.
  }

  //If we reach here lets mark as not spinning untill spintracker picks up that we are
  spinData->lastSpinTime = 0;


  PT_END(pt);
}


//-----------------------------------------------------------------------------------------------------------
static int RainbowAnimationUpdate(pt * pt, SpinData * spinData)
{
  static unsigned long timestamp = 0;
  static unsigned long updateDelay;

  PT_BEGIN(pt);

  if (!spinData->spinning || spinData->lastSpinTime == 0) {
    PT_EXIT(pt); //Early out if we are not spinning
  }

  // Calculate how long between each update
  updateDelay = ((spinData->lastSpinTime) / canvasSize);

  //Serial.println(spinData->lastSpinTime);
  //Serial.println(canvasSize);
  //Serial.println(updateDelay);

  // Define these here so we don't waste cyles
  static unsigned long rainbowIndex = 0;

  timestamp = micros();

  //static unsigned long startDrift = (timestamp - spinData->lastPassedGo);
  //static unsigned int driftCorrect = (startDrift / updateDelay);

  for (rainbowIndex = 0; rainbowIndex < canvasSize; rainbowIndex++) {
    digitalWrite(slaveSelectPin, LOW);
    if (rainbowIndex > rainbowLength) {
      SPI.transfer(B00011000); // Blue
      SPI.transfer(B00010110); // Green
      SPI.transfer(B00000011); // Red
    }
    else {
      SPI.transfer(0); // Blue
      SPI.transfer(0); // Green
      SPI.transfer(0); // Red
    }      
    digitalWrite(slaveSelectPin, HIGH);
    PT_WAIT_UNTIL(pt, ((micros() - timestamp) >= updateDelay) || micros() < timestamp);
    timestamp = micros(); // Put it at the end so we can account for the loop of the next one in our timming.
  }


  PT_END(pt);
}

#endif

