 #ifndef CONTROLADOR_BUZZER_H
 #define CONTROLADOR_BUZZER_H

 #include "SonidoInterface.hpp"

class ControladorBuzzer: public SonidoInterface{

    public: 
    ControladorBuzzer();
    void generarSonido(int tiempo);

  
};

#endif