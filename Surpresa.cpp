#include "Surpresa.h"
#include <Arduino.h>

int temp = 180; 
int apito = 6; 

int secret[] = {
  
  NOTE_E5, 8, NOTE_D5, 8, NOTE_FS4, 4, NOTE_GS4, 4, 
  NOTE_CS5, 8, NOTE_B4, 8, NOTE_D4, 4, NOTE_E4, 4, 
  NOTE_B4, 8, NOTE_A4, 8, NOTE_CS4, 4, NOTE_E4, 4,
  NOTE_A4, 2, 
};

int nota = sizeof(secret) / sizeof(secret[0]) / 2;
int wholenote = (60000 * 4) / temp;

void tocaSurpresa() {
  int divider = 0, noteDuration = 0;

  for (int thisNote = 0; thisNote < nota * 2; thisNote += 2) {
    divider = secret[thisNote + 1];

    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }

    tone(apito, secret[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(apito);
  }
}