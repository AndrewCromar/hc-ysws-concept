#include <Arduino.h>

const int LED_PIN = 27;

const int BTN_LEFT_N = 17;
const int BTN_LEFT_E = 18;
const int BTN_LEFT_S = 26;
const int BTN_LEFT_W = 16;

const int BTN_RIGHT_N = 20;
const int BTN_RIGHT_E = 21;
const int BTN_RIGHT_S = 22;
const int BTN_RIGHT_W = 19;

const int BUTTONS[] = {
  BTN_LEFT_N, BTN_LEFT_E, BTN_LEFT_S, BTN_LEFT_W,
  BTN_RIGHT_N, BTN_RIGHT_E, BTN_RIGHT_S, BTN_RIGHT_W
};
const int NUM_BUTTONS = sizeof(BUTTONS) / sizeof(BUTTONS[0]);

const char* BUTTON_NAMES[] = {
  "LEFT_N", "LEFT_E", "LEFT_S", "LEFT_W",
  "RIGHT_N", "RIGHT_E", "RIGHT_S", "RIGHT_W"
};

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(BUTTONS[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    if (digitalRead(BUTTONS[i]) == LOW) {
      Serial.println(BUTTON_NAMES[i]);
    }
  }
  delay(100);
}