 #include "LedsInterface.hpp"

class ControladorLedMock: public LedsInterface{

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

    void apagarLeds(){
        led_verde_encendido = false;
        led_rojo_encendido = false;
        led_amarillo_encendido = false;
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

    void parpadearLedVerde(int tiempo, int cantidadParpadeos){

      for(int i=0; i<cantidadParpadeos; i++){
          cantidad_encendidos_parpadeo_verde++;
      }
      
    }   
    
    void parpadearLedRojo(int tiempo, int cantidadParpadeos){
    
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

   // void encenderBuzzer(){

    //}


};