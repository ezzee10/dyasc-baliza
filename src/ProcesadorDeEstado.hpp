#ifndef PROCESADOR_DE_ESTADO_H
#define PROCESADOR_DE_ESTADO_H
 
 #include "EstadoBuild.hpp"
 #include "ControladorLed.hpp"
 #include "ControladorBuzzer.hpp"

class ProcesadorDeEstado{

    public: 
    ProcesadorDeEstado(LedsInterface  *interface_led, BuzzerInterface *interface_buzzer);
    void cambiarEstadoBuild(EstadoBuild estado);
    EstadoBuild getEstadoAnterior();
    void setEstadoAnterior(EstadoBuild estado);

    private:
    EstadoBuild estado_anterior = DESCONECTADO;
    LedsInterface *interface_led_;
    BuzzerInterface *interface_buzzer_;
};

#endif

