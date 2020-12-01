#include <Arduino.h>
#include "ControladorBuzzer.hpp"

#define BUZZER 27

ControladorBuzzer::ControladorBuzzer(){
    pinMode(BUZZER, OUTPUT);
}

void ControladorBuzzer::generarSonido(int delay_ms){
    digitalWrite(BUZZER, HIGH);
    delay(delay_ms);
    digitalWrite(BUZZER, LOW);
}


