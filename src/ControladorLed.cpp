#include <Arduino.h>
#include "ControladorLed.hpp"
#include "EstadoBuild.hpp"

#define LED_VERDE 14
#define LED_AMARILLO 26
#define LED_ROJO 33
#define DELAY_PROGRESO 300
#define DELAY_CAMBIO_ESTADO 500


ControladorLed::ControladorLed(){
    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_ROJO, OUTPUT);
    pinMode(LED_AMARILLO, OUTPUT);
    cambiarEstadoLeds(DESCONECTADO);

}

void ControladorLed::apagarLeds(){
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_AMARILLO, LOW);
}


void ControladorLed::parpadearLed(int nro_led, int tiempo, int cantidadParpadeos){
    for(int i=0; i<cantidadParpadeos; i++){
        Serial.println(LED_VERDE);
        digitalWrite(nro_led, HIGH);
        delay(tiempo);
        digitalWrite(nro_led, LOW);
        delay(tiempo);
        digitalWrite(nro_led, HIGH);
    
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


void ControladorLed::cambiarEstadoLeds(EstadoBuild estado){
    apagarLeds();

    switch(estado){
        case DESCONECTADO :
            encenderLedAmarillo();
            break;
        case PASADO : 
            if(getEstadoAnterior() == FALLIDO){
                parpadearLed(LED_VERDE, DELAY_CAMBIO_ESTADO, 3);
            }
            encenderLedVerde();
            break;
        case FALLIDO :
            if(getEstadoAnterior() == PASADO){
                parpadearLed(LED_ROJO, DELAY_CAMBIO_ESTADO, 3);
            }
            encenderLedRojo();       
            break;
        case PROGRESO :
            parpadearLed(LED_VERDE, DELAY_PROGRESO, 4);
            Serial.println("BUILD EN PROGRESO");
            break;         
    }

     setEstadoAnterior(estado);
}

void ControladorLed::setEstadoAnterior(EstadoBuild nuevoEstado){
    estado_anterior = nuevoEstado;
}

EstadoBuild ControladorLed::getEstadoAnterior(){
    return estado_anterior;
}





