
#include <string>

class ConexionWifi{ 

    public: ConexionWifi(std::string nombreDeRed, std::string password);
        void ConectarRed();
        bool EstaConectado();

    private: 
        std::string nombreDeRed_;
        std::string password_;
};

