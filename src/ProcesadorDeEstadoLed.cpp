#include "ProcesadorDeEstadoLed.hpp"
#include "EstadoBuild.hpp"
#include <Arduino.h>

ProcesadorDeEstadoLed::ProcesadorDeEstadoLed(LedsInterface  *interface_led){
    interface_led_ = interface_led;
    cambiarEstadoLed(DESCONECTADO);
}


void ProcesadorDeEstadoLed::cambiarEstadoLed(EstadoBuild estado){
    interface_led_->apagarLeds();

    switch(estado){
        case DESCONECTADO :
            interface_led_->encenderLedAmarillo();
            break;
        case PASADO : 
            if(getEstadoAnterior() == FALLIDO){
                interface_led_->parpadearLedVerde(300, 3);
            }
            interface_led_->encenderLedVerde();
            break;
        case FALLIDO :
            if(getEstadoAnterior() == PASADO){
                interface_led_->parpadearLedRojo(300, 3);
            }
            interface_led_->encenderLedRojo();       
            break;
        case PROGRESO :
            interface_led_->parpadearLedVerde(500, 4);
            Serial.println("BUILD EN PROGRESO");
            break;         
    }

     setEstadoAnterior(estado);
}

void ProcesadorDeEstadoLed::setEstadoAnterior(EstadoBuild nuevoEstado){
    estado_anterior = nuevoEstado;
}

EstadoBuild ProcesadorDeEstadoLed::getEstadoAnterior(){
    return estado_anterior;
}