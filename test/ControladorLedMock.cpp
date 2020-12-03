 #include "LuzInterface.hpp"

class ControladorLedMock: public LuzInterface{

    private: 
    bool led_verde_encendido;
    bool led_rojo_encendido;
    bool led_amarillo_encendido;
    int cantidad_encendidos_parpadeo_verde = 0;
    int cantidad_encendidos_parpadeo_rojo = 0;

    public: ControladorLedMock(){
        led_verde_encendido = false;
        led_rojo_encendido = false;
        led_amarillo_encendido = true;
    }

    void apagarLuces(){
        led_verde_encendido = false;
        led_rojo_encendido = false;
        led_amarillo_encendido = false;
    }

    void encenderLuzVerde(){
        led_verde_encendido = true;

    }

    void encenderLuzAmarilla(){
        led_amarillo_encendido = true;
    }

    void encenderLuzRoja(){
        led_rojo_encendido = true;
    }

    void parpadearLuzVerde(int tiempo, int cantidadParpadeos){

        cantidad_encendidos_parpadeo_verde = cantidadParpadeos;
      
    }   
    
    void parpadearLuzRoja(int tiempo, int cantidadParpadeos){
        cantidad_encendidos_parpadeo_rojo = cantidadParpadeos;
    }

    bool ledVerdeEncendido(){
        return led_verde_encendido;
    }

    bool ledRojoEncendido(){
        return led_rojo_encendido;
    }

    bool ledAmarilloEncendido(){
        return led_amarillo_encendido;
    }

    int cantidadParpadeosEncendidosVerdes(){
        return cantidad_encendidos_parpadeo_verde;
    }

    int cantidadParpadeosEncendidosRojos(){
        return cantidad_encendidos_parpadeo_rojo;
    }

};