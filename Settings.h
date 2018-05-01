// Settings.h

#ifndef _SETTINGS_h
#define _SETTINGS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

const bool debugPrint = true;
const int slaveSelectPin = 4;
const int serReset = 6;
const unsigned long spinnerIdleTimeMicros = 2000000;


#endif

