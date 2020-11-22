 #ifndef CONTROLADOR_LED_H
 #define CONTROLADOR_LED_H

class ControladorLed{

    public: 
    ControladorLed();
   // void cambiarEstadoLeds(EstadoBuild estado);
    void apagarLeds();
    void encenderLedVerde();
    void encenderLedAmarillo();
    void encenderLedRojo();
    void parpadearLedVerde(int tiempo, int cantidadParpadeos);
    void parpadearLedRojo(int tiempo, int cantidadParpadeos);
  //  EstadoBuild getEstadoAnterior();
  //  void setEstadoAnterior(EstadoBuild estado);

  //  private: 
  //  EstadoBuild estado_anterior = DESCONECTADO;
  
};

#endif