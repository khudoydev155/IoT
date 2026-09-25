#include <Arduino.h>

constexpr uint8_t BUTTON_PIN = 25;
constexpr uint8_t LIGHT_SENSOR_PIN = 33;
constexpr uint8_t YELLOW_LED_PIN = 12;

bool previousButtonState = false;
bool yellowFlashActive = false;
uint32_t yellowFlashStartedAt = 0;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  digitalWrite(YELLOW_LED_PIN, LOW);
}

void loop() {
  const uint32_t now = millis();
  const bool buttonState = digitalRead(BUTTON_PIN) == HIGH;

  if (buttonState && !previousButtonState) {
    Serial.print("snapshot=");
    Serial.println(analogRead(LIGHT_SENSOR_PIN));
    digitalWrite(YELLOW_LED_PIN, HIGH);
    yellowFlashActive = true;
    yellowFlashStartedAt = now;
  }

  if (yellowFlashActive && now - yellowFlashStartedAt >= 100UL) {
    digitalWrite(YELLOW_LED_PIN, LOW);
    yellowFlashActive = false;
  }

  previousButtonState = buttonState;
  delay(10);
}
