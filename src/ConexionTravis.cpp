#include "ConexionTravis.hpp"
#include <HTTPClient.h>
#include <Arduino.h>
#include <string>
#include "EstadoBuild.hpp"

ConexionTravis::ConexionTravis(std::string url, std::string usuario, std::string nombre_repo, std::string token){
    url_ = url;
    nombre_repo_ = nombre_repo;
    token_ = token;
    usuario_ = usuario;
    estado = DESCONECTADO;
}

EstadoBuild ConexionTravis::ObtenerEstado(){
    HTTPClient http;
    std::string url_concat = "https://api.travis-ci.com/repo/" + usuario_ + "%2F" + nombre_repo_ + "/branch/master";
    std::string token_concat = "token " + token_;
    http.begin(url_concat.c_str());
    http.addHeader("Travis-API-Version", "3");
    http.addHeader("Authorization",  token_concat.c_str());
    int httpCode = http.GET();
    Serial.println(httpCode);

    if (httpCode > 0){ 
        String payload = http.getString();
        //Serial.println(payload);
        int comienzo = payload.indexOf("state") + 9;
        int fin = payload.indexOf(",", comienzo) - 1;
        String state = (payload.substring(comienzo, fin));
        //Serial.println(state);
        estado = DefinirEstado(state.c_str());
        //Serial.println(estado);
        return estado;      
    }else{
        http.end();
        Serial.println(estado + "x");
        return estado;
    }

}

EstadoBuild ConexionTravis::DefinirEstado(std::string state){

        std::string estadoCorrecto = "passed";
        std::string estadoIncorrecto = "failed";
        EstadoBuild estado = DESCONECTADO; 

        if(state == estadoCorrecto){
            estado = PASADO;
        }else if(state == estadoIncorrecto){
            estado = FALLIDO;
        }else{
            estado = PROGRESO;
        }

       // Serial.println(estado);
        return estado;
}


