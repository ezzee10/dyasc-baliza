 #ifndef CONTROLADOR_LED_H
 #define CONTROLADOR_LED_H

 #include "LedsInterface.hpp"

class ControladorLed: public LedsInterface{

    public: 
    ControladorLed();
    void apagarLeds();
    void encenderLedVerde();
    void encenderLedAmarillo();
    void encenderLedRojo();
    void parpadearLedVerde(int tiempo, int cantidadParpadeos);
    void parpadearLedRojo(int tiempo, int cantidadParpadeos);
   // void encenderBuzzer();

};

#endif