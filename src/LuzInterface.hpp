 #ifndef INTERFACE_LUZ_H
 #define INTERFACE_LUZ_H

class LuzInterface{
    public:
    
    virtual void apagarLuces() = 0;
    virtual void encenderLuzVerde() = 0;
    virtual void encenderLuzAmarilla() = 0;
    virtual void encenderLuzRoja() = 0;
    virtual void parpadearLuzVerde(int tiempo, int cantidadParpadeos) = 0;
    virtual void parpadearLuzRoja(int tiempo, int cantidadParpadeos) = 0;
    
};

#endif