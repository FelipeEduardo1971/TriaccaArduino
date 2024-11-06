#include "StarWars.h"
#include <Arduino.h>

int tempo = 120;
int buzzer = 6;

int melody[] = {
  NOTE_A4, -4, NOTE_A4, -4, NOTE_A4, 16, NOTE_A4, 16, NOTE_A4, 16, NOTE_A4, 16, NOTE_F4, 8, REST, 8,
  NOTE_A4, -4, NOTE_A4, -4, NOTE_A4, 16, NOTE_A4, 16, NOTE_A4, 16, NOTE_A4, 16, NOTE_F4, 8, REST, 8,
  NOTE_A4, 4, NOTE_A4, 4, NOTE_A4, 4, NOTE_F4, -8, NOTE_C5, 16,
  NOTE_A4, 4, NOTE_F4, -8, NOTE_C5, 16, NOTE_A4, 2,
  NOTE_E5, 4, NOTE_E5, 4, NOTE_E5, 4, NOTE_F5, -8, NOTE_C5, 16,
  NOTE_A4, 4, NOTE_F4, -8, NOTE_C5, 16, NOTE_A4, 2,
  NOTE_A5, 4, NOTE_A4, -8, NOTE_A4, 16, NOTE_A5, 4, NOTE_GS5, -8, NOTE_G5, 16,
  NOTE_DS5, 16, NOTE_D5, 16, NOTE_DS5, 8, REST, 8, NOTE_A4, 8, NOTE_DS5, 4, NOTE_D5, -8, NOTE_CS5, 16,
  NOTE_C5, 16, NOTE_B4, 16, NOTE_C5, 16, REST, 8, NOTE_F4, 8, NOTE_GS4, 4, NOTE_F4, -8, NOTE_A4, -16,
  NOTE_C5, 4, NOTE_A4, -8, NOTE_C5, 16, NOTE_E5, 2,
  NOTE_A5, 4, NOTE_A4, -8, NOTE_A4, 16, NOTE_A5, 4, NOTE_GS5, -8, NOTE_G5, 16,
  NOTE_DS5, 16, NOTE_D5, 16, NOTE_DS5, 8, REST, 8, NOTE_A4, 8, NOTE_DS5, 4, NOTE_D5, -8, NOTE_CS5, 16,
  NOTE_C5, 16, NOTE_B4, 16, NOTE_C5, 16, REST, 8, NOTE_F4, 8, NOTE_GS4, 4, NOTE_F4, -8, NOTE_A4, -16,
  NOTE_A4, 4, NOTE_F4, -8, NOTE_C5, 16, NOTE_A4, 2,
};

int notes = sizeof(melody) / sizeof(melody[0]) / 2;

void tocaStarWars() {
  int wholenote = (60000 * 4) / tempo;
  int divider = 0, noteDuration = 0;

  for (int thisNote = 0; thisNote < notes * 2; thisNote += 2) {
    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }

    tone(buzzer, melody[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(buzzer);
  }
}
