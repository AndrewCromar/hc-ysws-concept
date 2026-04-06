#include <Arduino.h>
#include "buttons.h"
#include "debug_logger.h"

Buttons buttons;
DebugLogger logger;

void setup() {
  logger.begin();
  buttons.begin();
}

void loop() {
  buttons.update();
  logger.logButtons(buttons);
  delay(100);
}
