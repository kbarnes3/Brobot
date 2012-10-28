#pragma once

#include "ILightManager.h"

class BrolightManager : public ILightManager
{
    public:
        virtual void ShowLights(int strength);

    private:
        void ClearLights();
        void ShowSomeLights(int strength);
        void SetLights(int cLights, int value, int msDelay);
        void BlinkLights(int cLights);

};

