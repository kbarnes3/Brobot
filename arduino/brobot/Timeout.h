// Provides utility functions to enable asynchronously running functions at various times in the future
#pragma once

typedef void AsyncFunction();

namespace TimerId
{
    enum Enum
    {
        Idle = 0,
        Brolight,
        Max
    };
};

void checkTimers();
void setTimeout(TimerId::Enum timerId, unsigned long delay, AsyncFunction * function);
void clearTimeouts();

