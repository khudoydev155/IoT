#include <Arduino.h>

constexpr uint8_t RED_LED_PIN = 26;
constexpr uint8_t GREEN_LED_PIN = 27;
constexpr uint8_t BLUE_LED_PIN = 14;
constexpr uint8_t YELLOW_LED_PIN = 12;
constexpr uint8_t LIGHT_SENSOR_PIN = 33;

enum class Band : uint8_t {
  Blue,
  Green,
  Yellow,
  Red
};

void setOnlyLed(uint8_t selectedPin) {
  digitalWrite(RED_LED_PIN, selectedPin == RED_LED_PIN ? HIGH : LOW);
  digitalWrite(GREEN_LED_PIN, selectedPin == GREEN_LED_PIN ? HIGH : LOW);
  digitalWrite(BLUE_LED_PIN, selectedPin == BLUE_LED_PIN ? HIGH : LOW);
  digitalWrite(YELLOW_LED_PIN, selectedPin == YELLOW_LED_PIN ? HIGH : LOW);
}

Band getBand(uint16_t raw) {
  if (raw <= 1023) {
    return Band::Blue;
  }
  if (raw <= 2047) {
    return Band::Green;
  }
  if (raw <= 3071) {
    return Band::Yellow;
  }
  return Band::Red;
}

const char* bandName(Band band) {
  switch (band) {
    case Band::Blue:
      return "BLUE";
    case Band::Green:
      return "GREEN";
    case Band::Yellow:
      return "YELLOW";
    case Band::Red:
      return "RED";
  }
  return "BLUE";
}

uint8_t bandPin(Band band) {
  switch (band) {
    case Band::Blue:
      return BLUE_LED_PIN;
    case Band::Green:
      return GREEN_LED_PIN;
    case Band::Yellow:
      return YELLOW_LED_PIN;
    case Band::Red:
      return RED_LED_PIN;
  }
  return BLUE_LED_PIN;
}

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);

  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  setOnlyLed(0);
}

void loop() {
  static bool firstReading = true;
  static Band previousBand = Band::Blue;

  const Band currentBand = getBand(analogRead(LIGHT_SENSOR_PIN));
  setOnlyLed(bandPin(currentBand));

  if (firstReading || currentBand != previousBand) {
    Serial.print("band=");
    Serial.println(bandName(currentBand));
    previousBand = currentBand;
    firstReading = false;
  }

  delay(100);
}
