#include "ProcesadorDeEstado.hpp"
#include "EstadoBuild.hpp"
#include <Arduino.h>

ProcesadorDeEstado::ProcesadorDeEstado(LedsInterface  *interface_led, BuzzerInterface *buzzer_interface){
    interface_led_ = interface_led;
    interface_buzzer_ = buzzer_interface;
    cambiarEstadoBuild(DESCONECTADO);
}


void ProcesadorDeEstado::cambiarEstadoBuild(EstadoBuild estado){
    interface_led_->apagarLeds();

    switch(estado){
        case DESCONECTADO :
            interface_led_->encenderLedAmarillo();
            setEstadoAnterior(estado);
            break;
        case PASADO : 
            if(getEstadoAnterior() == FALLIDO){
                interface_led_->parpadearLedVerde(300, 3);
                interface_buzzer_->generarSonido(300);
            }
            setEstadoAnterior(estado);
            interface_led_->encenderLedVerde();
            break;
        case FALLIDO :
            if(getEstadoAnterior() == PASADO){
                interface_led_->parpadearLedRojo(300, 3);
                interface_buzzer_->generarSonido(300);
            }
            setEstadoAnterior(estado);
            interface_led_->encenderLedRojo();       
            break;
        case PROGRESO :
            if(getEstadoAnterior() == PASADO){
                interface_led_->parpadearLedVerde(500, 4);
            }else{
                interface_led_->parpadearLedRojo(500,4);
            }    
            Serial.println("BUILD EN PROGRESO");
            break;         
    }

    
}

void ProcesadorDeEstado::setEstadoAnterior(EstadoBuild nuevoEstado){
    estado_anterior = nuevoEstado;
}

EstadoBuild ProcesadorDeEstado::getEstadoAnterior(){
    return estado_anterior;
}