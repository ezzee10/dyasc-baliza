#include "WiFi.h"
#include <HTTPClient.h>
#include <Arduino.h>
#include "ConectorWifi.hpp"
#include "ConectorTravis.hpp"
#include "ControladorLed.hpp"
#include "ControladorBuzzer.hpp"
#include "ProcesadorDeEstado.hpp"
#include "Baliza.hpp"


const std::string nombreWifi = "Internet123";
const std::string password = "ezequiel12345";
const std::string usuario = "ezzee10";
const std::string nombrerepo = "dyasc-2020";
const std::string token = "zRb7HwgxDHQUiLjkntffsA";


ConectorWifi *conectorWifi;
ConectorTravis *conectorTravis;
ControladorLed *controladorLed;
ControladorBuzzer *controladorBuzzer;
ProcesadorDeEstado *procesadorEstado;
Baliza *baliza;

void setup(){
 
  Serial.begin(115200);
  controladorLed = new ControladorLed();
  controladorBuzzer = new ControladorBuzzer();
  procesadorEstado = new ProcesadorDeEstado(controladorLed,controladorBuzzer);
  conectorWifi = new ConectorWifi(nombreWifi, password);
  conectorTravis = new ConectorTravis
(usuario, nombrerepo, token);
  baliza = new Baliza(conectorWifi, conectorTravis, procesadorEstado);
  baliza->iniciar();
}

void loop(){

  baliza->consultarEstado();
}


