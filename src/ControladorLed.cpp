#include <Arduino.h>
#include "ControladorLed.hpp"
#include "EstadoBuild.hpp"

#define LED_VERDE 14
#define LED_AMARILLO 26
#define LED_ROJO 33
#define BUZZER 27


ControladorLed::ControladorLed(){
    pinMode(BUZZER, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_ROJO, OUTPUT);
    pinMode(LED_AMARILLO, OUTPUT);
    //cambiarEstadoLeds(DESCONECTADO);

}


void ControladorLed::apagarLeds(){
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_AMARILLO, LOW);
}



void ControladorLed::parpadearLedVerde(int tiempo, int cantidadParpadeos){
    for(int i=0; i<cantidadParpadeos; i++){
        Serial.println(LED_VERDE);
        digitalWrite(LED_VERDE, HIGH);
        delay(tiempo);
        digitalWrite(LED_VERDE, LOW);
        delay(tiempo);
        digitalWrite(LED_VERDE, HIGH);
    
    }   
}

void ControladorLed::parpadearLedRojo(int tiempo, int cantidadParpadeos){
    for(int i=0; i<cantidadParpadeos; i++){
        Serial.println(LED_VERDE);
        digitalWrite(LED_ROJO, HIGH);
        delay(tiempo);
        digitalWrite(LED_ROJO, LOW);
        delay(tiempo);
        digitalWrite(LED_ROJO, HIGH);
    
    }   
}

void ControladorLed::encenderLedVerde(){
    digitalWrite(LED_VERDE, HIGH);
    Serial.println("BUILD EXITOSO"); 
}

void ControladorLed::encenderLedAmarillo(){
    digitalWrite(LED_AMARILLO, HIGH);
    Serial.println("DESCONECTADO");
}

void ControladorLed::encenderLedRojo(){
    digitalWrite(LED_ROJO, HIGH);
    Serial.println("BUILD FALLIDO");
}

void ControladorLed::encenderBuzzer(){
    digitalWrite(BUZZER, HIGH);
    delay(200);
    digitalWrite(BUZZER,LOW);
}








