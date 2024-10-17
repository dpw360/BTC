#include <clickButton.h>
#include "Particle.h"
#include "musicNotes.cpp"
#define BUZZER D1
#define LED D2
#define BUTTON_PIN D3

ClickButton BUTTON(BUTTON_PIN, LOW, CLICKBTN_PULLUP);


void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void playSong(int songID) {
  digitalWrite(LED, HIGH);

  if (songID % 2 == 1) {
    int melody[] = {N_B7,N_D6,N_GS6,N_A7,N_D6,N_E6,N_GS6,N_A6,N_B7,N_C7,N_B7,N_E6};  // notes in the melody
    int noteDurations[] = {6,6,6,6,6,6,6,6,6,6,6,6};               // note durations

    for (int thisNote = 0; thisNote < 12; thisNote++) {      // ergodic all notes
      int noteDuration = 1000/noteDurations[thisNote];      // calculate the note duration
      tone(BUZZER, melody[thisNote], noteDuration);         // let speaker sonds
      int pauseBetweenNotes = noteDuration * 1.30;          // set a minimum time between notes
      delay(pauseBetweenNotes);                             // delay for the while
      noTone(BUZZER);                                       // stop the tone playing:
    }
  } else {
    int melody[] = {1900,2000,2000,2443,2500,0,2000,1900};  // notes in the melody
    int noteDurations[] = {4,8,8,4,4,4,4,4 };               // note durations

    for (int thisNote = 0; thisNote < 8; thisNote++) {      // ergodic all notes
      int noteDuration = 1000/noteDurations[thisNote];      // calculate the note duration
      tone(BUZZER, melody[thisNote], noteDuration);         // let speaker sonds
      int pauseBetweenNotes = noteDuration * 1.30;          // set a minimum time between notes
      delay(pauseBetweenNotes);                             // delay for the while
      noTone(BUZZER);  
    }
  }

  digitalWrite(LED, LOW);  
}

bool clicked;
int songID = 0;

void loop() {
  clicked = false;
  BUTTON.Update();
  
  if (BUTTON.clicks != 0) {
    clicked = true;
    songID++;
  }

  if (clicked) {
    playSong(songID);
  }
}
