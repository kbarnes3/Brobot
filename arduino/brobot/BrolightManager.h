#pragma once

#include "ILightManager.h"

class BrolightManager : public ILightManager
{
    public:
        virtual void ShowLights(int strength);

    private:
        static void RisingLights();
        static void ClearLights();
        static void BlinkLights();
};

