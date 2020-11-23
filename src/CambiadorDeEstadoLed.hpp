 #include "EstadoBuild.hpp"
 #include "ControladorLed.hpp"

class CambiadorDeEstadoLed{

    public: 
    CambiadorDeEstadoLed(ControladorLed  *controlador_led);
    void cambiarEstadoLed(EstadoBuild estado);
    EstadoBuild getEstadoAnterior();
    void setEstadoAnterior(EstadoBuild estado);

    private:
    EstadoBuild estado_anterior = DESCONECTADO;
    ControladorLed *controlador_led_;
};

