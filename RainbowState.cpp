// 
// 
// 

#include "RainbowState.h"
#include "Performace.h"
#include "RainbowAnimation.h"
#include "SpinTracker.h"
#include "Spinner.h"
#include "pt.h"

//RainbowAnimationClass rainbowAnimation;
pt rainbowStateAnimationProtoThread;

//-----------------------------------------------------------------------------------------------------------
void RainbowState::Start()
{
  PT_INIT(&rainbowStateAnimationProtoThread);
}

//-----------------------------------------------------------------------------------------------------------
void RainbowState::Update()
{
  SpinData *spinData = stateManager->GetSpinnner()->GetSpinTracker()->GetSpinData();
  if (spinData->spinning) {    
    RainbowAnimationUpdate2(&rainbowStateAnimationProtoThread, spinData);
  }

  if (spinData->spinnerIsIdle) {
    stateManager->ChangeState(IDLE_STATE);
  }
}

//-----------------------------------------------------------------------------------------------------------
void RainbowState::End()
{
  stateManager->GetSpinnner()->GetScreenDriver()->ClearDisplay();
}

