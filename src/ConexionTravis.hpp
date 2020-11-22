#include <string>
#include "EstadoBuild.hpp"

class ConexionTravis{

    public: 
    ConexionTravis(std::string usuario, std::string repositorio, std::string token);
    EstadoBuild ObtenerEstado();
    EstadoBuild DefinirEstado(std::string estado);

    private: 
    std:: string nombre_repo_;
    std:: string token_;
    std:: string usuario_;
    EstadoBuild estado;
};