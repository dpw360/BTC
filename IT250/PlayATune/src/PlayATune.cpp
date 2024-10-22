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
    int melody[] = {N_B7,N_D6,N_GS6,N_A7,N_D6,N_E6,N_GS6,N_A6,N_B7,N_C7,N_B7,N_E6};
    int noteDurations[] = {6,6,6,6,6,6,6,6,6,6,6,6};

    // Code to play the melody, copied in from assignment
    for (int thisNote = 0; thisNote < sizeof(melody); thisNote++) {
      int noteDuration = 1000/noteDurations[thisNote];
      tone(BUZZER, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(BUZZER);
    }
  } else {
    // Notes in the melody, and how long to play each note for
    int melody[] = {N_CS6,N_E6,N_GS6,N_CS6,N_E6,N_CS7,N_CS6,N_E6,N_GS6,N_CS6,N_E6,N_CS7,N_CS6,N_E6,N_GS6,N_CS6,};
    int noteDurations[] = {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};

    // Code to play the melody, copied in from assignment
    for (int thisNote = 0; thisNote < sizeof(melody); thisNote++) {
      int noteDuration = 1000/noteDurations[thisNote];
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

void loop() {
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
