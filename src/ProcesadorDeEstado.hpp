 #include "EstadoBuild.hpp"
 #include "ControladorLed.hpp"

class ProcesadorDeEstado{

    public: 
    ProcesadorDeEstado(LedsInterface  *interface_led);
    void cambiarEstadoBuild(EstadoBuild estado);
    EstadoBuild getEstadoAnterior();
    void setEstadoAnterior(EstadoBuild estado);

    private:
    EstadoBuild estado_anterior = DESCONECTADO;
    LedsInterface *interface_led_;
};

