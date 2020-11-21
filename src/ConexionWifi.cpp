#include "ConexionWifi.hpp"
#include <WiFI.h>
#include <Arduino.h>
#include <string>


ConexionWifi::ConexionWifi(std::string nombreDeRed, std::string password){
    nombreDeRed_ = nombreDeRed;
    password_ = password;
}

void ConexionWifi::ConectarRed(){

  //  Serial.println("hola");
    Serial.println(nombreDeRed_.c_str());
    Serial.println(password_.c_str());

    WiFi.begin(nombreDeRed_.c_str(), password_.c_str());

    //while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.println("Connecting to WiFi..");
    

}

bool ConexionWifi::EstaConectado(){
    return WiFi.status() == WL_CONNECTED;
}

