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
        case EXITOSO : 
            if(getEstadoAnterior() == FALLIDO){
                interface_luz_->parpadearLuzVerde(200, 3);
                interface_sonido_->generarSonido(200);
            }
            setEstadoAnterior(estado);
            interface_luz_->encenderLuzVerde();
            break;
        case FALLIDO :
            if(getEstadoAnterior() == EXITOSO){
                interface_luz_->parpadearLuzRoja(200, 3);
                interface_sonido_->generarSonido(200);
            }
            setEstadoAnterior(estado);
            interface_luz_->encenderLuzRoja();       
            break;
        case PROGRESO :
            if(getEstadoAnterior() == EXITOSO){
                interface_luz_->parpadearLuzVerde(500, 4);
            }else{
                interface_luz_->parpadearLuzRoja(500,4);
            }    
            break;         
    }

    
}

void ProcesadorDeEstado::setEstadoAnterior(EstadoBuild nuevoEstado){
    estado_anterior = nuevoEstado;
}

EstadoBuild ProcesadorDeEstado::getEstadoAnterior(){
    return estado_anterior;
}