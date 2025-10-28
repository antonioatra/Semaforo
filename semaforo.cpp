// C++ code
#include <Arduino.h>

unsigned long tempoInicial = 0;

bool red = false;
bool yel = false;
bool green = true;

void setup() {
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  unsigned long tempoAgora = millis();

  if (green == true) {
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);

    if (tempoAgora - tempoInicial >= 4000) {
      green = false;
      yel = true;
      tempoInicial = tempoAgora;
    }
  }

  else if (yel == true) {
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);

    if (tempoAgora - tempoInicial >= 2000) {
      yel = false;
      red = true;
      tempoInicial = tempoAgora;
    }
  }

  else if (red == true) {
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);

    if (tempoAgora - tempoInicial >= 6000) {
      red = false;
      green = true;
      tempoInicial = tempoAgora;
    }
  }
}
