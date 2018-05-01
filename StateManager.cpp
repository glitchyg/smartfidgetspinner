#include "StateManager.h"
#include "IdleState.h"
#include "RainbowState.h"

// States
IdleState idleState;
RainbowState rainbowState;

//-----------------------------------------------------------------------------------------------------------
void StateManagerClass::Init(SpinnerClass *spinnerParent)
{  
  // Set spinner
  spinner = spinnerParent;

  // Set Current State
  currentState = IDLE_STATE;
  previoseState = RAINBOW_STATE;

  // Init States
  idleState.Init(this);
  rainbowState.Init(this);

  // Setup states in list
  states[IDLE_STATE] = &idleState;
  states[RAINBOW_STATE] = &rainbowState;

  // Start the current State
  states[currentState]->Start();
}

//-----------------------------------------------------------------------------------------------------------
void StateManagerClass::ChangeState(StateType newState)
{
  // End the current state
  states[currentState]->End();

  // Save info on state change
  previoseState = currentState;
  currentState = newState;

  // Start the new state
  states[newState]->Start();
}

//-----------------------------------------------------------------------------------------------------------
void StateManagerClass::GotoPreviousState() {
  ChangeState(previoseState);
}

//-----------------------------------------------------------------------------------------------------------
void StateManagerClass::Update()
{
  states[currentState]->Update();
}

