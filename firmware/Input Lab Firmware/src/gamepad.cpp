#include "gamepad.h"

static uint8_t const desc_hid_report[] = {
  TUD_HID_REPORT_DESC_GAMEPAD()
};

void Gamepad::begin() {
  _hid.setPollInterval(2);
  _hid.setReportDescriptor(desc_hid_report, sizeof(desc_hid_report));
  _hid.begin();

  while (!TinyUSBDevice.mounted()) {
    delay(1);
  }

  memset(&_report, 0, sizeof(_report));
}

void Gamepad::sendReport(Buttons& buttons) {
  if (!_hid.ready()) return;

  _report.buttons = 0;
  if (buttons.leftN)  _report.buttons |= (1 << 0);
  if (buttons.leftE)  _report.buttons |= (1 << 1);
  if (buttons.leftS)  _report.buttons |= (1 << 2);
  if (buttons.leftW)  _report.buttons |= (1 << 3);
  if (buttons.rightN) _report.buttons |= (1 << 4);
  if (buttons.rightE) _report.buttons |= (1 << 5);
  if (buttons.rightS) _report.buttons |= (1 << 6);
  if (buttons.rightW) _report.buttons |= (1 << 7);

  _report.x = 0;
  _report.y = 0;
  _report.z = 0;
  _report.rz = 0;
  _report.rx = 0;
  _report.ry = 0;
  _report.hat = GAMEPAD_HAT_CENTERED;

  _hid.sendReport(0, &_report, sizeof(_report));
}
