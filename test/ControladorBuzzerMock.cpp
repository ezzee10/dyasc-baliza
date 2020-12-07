 #include "SonidoInterface.hpp"

class ControladorBuzzerMock: public SonidoInterface{

    private: 
    int cantidad_de_sonidos;

    public: ControladorBuzzerMock(){
        cantidad_de_sonidos = 0;
    }

    void generarSonido(int tiempo){
        cantidad_de_sonidos++;
    }

    int cantidad_de_sonidos_generados(){
        return cantidad_de_sonidos;
    }

};