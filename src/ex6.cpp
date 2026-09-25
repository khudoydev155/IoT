#include <Arduino.h>

constexpr uint8_t BLUE_LED_PIN = 14;

void setup() {
  Serial.begin(115200);
  pinMode(BLUE_LED_PIN, OUTPUT);
  digitalWrite(BLUE_LED_PIN, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    const char command = static_cast<char>(Serial.read());

    if (command == 'B') {
      digitalWrite(BLUE_LED_PIN, HIGH);
      Serial.println("BLUE=1");
    } else if (command == 'b') {
      digitalWrite(BLUE_LED_PIN, LOW);
      Serial.println("BLUE=0");
    }
  }
}
