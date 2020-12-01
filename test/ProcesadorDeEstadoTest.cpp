#include "ProcesadorDeEstado.cpp"
#include "ControladorLedMock.cpp"
#include "ControladorBuzzerMock.cpp"
#include <unity.h>
#include <Arduino.h>

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}


void test_inicializa_desconectado(void){

    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
   // ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock);
    
    TEST_ASSERT_FALSE(controlador_led_mock->ledVerdeEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledRojoEncendido());
    TEST_ASSERT_TRUE(controlador_led_mock->ledAmarilloEncendido());
};


void test_estado_correcto_luz_verde_encendida(void){

    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ControladorBuzzerMock *controlador_buzzer_mock = new ControladorBuzzerMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock, controlador_buzzer_mock);
    procesador_de_estado->cambiarEstadoBuild(PASADO);

    TEST_ASSERT_TRUE(controlador_led_mock->ledVerdeEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledRojoEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledAmarilloEncendido());
};

void test_estado_incorrecto_luz_roja_encendida(void){

    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ControladorBuzzerMock *controlador_buzzer_mock = new ControladorBuzzerMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock, controlador_buzzer_mock);
    procesador_de_estado->cambiarEstadoBuild(FALLIDO);

    TEST_ASSERT_FALSE(controlador_led_mock->ledVerdeEncendido());
    TEST_ASSERT_TRUE(controlador_led_mock->ledRojoEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledAmarilloEncendido());

};

void test_cambio_estado_pasado_a_fallido(void){

    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ControladorBuzzerMock *controlador_buzzer_mock = new ControladorBuzzerMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock, controlador_buzzer_mock);
    procesador_de_estado->cambiarEstadoBuild(FALLIDO);
    procesador_de_estado->cambiarEstadoBuild(PASADO);

    TEST_ASSERT_TRUE(controlador_led_mock->ledVerdeEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledRojoEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledAmarilloEncendido());

};

void test_cambio_estado_fallido_a_pasado(){
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ControladorBuzzerMock *controlador_buzzer_mock = new ControladorBuzzerMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock, controlador_buzzer_mock);
    procesador_de_estado->cambiarEstadoBuild(PASADO);
    procesador_de_estado->cambiarEstadoBuild(FALLIDO);

    TEST_ASSERT_FALSE(controlador_led_mock->ledVerdeEncendido());
    TEST_ASSERT_TRUE(controlador_led_mock->ledRojoEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledAmarilloEncendido());

};

void test_cambio_estado_pasado_a_desconectado(){
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ControladorBuzzerMock *controlador_buzzer_mock = new ControladorBuzzerMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock, controlador_buzzer_mock);
    procesador_de_estado->cambiarEstadoBuild(PASADO);
    procesador_de_estado->cambiarEstadoBuild(DESCONECTADO);

    TEST_ASSERT_FALSE(controlador_led_mock->ledVerdeEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledRojoEncendido());
    TEST_ASSERT_TRUE(controlador_led_mock->ledAmarilloEncendido());

};

void test_cambio_estado_desconectado_a_pasado(){
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ControladorBuzzerMock *controlador_buzzer_mock = new ControladorBuzzerMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock, controlador_buzzer_mock);
    procesador_de_estado->cambiarEstadoBuild(DESCONECTADO);
    procesador_de_estado->cambiarEstadoBuild(PASADO);
    
    TEST_ASSERT_TRUE(controlador_led_mock->ledVerdeEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledRojoEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledAmarilloEncendido());

};

void test_cambio_estado_desconectado_a_fallido(){

    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ControladorBuzzerMock *controlador_buzzer_mock = new ControladorBuzzerMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock, controlador_buzzer_mock);
    procesador_de_estado->cambiarEstadoBuild(PASADO);
    procesador_de_estado->cambiarEstadoBuild(FALLIDO);

    TEST_ASSERT_FALSE(controlador_led_mock->ledVerdeEncendido());
    TEST_ASSERT_TRUE(controlador_led_mock->ledRojoEncendido());
    TEST_ASSERT_FALSE(controlador_led_mock->ledAmarilloEncendido());

};


void test_build_en_progreso_parpadea_led_verde(){
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ControladorBuzzerMock *controlador_buzzer_mock = new ControladorBuzzerMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock, controlador_buzzer_mock);
    procesador_de_estado->cambiarEstadoBuild(PROGRESO);
    
    TEST_ASSERT_EQUAL_INT(4,controlador_led_mock->cantidadParpadeosEncendidosVerdes());

};

void test_exitoso_a_fallido_suena_buzzer(){
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ControladorBuzzerMock *controlador_buzzer_mock = new ControladorBuzzerMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock, controlador_buzzer_mock);
    procesador_de_estado->cambiarEstadoBuild(PASADO);
    procesador_de_estado->cambiarEstadoBuild(FALLIDO);
    
    TEST_ASSERT_EQUAL_INT(1,controlador_buzzer_mock->cantidad_de_sonidos_generados());

};

void test_exitoso_a_fallido_a_exitoso_suena_buzzer(){
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ControladorBuzzerMock *controlador_buzzer_mock = new ControladorBuzzerMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock, controlador_buzzer_mock);
    procesador_de_estado->cambiarEstadoBuild(PASADO);
    procesador_de_estado->cambiarEstadoBuild(FALLIDO);
    procesador_de_estado->cambiarEstadoBuild(PASADO);
    
    TEST_ASSERT_EQUAL_INT(2,controlador_buzzer_mock->cantidad_de_sonidos_generados());

};

void test_fallido_a_exitoso_a_fallido_a_exitoso_suena_buzzer(){
    ControladorLedMock *controlador_led_mock = new ControladorLedMock();
    ControladorBuzzerMock *controlador_buzzer_mock = new ControladorBuzzerMock();
    ProcesadorDeEstado *procesador_de_estado = new ProcesadorDeEstado(controlador_led_mock, controlador_buzzer_mock);
    procesador_de_estado->cambiarEstadoBuild(FALLIDO);
    procesador_de_estado->cambiarEstadoBuild(PASADO);
    procesador_de_estado->cambiarEstadoBuild(FALLIDO);
    procesador_de_estado->cambiarEstadoBuild(PASADO);
    
    TEST_ASSERT_EQUAL_INT(3,controlador_buzzer_mock->cantidad_de_sonidos_generados());

};



void setup()
{
    UNITY_BEGIN();
    RUN_TEST(test_inicializa_desconectado);
    RUN_TEST(test_estado_correcto_luz_verde_encendida);
    RUN_TEST(test_estado_incorrecto_luz_roja_encendida);
    RUN_TEST(test_cambio_estado_pasado_a_fallido);
    RUN_TEST(test_cambio_estado_fallido_a_pasado);
    RUN_TEST(test_cambio_estado_pasado_a_desconectado);
    RUN_TEST(test_cambio_estado_desconectado_a_pasado);
    RUN_TEST(test_cambio_estado_desconectado_a_fallido);
    RUN_TEST(test_build_en_progreso_parpadea_led_verde);
    RUN_TEST(test_exitoso_a_fallido_suena_buzzer);
    RUN_TEST(test_exitoso_a_fallido_a_exitoso_suena_buzzer);
    RUN_TEST(test_fallido_a_exitoso_a_fallido_a_exitoso_suena_buzzer);
    UNITY_END(); // stop unit testing
}

void loop(){
}