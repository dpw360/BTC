#include "Particle.h"

int LED_PIN = D2;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
