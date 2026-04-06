#pragma once

#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include "buttons.h"

class Gamepad {
public:
  void begin();
  void sendReport(Buttons& buttons);

private:
  Adafruit_USBD_HID _hid;
  hid_gamepad_report_t _report;
};
