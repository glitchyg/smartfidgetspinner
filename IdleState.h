// IdleState.h

#ifndef _IDLESTATE_h
#define _IDLESTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "StateManager.h"

// Derived classes
class IdleState : public State {
public:
  void Start();
  void Update();
  void End();
};


#endif

