 #ifndef CONTROLADOR_LED_H
 #define CONTROLADOR_LED_H

 #include "LuzInterface.hpp"

class ControladorLed: public LuzInterface{

    public: 
    ControladorLed();
    void apagarLuces();
    void encenderLuzVerde();
    void encenderLuzAmarilla();
    void encenderLuzRoja();
    void parpadearLuzVerde(int tiempo, int cantidadParpadeos);
    void parpadearLuzRoja(int tiempo, int cantidadParpadeos);

};

#endif