#include "Particle.h"
SYSTEM_MODE(AUTOMATIC);
SerialLogHandler logHandler(LOG_LEVEL_INFO);

// set var led1 to D7
int led1 = D7; 

void setup() {
    pinMode(led1, OUTPUT);
}

void loop() {
    // SHORT BLINK
    // This turns the LED on for 500ms, then off for 250ms
    digitalWrite(led1, HIGH);
    delay(250);
    digitalWrite(led1, LOW);
    delay(250);
    
    // LONG BLINK
    // This turns the LED on for 1000ms, then off for 250ms
    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led1, LOW);
    delay(250);
    
    // SHORT BLINK
    // This turns the LED on for 500ms, then off for 3000ms
    digitalWrite(led1, HIGH);
    delay(250);
    digitalWrite(led1, LOW);
    delay(3000);
}