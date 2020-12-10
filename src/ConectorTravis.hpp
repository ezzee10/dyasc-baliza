#ifndef CONEXIONTRAVIS_H
#define CONEXIONTRAVIS_H

#include <string>
#include "EstadoBuild.hpp"
#include "CiInterface.hpp"

class ConectorTravis: public CiInterface{

    public: 
    ConectorTravis(std::string usuario, std::string repositorio, std::string token);
    EstadoBuild ObtenerEstado();
    void DefinirEstado(std::string estado);

    private: 
    std:: string nombre_repo_;
    std:: string token_;
    std:: string usuario_;
    EstadoBuild estado;
};

#endif

