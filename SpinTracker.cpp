// 
// 
// 

#include "SpinTracker.h"
#include "Spinner.h"

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void pciSetup(byte pin)
{
  *digitalPinToPCMSK(pin) |= bit(digitalPinToPCMSKbit(pin));  // enable pin
  PCIFR |= bit(digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
  PCICR |= bit(digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
ISR(PCINT1_vect) { // handle pin change interrupt for A0 to A5 here
  if (analogRead(A3) > 512) { // Falling edge
    spinner.GetSpinTracker()->TriggerFalling();
  } else { // Rising Edge
    spinner.GetSpinTracker()->TriggerRising();
  }
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SpinTrackerClass::TriggerFalling() {
  passGoTriggered = true;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SpinTrackerClass::TriggerRising() {
  spinData.spinning = false;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SpinTrackerClass::PassedGo() {
  unsigned long currentMicros = micros();
  unsigned long timePassed = currentMicros - spinData.lastPassedGo;

  if (spinData.lastPassedGo > 0 && timePassed < spinnerIdleTimeMicros) {
    spinData.lastSpinTime = timePassed;
  } else {
    spinData.lastSpinTime = 0;
  }

  spinData.passedGo = true;
  spinData.spinning = true;
  spinData.spinnerIsIdle = false;
  spinData.lastPassedGo = currentMicros;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SpinTrackerClass::Init()
{
  pciSetup(A3); // Setup analog intrupt
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void SpinTrackerClass::Update()
{
  bool fake = true;

  if (passGoTriggered) {
    PassedGo();
    passGoTriggered = false;
  }

  unsigned long currentMicros = micros();
  unsigned long timePassed = currentMicros - spinData.lastPassedGo;
  if (timePassed > spinnerIdleTimeMicros) {
    spinData.spinnerIsIdle = true;
    spinData.spinning = false;
  }
  else {
    spinData.spinnerIsIdle = false;
  }

}
