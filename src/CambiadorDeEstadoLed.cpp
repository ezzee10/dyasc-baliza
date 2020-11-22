#include "CambiadorDeEstadoLed.hpp"
#include "EstadoBuild.hpp"
#include <Arduino.h>

CambiadorDeEstadoLed::CambiadorDeEstadoLed(ControladorLed  *controlador_led){
    controlador_led_ = controlador_led;
    cambiarEstadoLed(DESCONECTADO);
}


void CambiadorDeEstadoLed::cambiarEstadoLed(EstadoBuild estado){
    controlador_led_->apagarLeds();

    switch(estado){
        case DESCONECTADO :
            controlador_led_->encenderLedAmarillo();
            break;
        case PASADO : 
            if(getEstadoAnterior() == FALLIDO){
                controlador_led_->parpadearLedVerde(300, 3);
            }
            controlador_led_->encenderLedVerde();
            break;
        case FALLIDO :
            if(getEstadoAnterior() == PASADO){
                controlador_led_->parpadearLedRojo(300, 3);
            }
            controlador_led_->encenderLedRojo();       
            break;
        case PROGRESO :
            controlador_led_->parpadearLedVerde(500, 4);
            Serial.println("BUILD EN PROGRESO");
            break;         
    }

     setEstadoAnterior(estado);
}

void CambiadorDeEstadoLed::setEstadoAnterior(EstadoBuild nuevoEstado){
    estado_anterior = nuevoEstado;
}

EstadoBuild CambiadorDeEstadoLed::getEstadoAnterior(){
    return estado_anterior;
}