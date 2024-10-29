// Include the clickButton library, as well as the musicNotes file.
#include <cstring>
#include "Particle.h"
#include "musicNotes.cpp"

// Defines the correct pins.
#define BUZZER D1

int playSong(String songID_str);

// Set up the pin modes for each pin.
void setup() {
  Particle.function("play", playSong);
  pinMode(BUZZER, OUTPUT);
}

// INPUT: A string that represents which song to play
// OUTPUT: VOID
// METHOD: We convert the string to an integer, and then use that integer to
//         to check which song to play. If it's an odd number,
//         we play the first song, otherwise we play the second song. After it
//         has played, we turn the LED back off.
int playSong(String songID_str) {
  int songID_int = 0;
  
  if (songID_str == "one" || songID_str == "One" || songID_str == "ONE") {
    songID_int = 1;
  } else if (songID_str == "two" || songID_str == "Two" || songID_str == "TWO") {
    songID_int = 2;
  } else {
    songID_int = 0;
  }
  
  if (songID_int == 0) {
    return 1;
  }

  if (songID_int == 1) {
    // Notes in the melody, and how long to play each note for
    int melody[] = {N_B5,N_D5,N_GS5,N_A5,N_D5,N_E5,N_GS5,N_A5,N_B4,N_C5,N_B5,N_E5,N_B5,N_D5,N_GS5,N_A5,N_D5,N_E5,N_GS5,N_A5,N_B4,N_C5,N_B5,N_E5};
    int noteDurations[] = {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6};

    // Code to play the melody, copied in from assignment
    for (int thisNote = 0; thisNote < 24; thisNote++) {
      int noteDuration = 1000/noteDurations[thisNote];
      tone(BUZZER, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(BUZZER);
    }
  } else {
    // Notes in the melody, and how long to play each note for
    int melody[] = {N_CS5,N_E5,N_GS5,N_CS5,N_E5,N_CS6,N_CS5,N_E5,N_GS5,N_CS5,N_E5,N_CS6,N_CS5,N_E5,N_GS5,N_CS5,N_E5,N_GS5,N_C6,N_E5,N_GS5,N_E6,N_E5,N_GS5,N_C6,N_E5,N_GS5,N_E6,N_E5,N_GS5,N_C6,N_E5,N_DS5,N_FS5,N_A6,N_DS5,N_FS5,N_DS6,N_DS5,N_FS5,N_A6,N_DS5,N_FS5,N_DS6,N_DS5,N_FS5,N_A6,N_FS5,N_GS5,N_C6,N_DS6,N_A6,N_DS6,N_C6,N_DS6,N_A6,N_FS6,N_CS7,N_C7,N_GS6,N_A6,N_C6,N_DS6,N_FS6};
    int noteDurations[] = {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};

    // Code to play the melody, copied in from assignment
    for (int thisNote = 0; thisNote < 64; thisNote++) {
      int noteDuration = 900/noteDurations[thisNote];
      tone(BUZZER, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(BUZZER);
    }
  }

  return 0;
}