 #include "CiInterface.hpp"

class ConectorCiMock: public CiInterface{

    private: 
    EstadoBuild estado_;

    public: ConectorCiMock(){
        estado_ = DESCONECTADO;
    }


    EstadoBuild ObtenerEstado(){
        return estado_;
    };
    
    void DefinirEstado(std::string estado){

        if(estado == "passed"){
            estado_ = EXITOSO;
        }else if(estado == "failed"){
            estado_ = FALLIDO;
        }else if(estado == "created" || estado == "started"){
            estado_ = PROGRESO;
        }else{
            estado_ = DESCONECTADO;
        }
    }

};

