#include "ProcesadorDeEstado.hpp"
#include "ControladorLedMock.cpp"
#include <unity.h>
#include <Arduino.h>

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}


void test_set_state(void){

    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock);
    
    TEST_ASSERT_FALSE(controlador_led_mock->ledVerdeEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledRojoEncendido());
    TEST_ASSERT_TRUE(controlador_led_mock->ledAmarilloEncendido());
};

void setup()
{
    delay(2000); // service delay
    UNITY_BEGIN();
    RUN_TEST(test_set_state);
    UNITY_END(); // stop unit testing
    UNITY_END(); // stop unit testing
}

void loop(){
}