#include "WiFi.h"
#include <HTTPClient.h>
#include <Arduino.h>
#include "ConexionWifi.hpp"
#include "ConexionTravis.hpp"
#include "ControladorLed.hpp"
#include "CambiadorDeEstadoLed.hpp"

const std::string nombreWifi = "Internet123";
const std::string password = "ezequiel12345";
const std::string usuario = "ezzee10";
const std::string nombrerepo = "dyasc-2020";
const std::string token = "zRb7HwgxDHQUiLjkntffsA";

ConexionWifi *conexionWifi;
ConexionTravis *conexionTravis;
ControladorLed *controladorLed;
CambiadorDeEstadoLed *cambiadorEstado;

void setup()
{
  Serial.begin(115200);

  controladorLed = new ControladorLed();
  cambiadorEstado = new CambiadorDeEstadoLed(controladorLed);
  conexionWifi = new ConexionWifi(nombreWifi, password);
  conexionWifi->ConectarRed();
  conexionTravis = new ConexionTravis(usuario, nombrerepo, token);
  
}

void loop()
{
  EstadoBuild estado = conexionTravis->ObtenerEstado();
  cambiadorEstado->cambiarEstadoLed(estado);
}
