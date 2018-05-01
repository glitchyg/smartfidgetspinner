// RainbowState.h

#ifndef _RAINBOWSTATE_h
#define _RAINBOWSTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "BaseState.h"

class RainbowState : public State {
public:
  void Start();
  void Update();
  void End();
};

#endif

