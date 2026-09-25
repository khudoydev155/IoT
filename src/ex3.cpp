#include <Arduino.h>

constexpr uint8_t LIGHT_SENSOR_PIN = 33;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  const uint16_t raw = analogRead(LIGHT_SENSOR_PIN);
  Serial.print("raw=");
  Serial.println(raw);
  delay(500);
}
