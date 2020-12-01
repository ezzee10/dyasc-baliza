#include "gtest/gtest.h"
#include "ProcesadorDeEstado.hpp"
#include "ControladorLedMock.cpp"


TEST(ProcesadorDeEstado, inicializa_desconectado){

    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock);
    
    EXPECT_FALSE(controlador_led_mock->ledVerdeEncendido());
    EXPECT_FALSE(controlador_led_mock->ledRojoEncendido());
    EXPECT_TRUE(controlador_led_mock->ledAmarilloEncendido());
};

TEST(ProcesadorDeEstado, estado_correcto_luz_verde_encendida){
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock);
    procesador_de_estado->cambiarEstadoBuild(PASADO);

    EXPECT_TRUE(controlador_led_mock->ledVerdeEncendido());
    EXPECT_FALSE(controlador_led_mock->ledRojoEncendido());
    EXPECT_FALSE(controlador_led_mock->ledAmarilloEncendido());

};

TEST(ProcesadorDeEstado, estado_incorrecto_luz_roja_encendida){
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock);
    procesador_de_estado->cambiarEstadoBuild(FALLIDO);

    EXPECT_FALSE(controlador_led_mock->ledVerdeEncendido());
    EXPECT_TRUE(controlador_led_mock->ledRojoEncendido());
    EXPECT_FALSE(controlador_led_mock->ledAmarilloEncendido());

};

TEST(ProcesadorDeEstado, estado_incorrecto_luz_roja_encendida){
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock);
    procesador_de_estado->cambiarEstadoBuild(FALLIDO);

    EXPECT_FALSE(controlador_led_mock->ledVerdeEncendido());
    EXPECT_TRUE(controlador_led_mock->ledRojoEncendido());
    EXPECT_FALSE(controlador_led_mock->ledAmarilloEncendido());

};


TEST(ProcesadorDeEstado, cambio_estado_pasado_a_fallido){
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock);
    procesador_de_estado->cambiarEstadoBuild(FALLIDO);
    procesador_de_estado->cambiarEstadoBuild(PASADO);

    EXPECT_TRUE(controlador_led_mock->ledVerdeEncendido());
    EXPECT_FALSE(controlador_led_mock->ledRojoEncendido());
    EXPECT_FALSE(controlador_led_mock->ledAmarilloEncendido());

};

TEST(ProcesadorDeEstado, cambio_estado_fallido_a_pasado){
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock);
    procesador_de_estado->cambiarEstadoBuild(PASADO);
    procesador_de_estado->cambiarEstadoBuild(FALLIDO);

    EXPECT_FALSE(controlador_led_mock->ledVerdeEncendido());
    EXPECT_TRUE(controlador_led_mock->ledRojoEncendido());
    EXPECT_FALSE(controlador_led_mock->ledAmarilloEncendido());

};

TEST(ProcesadorDeEstado, cambio_estado_pasado_a_desconectado){
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock);
    procesador_de_estado->cambiarEstadoBuild(PASADO);
    procesador_de_estado->cambiarEstadoBuild(DESCONECTADO);

    EXPECT_FALSE(controlador_led_mock->ledVerdeEncendido());
    EXPECT_FALSE(controlador_led_mock->ledRojoEncendido());
    EXPECT_TRUE(controlador_led_mock->ledAmarilloEncendido());

};

TEST(ProcesadorDeEstado, cambio_estado_desconectado_a_pasado){
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock);
    procesador_de_estado->cambiarEstadoBuild(PASADO);
    procesador_de_estado->cambiarEstadoBuild(DESCONECTADO);

    EXPECT_TRUE(controlador_led_mock->ledVerdeEncendido());
    EXPECT_FALSE(controlador_led_mock->ledRojoEncendido());
    EXPECT_FALSE(controlador_led_mock->ledAmarilloEncendido());

};

TEST(ProcesadorDeEstado, cambio_estado_desconectado_a_fallido){
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock);
    procesador_de_estado->cambiarEstadoBuild(PASADO);
    procesador_de_estado->cambiarEstadoBuild(FALLIDO);

    EXPECT_FALSE(controlador_led_mock->ledVerdeEncendido());
    EXPECT_TRUE(controlador_led_mock->ledRojoEncendido());
    EXPECT_FALSE(controlador_led_mock->ledAmarilloEncendido());

};

TEST(ProcesadorDeEstado, build_en_progreso_parpadea_led_verde){
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock);
    procesador_de_estado->cambiarEstadoBuild(PROGRESO);
    
    ASSERT_EQ(4,controlador_led_mock->cantidadParpadeosEncendidosVerdes());

};

