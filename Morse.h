#ifndef MORSE_H
#define MORSE_H

#include "Arduino.h"

class Morse {
  public:
    Morse(int pin);
    void sendMessage(String text);

  private:
    int _pin;
    void sendDot();
    void sendDash();
    void sendSpace();
    String convertToMorse(char c);
};

#endif