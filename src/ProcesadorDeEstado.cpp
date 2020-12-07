#include "ProcesadorDeEstado.hpp"
#include "EstadoBuild.hpp"
#include <Arduino.h>

ProcesadorDeEstado::ProcesadorDeEstado(LuzInterface  *interface_luz, SonidoInterface *sonido_interface){
    interface_luz_ = interface_luz;
    interface_sonido_ = sonido_interface;
    cambiarEstadoBuild(DESCONECTADO);
}


void ProcesadorDeEstado::cambiarEstadoBuild(EstadoBuild estado){
    interface_luz_->apagarLuces();

    switch(estado){
        case DESCONECTADO :
            interface_luz_->encenderLuzAmarilla();
            setEstadoAnterior(estado);
            break;
        case PASADO : 
            if(getEstadoAnterior() == FALLIDO){
                interface_luz_->parpadearLuzVerde(300, 3);
                interface_sonido_->generarSonido(300);
            }
            setEstadoAnterior(estado);
            interface_luz_->encenderLuzVerde();
            break;
        case FALLIDO :
            if(getEstadoAnterior() == PASADO){
                interface_luz_->parpadearLuzRoja(300, 3);
                interface_sonido_->generarSonido(300);
            }
            setEstadoAnterior(estado);
            interface_luz_->encenderLuzRoja();       
            break;
        case PROGRESO :
            if(getEstadoAnterior() == PASADO){
                interface_luz_->parpadearLuzVerde(500, 4);
            }else{
                interface_luz_->parpadearLuzRoja(500,4);
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