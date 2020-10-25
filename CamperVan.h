#pragma once
#include "LeakedObjectDetector.h"


struct CamperVan
{
    int numSpareTires { 1 };
    int numJerryCans { 0 };
    int numBumpStickers = { 44 };
    float windshieldBugPercentage { 0.7f };
    int personCapacity { 3 };
    CamperVan();
    ~CamperVan();

    void driveCamper( bool tankHasSomeGas = true );
    void popCamperTop( bool isRaining = false, int outsideTemperature = 70 );
    int consumeGas( float gasRemaining, bool airConditioningOn );
    int addJerryCans(int curCans, int maxCans);
    void printCans();

    JUCE_LEAK_DETECTOR(CamperVan)
};
