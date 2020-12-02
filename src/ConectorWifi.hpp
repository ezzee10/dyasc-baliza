#ifndef CONECTORWIFI_H
#define CONECTORWIFI_H

#include <string>

class ConectorWifi{ 

    public: ConectorWifi(std::string nombreDeRed, std::string password);
        void ConectarRed();
        bool EstaConectado();

    private: 
        std::string nombreDeRed_;
        std::string password_;
        int cantidadIntentos = 0;
};

#endif



