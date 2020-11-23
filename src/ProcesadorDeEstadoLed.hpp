 #include "EstadoBuild.hpp"
 #include "ControladorLed.hpp"

class ProcesadorDeEstadoLed{

    public: 
    ProcesadorDeEstadoLed(LedsInterface  *interface_led);
    void cambiarEstadoLed(EstadoBuild estado);
    EstadoBuild getEstadoAnterior();
    void setEstadoAnterior(EstadoBuild estado);

    private:
    EstadoBuild estado_anterior = DESCONECTADO;
    LedsInterface *interface_led_;
};

