#include "ControladorLed.hpp"

class ControladorLedMock{

    private: 
    bool led_verde_encendido;
    bool led_rojo_encendido;
    bool led_amarillo_encendido;

    public: ControladorLedMock(){
        led_verde_encendido = false;
        led_rojo_encendido = false;
        led_amarillo_encendido = true;
    }

    void apagarLeds(){
        led_verde_encendido = false;
        led_rojo_encendido = false;
        led_amarillo_encendido = true;
    }

    void encenderLedVerde(){
        led_verde_encendido = true;

    }

    void encenderLedAmarillo(){
        led_amarillo_encendido = true;
    }

    void encenderLedRojo(){
        led_rojo_encendido = true;
    }


};