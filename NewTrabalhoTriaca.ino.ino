#include "StarWars.h"
#include "FurElise.h"
#include "Surpresa.h"

void setup() {
  pinMode(buzzer, OUTPUT);
  serial.Begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Lê até a nova linha

    if (input == "Star") {
      tocaStarWars();
      delay(2000);
    }else if(input == "Pink"){
      tocaPinkP();
      delay(2000);
    }else if(input == "Surprise"){
      tocaSurpresa();
      delay(2000);
    }

  }
}
