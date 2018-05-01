// ScreenDriver.h

#ifndef _SCREENDRIVER_h
#define _SCREENDRIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

// Forward declares
class SpinnerClass;
class AnimationClass;
struct pt;

class ScreenDriverClass
{
 private:
   SpinnerClass *spinner;
   struct pt *driverThread;
   AnimationClass *currentAnimation;

 public:
   void ClearDisplay();
   void Init(SpinnerClass *spinner);
   void Update();
};

#endif

