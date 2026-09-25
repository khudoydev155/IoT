#include <Arduino.h>

constexpr uint8_t GREEN_LED_PIN = 27;
constexpr uint8_t BUTTON_PIN = 25;

bool greenState = false;
bool previousButtonState = false;

void setup() {
  Serial.begin(115200);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(GREEN_LED_PIN, LOW);
}

void loop() {
  const bool buttonState = digitalRead(BUTTON_PIN) == HIGH;

  if (buttonState && !previousButtonState) {
    greenState = !greenState;
    digitalWrite(GREEN_LED_PIN, greenState ? HIGH : LOW);
    Serial.println(greenState ? "GREEN=1" : "GREEN=0");
  }

  previousButtonState = buttonState;
  delay(10);
}
