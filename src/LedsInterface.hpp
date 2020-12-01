 #ifndef INTERFACE_LED_H
 #define INTERFACE_LED_H

class LedsInterface{
    public:
    
    virtual void apagarLeds() = 0;
    virtual void encenderLedVerde() = 0;
    virtual void encenderLedAmarillo() = 0;
    virtual void encenderLedRojo() = 0;
    virtual void parpadearLedVerde(int tiempo, int cantidadParpadeos) = 0;
    virtual void parpadearLedRojo(int tiempo, int cantidadParpadeos) = 0;
    virtual void encenderBuzzer();
    
};

#endif