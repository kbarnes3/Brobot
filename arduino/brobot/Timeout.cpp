#include "Arduino.h"
#include "Timeout.h"

struct TimeoutInfo
{
    AsyncFunction * targetFunction;
    unsigned long runTime;
};

TimeoutInfo s_timers[TimerId::Max] = {};

void checkTimers()
{
    unsigned long currentTick = millis();

    for (int i = 0; i < TimerId::Max; i++)
    {
        TimeoutInfo * pInfo = &(s_timers[i]);
        if (pInfo->runTime && pInfo->runTime < currentTick)
        {
            pInfo->runTime = 0;
            (*pInfo->targetFunction)();
        }
    }
}

void setTimeout(TimerId::Enum timerId, unsigned long delay, AsyncFunction * function)
{
    unsigned long currentTick = millis();
    TimeoutInfo * pInfo = &(s_timers[timerId]);

    pInfo->runTime = currentTick + delay;
    pInfo->targetFunction = function;
}

void clearTimeouts()
{
    for (int i = 0; i < TimerId::Max; i++)
    {
        s_timers[i].runTime = 0;
    }
}

