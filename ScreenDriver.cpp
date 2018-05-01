// 
// 
// 

#include "ScreenDriver.h"
#include "Spinner.h"
#include "Settings.h"
#include "SPI.h"
#include "pt.h"

//-----------------------------------------------------------------------------------------------------------
void ScreenDriverClass::ClearDisplay() {
  digitalWrite(serReset, LOW);
  digitalWrite(serReset, HIGH);

  digitalWrite(slaveSelectPin, LOW);
  SPI.transfer(0);
  SPI.transfer(0);
  SPI.transfer(0);
  digitalWrite(slaveSelectPin, HIGH);
}

//-----------------------------------------------------------------------------------------------------------
void ScreenDriverClass::Init(SpinnerClass *spinnerParent)
{
  spinner = spinnerParent;

  //Set pin modes
  pinMode(slaveSelectPin, OUTPUT);
  pinMode(serReset, OUTPUT);

  SPI.begin();
  ClearDisplay();
}

void ScreenDriverClass::Update()
{
}
