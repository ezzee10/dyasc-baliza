 #include "BuzzerInterface.hpp"

class ControladorBuzzerMock: public BuzzerInterface{

    private: 
    int cantidad_de_sonidos;

    public: ControladorBuzzerMock(){
        cantidad_de_sonidos = 0;
    }

    void generarSonido(int delay_ms){
        cantidad_de_sonidos++;
    }

    int cantidad_de_sonidos_generados(){
        return cantidad_de_sonidos;
    }

};