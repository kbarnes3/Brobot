// Brobot 9000 sketch

#include "Arduino.h"
#include "ILightManager.h"
#include "BrolightManager.h"
#include "pins.h"

const int c_cLights = 5;
const int c_rgLights[c_cLights] = { light1, light2, light3, light4, light5 };

BrolightManager g_brolightManager;

ILightManager *g_pCurrentManager = NULL;

void setup()
{
    g_pCurrentManager = &g_brolightManager;

    for (int i = 0; i < c_cLights; i++)
    {
        pinMode(c_rgLights[i], OUTPUT);
    }

    pinMode(pushButton, INPUT);
}

void loop()
{
    int strength = 0;

    strength = measureAccel();
    g_pCurrentManager->ShowLights(strength);

}

int measureAccel()
{
    int minValue = 1023;
    unsigned long currentTick = 0;
    unsigned long endTick = 0;
    const unsigned long c_readTime = 250; // ms

    currentTick = millis();
    minValue = analogRead(accel);

    // If the minValue is > 400 (512 is roughly 0 g),
    // return immediately as nothing interesting is happening
    if (minValue > 400)
    {
        return 0;
    }

    // Otherwise sample the accelerometer as many times as possible in the next 0.250 seconds
    // and find the minimum
    endTick  = currentTick + c_readTime;
    while (currentTick < endTick)
    {
        int value = 1023;

        value = analogRead(accel);
        if (value < minValue)
        {
            minValue = value;
        }

        currentTick = millis();
    }

    // Now map minValue to a strength value between 1 and 5 and return that
    if (minValue <= 50)
    {
        return 5;
    }
    else if (minValue <= 100)
    {
        return 4;
    }
    else if (minValue <= 200)
    {
        return 3;
    }
    else if (minValue <= 300)
    {
        return 2;
    }
    else //if (minValue <= 400)
    {
        return 1;
    }

}
