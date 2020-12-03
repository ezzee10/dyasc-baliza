#include <Arduino.h>
#include "ControladorLed.hpp"
#include "EstadoBuild.hpp"

#define LED_VERDE 14
#define LED_AMARILLO 26
#define LED_ROJO 33


ControladorLed::ControladorLed(){
    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_ROJO, OUTPUT);
    pinMode(LED_AMARILLO, OUTPUT);

}


void ControladorLed::apagarLuces(){
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_AMARILLO, LOW);
}



void ControladorLed::parpadearLuzVerde(int tiempo, int cantidadParpadeos){
    for(int i=0; i<cantidadParpadeos; i++){
        Serial.println(LED_VERDE);
        digitalWrite(LED_VERDE, HIGH);
        delay(tiempo);
        digitalWrite(LED_VERDE, LOW);
        delay(tiempo);
        digitalWrite(LED_VERDE, HIGH);
    
    }   
}

void ControladorLed::parpadearLuzRoja(int tiempo, int cantidadParpadeos){
    for(int i=0; i<cantidadParpadeos; i++){
        Serial.println(LED_VERDE);
        digitalWrite(LED_ROJO, HIGH);
        delay(tiempo);
        digitalWrite(LED_ROJO, LOW);
        delay(tiempo);
        digitalWrite(LED_ROJO, HIGH);
    
    }   
}

void ControladorLed::encenderLuzVerde(){
    digitalWrite(LED_VERDE, HIGH);
    Serial.println("BUILD EXITOSO"); 
}

void ControladorLed::encenderLuzAmarilla(){
    digitalWrite(LED_AMARILLO, HIGH);
    Serial.println("DESCONECTADO");
}

void ControladorLed::encenderLuzRoja(){
    digitalWrite(LED_ROJO, HIGH);
    Serial.println("BUILD FALLIDO");
}










