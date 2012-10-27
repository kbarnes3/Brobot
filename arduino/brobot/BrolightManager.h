#pragma once

#include "ILightManager.h"

class BrolightManager : public ILightManager
{
    public:
        virtual void ShowLights(int strength);
};

