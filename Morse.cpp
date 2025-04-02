#include "Morse.h"

Morse::Morse(int pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

void Morse::sendMessage(String text) {
  for (int i = 0; i < text.length(); i++) {
    char c = text[i];
    String morseCode = convertToMorse(c);
    for (int j = 0; j < morseCode.length(); j++) {
      char mc = morseCode[j];
      switch (mc) {
        case '.':
          sendDot();
          break;
        case '-':
          sendDash();
          break;
      }
      // Short gap between symbols
      delay(500);
    }
    // Gap between letters
    delay(1000);
  }
}

void Morse::sendDot() {
  digitalWrite(_pin, HIGH);
  delay(100); // Dot duration
  digitalWrite(_pin, LOW);
  delay(50); // Gap after dot
}

void Morse::sendDash() {
  digitalWrite(_pin, HIGH);
  delay(500); // Dash duration
  digitalWrite(_pin, LOW);
  delay(50); // Gap after dash
}

void Morse::sendSpace() {
  delay(500); // Space between words
}

String Morse::convertToMorse(char c) {
  switch (toupper(c)) {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    case '0': return "-----";
    case ' ': return " ";
    default: return "";
  }
}