#include "Arduino.h"
#include "LightUtils.h"

void setLights(const int * const prgLights, int cLights, int value)
{
    for (int i = 0; i < cLights; i++)
    {
        digitalWrite(prgLights[i], value);
    }
}

