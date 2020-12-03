#ifndef PROCESADOR_DE_ESTADO_H
#define PROCESADOR_DE_ESTADO_H
 
 #include "EstadoBuild.hpp"
 #include "ControladorLed.hpp"
 #include "ControladorBuzzer.hpp"

class ProcesadorDeEstado{

    public: 
    ProcesadorDeEstado(LuzInterface  *interface_luz, BuzzerInterface *interface_buzzer);
    void cambiarEstadoBuild(EstadoBuild estado);
    EstadoBuild getEstadoAnterior();
    void setEstadoAnterior(EstadoBuild estado);

    private:
    EstadoBuild estado_anterior = DESCONECTADO;
    LuzInterface *interface_luz_;
    BuzzerInterface *interface_buzzer_;
};

#endif

