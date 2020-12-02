#include "ConectorWifi.hpp"
#include <WiFI.h>
#include <Arduino.h>
#include <string>


ConectorWifi::ConectorWifi(std::string nombreDeRed, std::string password){
    nombreDeRed_ = nombreDeRed;
    password_ = password;
}

void ConectorWifi::ConectarRed(){

  //  Serial.println("hola");
    Serial.println(nombreDeRed_.c_str());
    Serial.println(password_.c_str());

    WiFi.begin(nombreDeRed_.c_str(), password_.c_str());

    delay(500);

    if(!EstaConectado() && cantidadIntentos < 3){
        WiFi.begin(nombreDeRed_.c_str(), password_.c_str());
        cantidadIntentos++;
    }else{
        Serial.println("La conexión WIFI no pudo establecerse");
    }

    //while (WiFi.status() != WL_CONNECTED) {
    
    //Serial.println("Connecting to WiFi..");
    

}

bool ConectorWifi::EstaConectado(){
    return WiFi.status() == WL_CONNECTED;
}

