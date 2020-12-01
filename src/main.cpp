#include "WiFi.h"
#include <HTTPClient.h>
#include <Arduino.h>
#include "ConexionWifi.hpp"
#include "ConexionTravis.hpp"
#include "ControladorLed.hpp"
#include "ProcesadorDeEstado.hpp"

const std::string nombreWifi = "Internet123";
const std::string password = "ezequiel12345";
const std::string usuario = "ezzee10";
const std::string nombrerepo = "dyasc-2020";
const std::string token = "zRb7HwgxDHQUiLjkntffsA";


ConexionWifi *conexionWifi;
ConexionTravis *conexionTravis;
ControladorLed *controladorLed;
ProcesadorDeEstado *procesadorEstado;

void setup(){
 
  Serial.begin(115200);
  controladorLed = new ControladorLed();
  procesadorEstado = new ProcesadorDeEstado(controladorLed);
  conexionWifi = new ConexionWifi(nombreWifi, password);
  conexionWifi->ConectarRed();
  conexionTravis = new ConexionTravis(usuario, nombrerepo, token);
  
}

void loop(){
 // 
  EstadoBuild estado = conexionTravis->ObtenerEstado();
  procesadorEstado->cambiarEstadoBuild(estado);
}
