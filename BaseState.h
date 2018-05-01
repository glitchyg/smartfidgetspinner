// BaseState.h

#ifndef _BASESTATE_h
#define _BASESTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class StateManagerClass;

//-----------------------------------------------------------------------------------------------------------
class State {

protected:
  StateManagerClass *stateManager;

public:
  void Init(StateManagerClass *parentStateManager) {
    stateManager = parentStateManager;
  }
  virtual void Start() {};
  virtual void Update() {};
  virtual void End() {};
};


#endif

