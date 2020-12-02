#include "EstadoBuild.hpp"

class CiInterface{
    public:
    
    virtual EstadoBuild ObtenerEstado() = 0;
    virtual void DefinirEstado(std::string estado) = 0;

};

