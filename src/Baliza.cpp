#include "Baliza.hpp"

    Baliza::Baliza(ConectorWifi *conectorWifi,
                        CiInterface *CiInterface,
                        ProcesadorDeEstado *procesadorEstado){

        conectorWifi_ = conectorWifi;
        CiInterface_ = CiInterface;
        procesadorEstado_ = procesadorEstado;
    }

    void Baliza::iniciar(){
        conectorWifi_->ConectarRed();
    }

    void Baliza::consultarEstado(){
          if(conectorWifi_->EstaConectado()){
            estado = CiInterface_->ObtenerEstado();
            procesadorEstado_->cambiarEstadoBuild(estado);
        }else{
            iniciar();
        }
    }
