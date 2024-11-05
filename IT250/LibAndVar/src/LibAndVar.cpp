#include <Grove_LED_Bar.h>
#include <Particle.h>

// Set the correct pins, and create the LED_BAR object.
#define POT A4
#define LED D2
Grove_LED_Bar LED_BAR(3, 2, 0);

// Create the two variables we'll use to track the value of the pot. One will
// update with the analog value, one with the digital value.
int potValue = 0;
int potValueDigital = 0;

// Setup the pins, and initialize the LED_BAR object.
void setup() {
  pinMode(POT, INPUT);
  pinMode(LED, OUTPUT);
  LED_BAR.begin();
  
  // Publish the variables.
  Particle.variable("Pot Value", potValue);
  Particle.variable("Level", potValueDigital);
}

void loop() {
  // Read in the analog value from the pot.
  potValue = analogRead(POT);

  // Map the value to the digital variable.
  potValueDigital = map(potValue, 0, 4095, 0, 10);

  // Set the level on the LED accordingly.
  LED_BAR.setLevel(potValueDigital);
}
