#include <Arduino.h>
#include "buttons.h"
#include "joystick.h"
#include "debug_logger.h"
#include "gamepad.h"

Buttons buttons;
Joystick leftStick;
DebugLogger logger;
Gamepad gamepad;

void setup() {
  logger.begin();
  buttons.begin();
  leftStick.begin(PIN_JOY_LX, PIN_JOY_LY);
  leftStick.calibrate();
  gamepad.begin();
}

void loop() {
  buttons.update();
  leftStick.update();
  gamepad.sendReport(buttons, leftStick);
  logger.logButtons(buttons);
  delay(10);
}
