#pragma once
#include "LeakedObjectDetector.h"

struct HouseBoat
{
    int numEngines, numRooms, numLifeJackets;
    float deckArea, boatLength;
    struct ReturnToShore
    {
        int nautMilesRemaining = 1;
        ReturnToShore( int n ) : nautMilesRemaining(n) {}
    };

    ReturnToShore getThereFunction( int curDistance );
    HouseBoat();
    ~HouseBoat();

    void moveBoat( float knotsperGallon, float windknots );
    void rockInWaves( int swell = 10 );
    void scarePelicans( int crewSize = 7, float crewVoiceVolume = 80.1f, float boatSpeed = 30.f);

    JUCE_LEAK_DETECTOR(HouseBoat)
};


