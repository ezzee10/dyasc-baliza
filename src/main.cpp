#include "WiFi.h"
#include <HTTPClient.h>
#include <Arduino.h>

#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif

const char *ssid = "****";
const char *password = "****";

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.println("Connecting to WiFi..");
    }

    Serial.println("Connected to the WiFi network");
}

void loop()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;                                                                 //declaro el cliente HTTP
        http.begin("https://api.travis-ci.com/repo/ezzee10%2Fdyasc-2020/branch/master"); //especifico la URL
        http.addHeader("Travis-API-Version", "3", false, false);
        http.addHeader("Authorization", "token **********", false, false);

        int httpCode = http.GET();

        if (httpCode == 200)
        { //Check for the returning code

            String payload = http.getString();
            int inicioState = payload.indexOf("state");
            String cadena = payload.substring(inicioState + 9);
            int finState = cadena.indexOf(",");
            String state = cadena.substring(0, finState - 1);
            Serial.println(state);

        }
        else
        {
            Serial.println("Error on HTTP request");
        }
        http.end();
    }
}
