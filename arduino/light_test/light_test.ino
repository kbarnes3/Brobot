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
    for (int i = 0; i < cLights; i++)
    {
        digitalWrite(rgLights[i], HIGH);
    }

    delay(10000);
}

