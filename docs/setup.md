# Firmware Setup Guide

How to go from nothing to a building PlatformIO project for the InputLab Controller.

## 1. Install VS Code

Download and install VS Code from https://code.visualstudio.com/

## 2. Install PlatformIO

1. Open VS Code
2. Go to Extensions (Ctrl+Shift+X)
3. Search for "PlatformIO IDE"
4. Click Install
5. Restart VS Code when prompted

## 3. Create a New Project

1. Click the PlatformIO icon in the sidebar (alien head)
2. Click "New Project" (or go to PIO Home > New Project)
3. Fill in:
   - **Name:** whatever you want
   - **Board:** search "Raspberry Pi Pico" — pick the one under "Raspberry Pi"
   - **Framework:** Arduino
   - **Location:** uncheck "Use default location" and select your `firmware/` folder
4. Click Finish — PlatformIO scaffolds the project

## 4. Configure platformio.ini

Open `firmware/platformio.ini` and replace the contents with:

```ini
[env:pico]
platform = https://github.com/maxgerhardt/platform-raspberrypi.git
board = rpipico
framework = arduino
board_build.core = earlephilhower
build_flags = -DUSE_TINYUSB
extra_scripts = post:copy_uf2.py
```

**Why these changes:**
- `platform` — The stock `raspberrypi` platform uses Arduino Mbed OS which doesn't support TinyUSB. The maxgerhardt fork provides the earlephilhower Arduino core.
- `board = rpipico` — The correct board ID for the earlephilhower core (not `pico`).
- `board_build.core = earlephilhower` — Explicitly selects the right Arduino core.
- `build_flags = -DUSE_TINYUSB` — Switches the USB stack from PicoSDK to TinyUSB for HID gamepad support.
- `extra_scripts` — Copies the built firmware.uf2 to the `production/` folder after each build.

**Important:** Do NOT add `Adafruit TinyUSB Library` to `lib_deps`. It is bundled inside the earlephilhower core and adding it separately causes duplicate symbol errors.

## 5. Install the Care Package

Download the care package and place the files in your project. (Details TBD)

This includes KiCad footprints/symbols and the firmware starter template.

## 6. Build

1. Click the checkmark icon in the PlatformIO toolbar (bottom bar) to build
2. First build takes ~1 minute as PlatformIO downloads the toolchain and libraries automatically
3. After a successful build, `production/firmware.uf2` is created automatically

## 7. Upload to Pico

**First time (or after changing VID/PID):**
1. Hold the BOOTSEL button on the Pico
2. Plug the Pico into USB while holding BOOTSEL
3. Release BOOTSEL — the Pico mounts as a USB drive
4. Click the Upload arrow in the PlatformIO toolbar (or run `pio run -t upload`)

**After first flash:**
Future uploads work directly over USB without BOOTSEL. The firmware runs as a composite USB device (HID gamepad + serial port), so PlatformIO can upload through the serial port while the gamepad is active.

## 8. Verify

- The Pico's LED should respond according to the firmware
- Open a gamepad tester website to see the controller
- Use the PlatformIO serial monitor (plug icon in toolbar, 115200 baud) for debug output
