#include "EstadoBuild.hpp"
class ControladorLed{

    public: 
    ControladorLed();
    void cambiarEstadoLeds(EstadoBuild estado);
    void apagarLeds();
    void parpadearLed(int nro_led, int tiempo, int cantidadParpadeos);
    void encenderLedVerde();
    void encenderLedAmarillo();
    void encenderLedRojo();
    EstadoBuild getEstadoAnterior();
    void setEstadoAnterior(EstadoBuild estado);

    private: 
    EstadoBuild estado_anterior = DESCONECTADO;
    

};