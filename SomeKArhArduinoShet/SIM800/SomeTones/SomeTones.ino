#include "pitches.h"

int spiker = 8;

void setup() {
  pinMode(spiker, OUTPUT);
}

void loop() {
  //    tone(pin, hz, milisec);
//    tone(spiker, 369);
//    delay(500);  
    noTone(spiker);
    delay(500);
}
