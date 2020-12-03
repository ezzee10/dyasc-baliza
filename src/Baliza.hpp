#include "WiFi.h"
#include "ConectorWifi.hpp"
#include "ConexionTravis.hpp"
#include "ProcesadorDeEstado.hpp"

class Baliza{

    public: 
    Baliza(ConectorWifi *conectorWifi,
                    CiInterface *CiInterface,
                    ProcesadorDeEstado *procesadorEstado);
    void iniciar();
    void consultarEstado();

    private: 
    ConectorWifi *conectorWifi_;
    CiInterface *CiInterface_;
    ProcesadorDeEstado *procesadorEstado_;
    EstadoBuild estado;
};