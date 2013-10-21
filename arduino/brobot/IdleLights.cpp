#include "Arduino.h"
#include "IdleLights.h"
#include "Timeout.h"
#include "pins.h"

// Forward declares
void TurnOnLights();
void TurnOffLights();

void SetupIdleLights()
{
    SetTimeout(TimerId::Idle, 10000, &TurnOnLights);
}

void TurnOnLights()
{
    for (int i = 0; i < cMaxLights; i++)
    {
        digitalWrite(rgLights[i], HIGH);
    }
    SetTimeout(TimerId::Idle, 1000, &TurnOffLights);
}

void TurnOffLights()
{
    for (int i = 0; i < cMaxLights; i++)
    {
        digitalWrite(rgLights[i], LOW);
    }
    SetTimeout(TimerId::Idle, 10000, &TurnOnLights);
}
