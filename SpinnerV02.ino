#include "Spinner.h"

// the setup function runs once when you press reset or power the board
void setup() {
  spinner.Init();
}

// the loop function runs over and over again forever
void loop() {
  while (1) {
    spinner.Update();
  }
}
