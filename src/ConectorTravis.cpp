#include "ConectorTravis.hpp"
#include <HTTPClient.h>
#include <Arduino.h>
#include <string>
#include "EstadoBuild.hpp"

ConectorTravis::ConectorTravis(std::string usuario, std::string nombre_repo, std::string token){
    nombre_repo_ = nombre_repo;
    token_ = token;
    usuario_ = usuario;
    estado = DESCONECTADO;
}

EstadoBuild ConectorTravis::ObtenerEstado(){
    HTTPClient http;
    std::string url_concat = "https://api.travis-ci.com/repo/" + usuario_ + "%2F" + nombre_repo_ + "/branch/master";
    std::string token_concat = "token " + token_;
    http.begin(url_concat.c_str());
    http.addHeader("Travis-API-Version", "3");
    http.addHeader("Authorization",  token_concat.c_str());
    int httpCode = http.GET();
    //Serial.println(httpCode);

    if (httpCode > 0){ 
        String payload = http.getString();
        int comienzo = payload.indexOf("state") + 9;
        int fin = payload.indexOf(",", comienzo) - 1;
        String state = (payload.substring(comienzo, fin));
        Serial.println(state);
        DefinirEstado(state.c_str());
        return estado;      
    }else{
        http.end();
        Serial.println(estado + "x");
        return estado;
    }

}


void ConectorTravis::DefinirEstado(std::string state){

        std::string estadoCorrecto = "passed";
        std::string estadoIncorrecto = "failed";
        std::string estadoEnProgreso1 = "created";
        std::string estadoEnProgreso2 = "started";

        if(state == estadoCorrecto){
            estado = EXITOSO;
        }else if(state == estadoIncorrecto){
            estado = FALLIDO;
        }else if(state == estadoEnProgreso1 || state == estadoEnProgreso2){
            estado = PROGRESO;
        }else{
            estado = DESCONECTADO;
        }

}





