# Andrew's Hack Club YSWS Idea

Build your own video game controller.

## Core Idea

Students design, build, and program a custom video game controller from scratch. The program walks teens through three disciplines: PCB design, 3D CAD modeling, and embedded firmware development in C++.

### What students do:

1. **PCB Design** — Using KiCad, students design a custom circuit board for their controller using a fixed set of provided components (RP2040 microcontroller, buttons, joysticks, LEDs, USB-C connector). They learn schematic capture and PCB layout.
2. **3D CAD** — Students design a 3D-printed enclosure for their controller and PCB using FreeCAD or Fusion360.
3. **Firmware** — Students write C++ firmware (Arduino framework + TinyUSB) to make their controller work as a USB HID gamepad. This includes: button reading and debouncing, analog stick calibration and mapping, LED feedback/effects, and USB HID report handling.
4. **Ship it** — Students submit their designs. The program manufactures PCBs, 3D prints cases, and ships parts kits for assembly. Students assemble, test, and publish their project.

## Technical Stack

- **Microcontroller:** RP2040-based board (e.g. Raspberry Pi Pico or Waveshare RP2040-Zero)
- **Firmware:** C++ using Arduino framework (earlephilhower's arduino-pico core) + TinyUSB for HID gamepad emulation
- **PCB Design:** KiCad
- **CAD:** FreeCAD or Fusion360

### Why C++ over CircuitPython?

CircuitPython's `adafruit_hid` library has limited gamepad support — no proper XInput/DirectInput, fragile boot-time report descriptor configuration, and poor customization. TinyUSB (used in C++) has mature, full-featured HID gamepad support with complete control over USB descriptors. The Arduino framework keeps it approachable for beginners while teaching real embedded development.

## Kit & Budget (~$5/hr)

Students work with a **fixed component list** to keep costs predictable. Parts are sourced in bulk for 50 students.

| Item | Per-student cost |
|---|---|
| RP2040 board (e.g. Waveshare RP2040-Zero) | ~$3 |
| Buttons (8-12x tactile/micro switches) | ~$2 |
| Joystick(s) (analog thumbstick module) | ~$2 |
| USB-C connector + cable | ~$1 |
| LEDs + resistors | ~$1 |
| Custom PCB (batch fab via JLCPCB) | ~$3 |
| 3D printed case | ~$3 |
| Misc (headers, wires, screws) | ~$2 |
| Shipping | ~$8 |
| **Total per student** | **~$25** |

At ~$25/student and an expected 5+ hours of tracked technical work per student, that's **~$5/hr** in program spend per student.

## Hour Tracking

- **Firmware coding** — Tracked via Hackatime (IDE plugin tracks active coding time)
- **PCB design & CAD work** — Tracked via Lapse (supports hardware/design time tracking, integrates with Hackatime)

Expected time breakdown per student:
- PCB design: ~2 hours
- CAD modeling: ~1.5 hours
- Firmware development: ~3 hours
- Assembly & testing: ~1 hour

## "Shipped Project" = Live URL + Open Source

Every completed project must have:
- A **public GitHub repo** with organized folders: `firmware/`, `pcb/`, `cad/`, `assets/`, `production/`, and a `README.md`
- A **project page** on the program's gallery website (built by me) with photos, description, and links
- A **ship post** on the Hack Club Slack

The GitHub repo is the open source code. The gallery page is the live URL.

## Signup Plan (Outside Hack Club)

- **Gaming/controller modding communities** — Reddit (r/fightsticks, r/controllers, r/customcontrollers), controller modding Discord servers
- **Maker/electronics communities** — Reddit (r/arduino, r/electronics, r/raspberrypipico), Maker Discord servers
- **Short-form video** — TikTok/YouTube Shorts showing a controller being built from scratch (PCB design timelapse, soldering, first button press)
- **School robotics and electronics clubs** — Direct outreach to club leaders
- **Word of mouth** — Each participant shares their ship post, attracting friends and peers

Target: 50 teens (ages 18 and under).

## Detailed Instructions & Support

The program provides step-by-step guides for each phase:
- KiCad tutorial: schematic capture and PCB layout with the fixed component set
- CAD tutorial: designing an enclosure around the PCB
- Firmware tutorial: Arduino setup, TinyUSB HID configuration, button/stick reading, debouncing, LED control
- Assembly guide: soldering, testing, troubleshooting

A starter firmware template handles USB initialization and HID report descriptors. Students implement the actual controller logic.

## Bonus Challenges (Extra Prizes)

- Make it wireless (Bluetooth HID)
- Custom LED animations and effects
- Multi-platform support (XInput + DirectInput + Switch)
- Unique form factor (fight stick, mini arcade, one-handed controller)
