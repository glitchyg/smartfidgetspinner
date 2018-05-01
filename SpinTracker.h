// SpinTracker.h

#ifndef _SPINTRACKER_h
#define _SPINTRACKER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

struct SpinData {
  unsigned long lastSpinTime = 0;
  unsigned long lastPassedGo = 0;
  bool spinning;  
  bool passedGo = false;
  bool spinnerIsIdle = false;
};

class SpinTrackerClass
{
 private:
   
   void PassedGo();
   bool passGoTriggered = false;

 public:   
  void TriggerFalling();
  void TriggerRising();  
  void Init();
  void Update();
  SpinData spinData;
  SpinData *GetSpinData() {
    return &spinData;
  }

};

extern SpinTrackerClass SpinTracker;

#endif

