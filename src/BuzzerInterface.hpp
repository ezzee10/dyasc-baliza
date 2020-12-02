 #ifndef INTERFACE_BUZZER_H
 #define INTERFACE_BUZZER_H

class BuzzerInterface{
    public:
    
    virtual void generarSonido(int delay_ms) = 0;
    
};

#endif