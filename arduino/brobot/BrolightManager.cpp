#include "Arduino.h"
#include "IdleLights.h"
#include "LightUtils.h"
#include "Timeout.h"
#include "pins.h"
#include "BrolightManager.h"

int s_iMaxStrength = 0;
int s_iCurrentStrength = 0;
int s_blinkCount = 0;
const int s_maxBlinkCount = 3;

void BrolightManager::ShowLights(int strength)
{
    if ((strength < 1) || (strength > 5))
    {
        return;
    }

    s_iMaxStrength = strength;
    s_iCurrentStrength = 0;
    s_blinkCount = 0;

    clearTimeouts();
    RisingLights();
}

void BrolightManager::RisingLights()
{
    int newLight = rgLights[s_iCurrentStrength];
    digitalWrite(newLight, HIGH);

    s_iCurrentStrength++;

    if (s_iCurrentStrength < s_iMaxStrength)
    {
        setTimeout(TimerId::Brolight, 200, &BrolightManager::RisingLights);
    }
    else
    {
        setTimeout(TimerId::Brolight, 500, &BrolightManager::ClearLights);
    }
}

void BrolightManager::ClearLights()
{
    setLights(rgLights, s_iMaxStrength, LOW);

    if (s_blinkCount < s_maxBlinkCount)
    {
        setTimeout(TimerId::Brolight, 400, &BrolightManager::BlinkLights);
    }
    else
    {
        setupIdleLights();
    }
}

void BrolightManager::BlinkLights()
{
    unsigned long clearDelay = 400;
    setLights(rgLights, s_iMaxStrength, HIGH);
    s_blinkCount++;

    if (s_blinkCount >= s_maxBlinkCount)
    {
        clearDelay = 1000;
    }

    setTimeout(TimerId::Brolight, clearDelay, &BrolightManager::ClearLights);
}

