// Spinner.h

#ifndef _SPINNER_h
#define _SPINNER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Settings.h"
#include "StateManager.h"
#include "SpinTracker.h"
#include "ScreenDriver.h"

class SpinnerClass
{
public:
	void Init();
  void Update();

  StateManagerClass *GetStateManager() {
    return &stateManager;
  }

  SpinTrackerClass *GetSpinTracker() {
    return &spinTracker;
  }

  ScreenDriverClass *GetScreenDriver() {
    return &screenDriver;
  }

protected:
  StateManagerClass stateManager;
  SpinTrackerClass spinTracker;
  ScreenDriverClass screenDriver;
};

extern SpinnerClass spinner;


#endif

