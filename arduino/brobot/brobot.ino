// Brobot 9000 sketch

#include "Arduino.h"
#include "pins.h"

const int c_cLights = 5;
const int c_rgLights[c_cLights] = { light1, light2, light3, light4, light5 };

void setup()
{
    for (int i = 0; i < c_cLights; i++)
    {
        pinMode(c_rgLights[i], OUTPUT);
    }

    pinMode(pushButton, INPUT);
}

void loop()
{
}

