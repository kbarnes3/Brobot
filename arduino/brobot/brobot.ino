// Brobot 9000 sketch

#include "Arduino.h"
#include "LightUtils.h"
#include "ILightManager.h"
#include "BrolightManager.h"
#include "IdleLights.h"
#include "Timeout.h"
#include "pins.h"

BrolightManager g_brolightManager;

ILightManager *g_pCurrentManager = NULL;

void setup()
{
    g_pCurrentManager = &g_brolightManager;

    for (int i = 0; i < cMaxLights; i++)
    {
        pinMode(rgLights[i], OUTPUT);
    }

    pinMode(pushButton, INPUT);

    IdleLights::Setup();
}

void loop()
{
    int strength = 0;

    strength = measureAccel();
    g_pCurrentManager->ShowLights(strength);
    checkTimers();

}

int measureAccel()
{
    int minValue = 1023;
    unsigned long currentTick = 0;
    unsigned long endTick = 0;
    const unsigned long c_flashTime = 100; // ms
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
    clearTimeouts();
    setLights(rgLights, cMaxLights, LOW);
    endTick  = currentTick + c_readTime;
    minValue = sampleAccel(minValue, endTick);

    // Now map minValue to a strength value between 1 and 5 and return that
    if (minValue <= 100)
    {
        return 5;
    }
    else if (minValue <= 150)
    {
        return 4;
    }
    else if (minValue <= 250)
    {
        return 3;
    }
    else if (minValue <= 350)
    {
        return 2;
    }
    else //if (minValue <= 400)
    {
        return 1;
    }

}

int sampleAccel(int threshold, unsigned long endTick)
{
    int minValue = threshold;
    unsigned long currentTick = millis();

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

    return minValue;
}

