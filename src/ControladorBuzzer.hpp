 #ifndef CONTROLADOR_BUZZER_H
 #define CONTROLADOR_BUZZER_H

 #include "BuzzerInterface.hpp"

class ControladorBuzzer: public BuzzerInterface{

    public: 
    ControladorBuzzer();
    void generarSonido(int delay_ms);

  
};

#endif