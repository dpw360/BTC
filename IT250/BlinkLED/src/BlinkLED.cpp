#include "Particle.h"
SYSTEM_MODE(AUTOMATIC);
SerialLogHandler logHandler(LOG_LEVEL_INFO);

// Set var led1 to pin D7
int led1 = D7;

// Set the pin to output voltage
void setup() {
  pinMode(led1, OUTPUT);
}

// INPUT: Char "length" variable that specifies long or short blink
// OUTPUT: VOID
// FUNCTION: Sets the time period in milliseconds for how long the LED should
// be on and off using the length variable, and then turns it on and off using
// the specified time lengths.
void blink(char length) {
  int onPeriod;
  int offPeriod = 250;

  if (length == 's') {
    onPeriod = 250;
  } else if (length == 'l') {
    onPeriod = 500;
  } else {
    onPeriod = 500;
  }

  digitalWrite(led1, HIGH);
  delay(onPeriod);
  digitalWrite(led1, LOW);
  delay(offPeriod);
}


void loop() {
  blink('s');
  blink('l');
  blink('s');

  delay(3000);
}