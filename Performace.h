#ifndef _PERFORMACE_h
#define _PERFORMACE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

static unsigned long measureMicrosStart;
static unsigned long measureMicrosEnd;
static unsigned long measureMicrosDelta;

#define START_MEASURE() measureMicrosStart = micros();
#define END_MEASURE() measureMicrosEnd = micros(); measureMicrosDelta = measureMicrosEnd - measureMicrosStart;
#define PRINT_MEASURED_TIME() Serial.println(measureMicrosDelta);

#endif