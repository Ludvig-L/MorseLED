
#include "Morse.h"

Morse morse(8); // LED connected to pin 8

void setup() {
  // Nothing to do here
}

void loop() {
  morse.sendMessage("Hello world");
  delay(5000); // Wait for 5 seconds before repeating
}
