// 
// 
// 

#include "Spinner.h"
#include "Performace.h"
#include "StateManager.h"
#include "chars.h" // Just adding this here temp to see program size


//-----------------------------------------------------------------------------------------------------------
void SpinnerClass::Init()
{  
  Serial.begin(9600);
  Serial.println("Spinner prototype v0.2");
  Serial.println("Created by Jason Morano");
  Serial.println("spinner@jason-morano.com");

  stateManager.Init(this);
  spinTracker.Init();
  screenDriver.Init(this);
}

//-----------------------------------------------------------------------------------------------------------
void SpinnerClass::Update()
{
  //START_MEASURE();
  spinTracker.Update();  
  stateManager.Update();  
  screenDriver.Update();
  //END_MEASURE();
  //PRINT_MEASURED_TIME();
}

//-----------------------------------------------------------------------------------------------------------
SpinnerClass spinner;