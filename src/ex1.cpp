#include <Arduino.h>

constexpr uint8_t RED_LED_PIN = 26;

void setup() {
  Serial.begin(115200);
  pinMode(RED_LED_PIN, OUTPUT);
  digitalWrite(RED_LED_PIN, LOW);
}

void loop() {
  digitalWrite(RED_LED_PIN, HIGH);
  Serial.println("RED ON");
  delay(500);

  digitalWrite(RED_LED_PIN, LOW);
  Serial.println("RED OFF");
  delay(500);
}
