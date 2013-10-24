#include "Arduino.h"
#include "IdleLights.h"
#include "Timeout.h"
#include "pins.h"

const int s_rgIdleSteps[] = {
    light1,
    light2,
    light3,
    light4,
    light5,
    light4,
    light3,
    light2,
    light1,
    };

const int s_cIdleSteps = sizeof(s_rgIdleSteps) / sizeof(s_rgIdleSteps[0]);
int s_iIdleStep = 0;

void IdleLights::Setup()
{
    s_iIdleStep = 0;
    setTimeout(TimerId::Idle, 30000, &StepIdle);
}

void IdleLights::StepIdle()
{
    if (s_iIdleStep < s_cIdleSteps)
    {
        digitalWrite(s_rgIdleSteps[s_iIdleStep], HIGH);
    }
    if (s_iIdleStep > 0)
    {
        digitalWrite(s_rgIdleSteps[s_iIdleStep - 1], LOW);
    }

    if (s_iIdleStep >= s_cIdleSteps)
    {
        Setup();
    }
    else
    {
        s_iIdleStep++;
        setTimeout(TimerId::Idle, 150, &StepIdle);
    }
}

