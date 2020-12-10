#include "ConectorWifi.hpp"
#include <WiFI.h>
#include <Arduino.h>
#include <string>


ConectorWifi::ConectorWifi(std::string nombreDeRed, std::string password){
    nombreDeRed_ = nombreDeRed;
    password_ = password;
}

void ConectorWifi::ConectarRed(){

    Serial.println(nombreDeRed_.c_str());
    Serial.println(password_.c_str());

    WiFi.begin(nombreDeRed_.c_str(), password_.c_str());

    delay(500);

    if(!EstaConectado()){
        WiFi.begin(nombreDeRed_.c_str(), password_.c_str());
        Serial.println("La conexión WIFI no pudo establecerse");
    }else{
        Serial.println("La conexión WIFI fue establecida");
    }

}

bool ConectorWifi::EstaConectado(){
    return WiFi.status() == WL_CONNECTED;
}

