// Light test sketch

#include "Arduino.h"

const int cLights = 7;
const int rgLights[cLights] = {2, 3, 5, 7, 9, 11, 13};

void setup()
{
    for (int i = 0; i < cLights; i++)
    {
        pinMode(rgLights[i], OUTPUT);
    }
}

void loop()
{
    setLights(LOW, 0);

    delay(1000);

    setLights(HIGH, 200);

    delay(500);

    blinkLights();
    blinkLights();
    blinkLights();

    delay(2000);
}

void setLights(int value, int msDelay)
{
    for (int i = 0; i < cLights; i++)
    {
        digitalWrite(rgLights[i], value);
        delay(msDelay);
    }
}

void blinkLights()
{
    const int msDelay = 400;

    setLights(LOW, 0);
    delay(400);

    setLights(HIGH, 0);
    delay(400);

}
