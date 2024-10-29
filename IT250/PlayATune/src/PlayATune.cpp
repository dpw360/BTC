// Include the clickButton library, as well as the musicNotes file.
#include <clickButton.h>
#include "Particle.h"
#include "musicNotes.cpp"
// Defines the correct pins.
#define BUZZER D1
#define LED D2
#define BUTTON_PIN D3

// Create the ClickButton object.
ClickButton BUTTON(BUTTON_PIN, LOW, CLICKBTN_PULLUP);

// Set up the pin modes for each pin.
void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

// INPUT: An int that represents which song to play
// OUTPUT: VOID
// METHOD: At the start of the function call, it turns on the LED. We then
//         use the songID to check which song to play. If it's an odd number,
//         we play the first song, otherwise we play the second song. After it
//         has played, we turn the LED back off.
void playSong(int songID) {
  digitalWrite(LED, HIGH);

  if (songID % 2 == 1) {
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

  digitalWrite(LED, LOW);  
}

// A global variable to check if the button has been clicked. This will reset
// each time the main loop runs.
bool clicked;
// A global variable to keep track of how many times the button has been
// pressed in total. Will not be reset, only incremented.
int songID = 0;

// MAIN LOOP //
void loop() {
  digitalWrite(LED, LOW);
  // Set the clicked var to false, then update the button to check for click
  clicked = false;
  BUTTON.Update();
  
  // If the button was clicked one or more times, set clicked to true, and
  // increment the songID variable.
  if (BUTTON.clicks != 0) {
    clicked = true;
    songID++;
  }

  // If the button was clicked, we play the song, passing the method the songID
  // variable.
  if (clicked) {
    playSong(songID);
  }
}
