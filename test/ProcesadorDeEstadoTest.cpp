#include "gtest/gtest.h"
#include "ProcesadorDeEstadoLed.hpp"
#include "ControladorLedMock.cpp"


TEST(ProcesadorDeEstadoLed, inicializa_desconectado){

    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ProcesadorDeEstadoLed *procesador_de_estado = new ProcesadorDeEstadoLed(controlador_led_mock);
    
    EXPECT_FALSE(controlador_led_mock->ledVerdeEncendido());
    EXPECT_FALSE(controlador_led_mock->ledRojoEncendido());
    EXPECT_TRUE(controlador_led_mock->ledAmarilloEncendido());
};