#include "Arduino.h"
#include "pins.h"
#include "BrolightManager.h"

namespace BrolightState
{
    enum Enum
    {
        Waiting = 0,
        Rising,
        Blink1,
        Clear1,
        Blink2,
        Clear2,
        Blink3,
        Clear3,
        Max
    };
};

BrolightState::Enum s_currentState = BrolightState::Waiting;

void BrolightManager::ShowLights(int strength)
{
    if ((strength < 1) || (strength > 5))
    {
        return;
    }
}

void BrolightManager::ClearLights()
{
    SetLights(cMaxLights, LOW, 0);
}

void BrolightManager::ShowSomeLights(int strength)
{
    SetLights(strength, HIGH, 200);

    delay(500);

    BlinkLights(strength);
    BlinkLights(strength);
    BlinkLights(strength);

    delay(1000);

    SetLights(cMaxLights, LOW, 0);
}

void BrolightManager::SetLights(int cLights, int value, int msDelay)
{
    for (int i = 0; i < cLights; i++)
    {
        digitalWrite(rgLights[i], value);
        delay(msDelay);
    }
}

void BrolightManager::BlinkLights(int cLights)
{
    const int msDelay = 400;

    SetLights(cLights, LOW, 0);
    delay(400);

    SetLights(cLights, HIGH, 0);
    delay(400);
}

