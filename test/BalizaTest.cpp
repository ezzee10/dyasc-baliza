
#include "ProcesadorDeEstado.hpp"
#include "ControladorLedMock.cpp"
#include "ControladorBuzzerMock.cpp"
#include "ConectorCiMock.cpp"
#include <unity.h>
#include <Arduino.h>


//void setUp(void) {
    // set stuff up here
//}

//void tearDown(void) {
    // clean stuff up here
//}

void test_baliza_desconectada(void){

    ConectorCiMock *conectorCiMock = new ConectorCiMock();
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ControladorBuzzerMock *controlador_buzzer_mock = new ControladorBuzzerMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock, controlador_buzzer_mock);
    conectorCiMock->DefinirEstado("");
    procesador_de_estado->cambiarEstadoBuild(conectorCiMock->ObtenerEstado());

  
    TEST_ASSERT_FALSE(controlador_led_mock->ledVerdeEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledRojoEncendido());
    TEST_ASSERT_TRUE(controlador_led_mock->ledAmarilloEncendido());
    TEST_ASSERT_EQUAL_INT(0,controlador_buzzer_mock->cantidad_de_sonidos_generados());
};



void test_baliza_build_exitoso(void){

    ConectorCiMock *conectorCiMock = new ConectorCiMock();
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ControladorBuzzerMock *controlador_buzzer_mock = new ControladorBuzzerMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock, controlador_buzzer_mock);
    conectorCiMock->DefinirEstado("passed");
    procesador_de_estado->cambiarEstadoBuild(conectorCiMock->ObtenerEstado());

  
    TEST_ASSERT_TRUE(controlador_led_mock->ledVerdeEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledRojoEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledAmarilloEncendido());
    TEST_ASSERT_EQUAL_INT(0,controlador_buzzer_mock->cantidad_de_sonidos_generados());
};

void test_baliza_build_fallido(void){

    ConectorCiMock *conectorCiMock = new ConectorCiMock();
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ControladorBuzzerMock *controlador_buzzer_mock = new ControladorBuzzerMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock, controlador_buzzer_mock);
    conectorCiMock->DefinirEstado("failed");
    procesador_de_estado->cambiarEstadoBuild(conectorCiMock->ObtenerEstado());

  
    TEST_ASSERT_FALSE(controlador_led_mock->ledVerdeEncendido());
    TEST_ASSERT_TRUE(controlador_led_mock->ledRojoEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledAmarilloEncendido());
    TEST_ASSERT_EQUAL_INT(0,controlador_buzzer_mock->cantidad_de_sonidos_generados());
};

void test_baliza_build_progreso(void){

    ConectorCiMock *conectorCiMock = new ConectorCiMock();
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ControladorBuzzerMock *controlador_buzzer_mock = new ControladorBuzzerMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock, controlador_buzzer_mock);
    conectorCiMock->DefinirEstado("passed");
    procesador_de_estado->cambiarEstadoBuild(conectorCiMock->ObtenerEstado());
    conectorCiMock->DefinirEstado("started");
    procesador_de_estado->cambiarEstadoBuild(conectorCiMock->ObtenerEstado());
    
    TEST_ASSERT_EQUAL_INT(4,controlador_led_mock->cantidadParpadeosEncendidosVerdes());
    TEST_ASSERT_FALSE(controlador_led_mock->ledVerdeEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledRojoEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledAmarilloEncendido());
    TEST_ASSERT_EQUAL_INT(0,controlador_buzzer_mock->cantidad_de_sonidos_generados());
};



/*

void setup()
{
    UNITY_BEGIN();
    RUN_TEST(test_baliza_desconectada);
    RUN_TEST(test_baliza_build_exitoso);
    RUN_TEST(test_baliza_build_fallido);
    RUN_TEST(test_baliza_build_progreso);
    UNITY_END(); // stop unit testing
}

void loop(){
}

*/
