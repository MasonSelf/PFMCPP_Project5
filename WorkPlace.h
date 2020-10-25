#pragma once
#include "LeakedObjectDetector.h"
#include "CamperVan.h"
#include "HouseBoat.h"
#include "Building.h"


struct WorkPlace
{
    CamperVan mobileOffice;
    HouseBoat marineResearchVessel;
    Building downtownOffice;
    WorkPlace();
    ~WorkPlace();

    void boastProductivity( bool atWorkPlace, int hoursWorked );
    int determineFireCodeCapacity( int length, int width, int floors );
    void fireCodeInside( int length, int width, int floors );


    JUCE_LEAK_DETECTOR(WorkPlace)
};


