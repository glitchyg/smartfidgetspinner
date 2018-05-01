#ifndef _STATEMANAGER_h
#define _STATEMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "BaseState.h"

// Forward declares
class SpinnerClass;

//-----------------------------------------------------------------------------------------------------------
enum StateType
{
  IDLE_STATE = 0,
  RAINBOW_STATE = 1
};

//-----------------------------------------------------------------------------------------------------------
class StateManagerClass
{
  public:
	  void Init(SpinnerClass *spinner);
    void ChangeState(StateType newState);
    void GotoPreviousState();
    void Update();
    SpinnerClass *GetSpinnner() {
      return spinner;
    }

  private:
    State *states[2];
    StateType currentState;
    StateType previoseState;
    SpinnerClass *spinner;
};

#endif

