#include <Arduino.h>
#include "ControladorBuzzer.hpp"

#define BUZZER 27

ControladorBuzzer::ControladorBuzzer(){
    pinMode(BUZZER, OUTPUT);
}

void ControladorBuzzer::generarSonido(int tiempo){
    digitalWrite(BUZZER, HIGH);
    delay(tiempo);
    digitalWrite(BUZZER, LOW);
}


