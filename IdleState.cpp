#include "IdleState.h"
#include "IdleAnimation.h"
#include "SpinTracker.h"
#include "Spinner.h"
#include "pt.h"

static struct pt idleStateAnimationProtoThread;

//-----------------------------------------------------------------------------------------------------------
void IdleState::Start()
{
  PT_INIT(&idleStateAnimationProtoThread);
}

//-----------------------------------------------------------------------------------------------------------
void IdleState::Update()
{
  SpinData *spinData = stateManager->GetSpinnner()->GetSpinTracker()->GetSpinData();
  IdleAnimationUpdate(&idleStateAnimationProtoThread, spinData);  
  if (spinData->spinning) {
    stateManager->GotoPreviousState();
  }
}

//-----------------------------------------------------------------------------------------------------------
void IdleState::End()
{
  stateManager->GetSpinnner()->GetScreenDriver()->ClearDisplay();
}
