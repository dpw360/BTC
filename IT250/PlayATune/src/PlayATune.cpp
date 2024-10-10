#include "Particle.h"
#define BUZZER D1
#define LED D2
#define BUTTON D3
bool buttonState = false;


void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

// INPUT: N/A
// OUTPUT: A boolean describing whether or not the button was pressed.
bool wasButtonPressed() {
  // Read if the button was pressed, store in var
  bool pressed = digitalRead(BUTTON);

  // Polls with an interrupt
  if (!pressed) {
    buttonState = 1 - buttonState;
    delay(200);
  }

  // Return if the button was pressed
  if (buttonState) {
    return true;
  } else {
    return false;
  }
}

int melody[] = {1908,2551,2551,2273,2551,0,2024,1908};  // notes in the melody
int noteDurations[] = {4,8,8,4,4,4,4,4 };               // note durations

void loop() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {  // ergodic all notes
    int noteDuration = 1000/noteDurations[thisNote];  // calculate the note duration
    tone(BUZZER, melody[thisNote], noteDuration);  // let speaker sonds
    int pauseBetweenNotes = noteDuration * 1.30;      // set a minimum time between notes
    delay(pauseBetweenNotes);                         // delay for the while
    noTone(BUZZER);                                // stop the tone playing:
  }
}
