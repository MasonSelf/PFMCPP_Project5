#include <iostream>
#include "Building.h"

void Building::remodel( float budget, bool committeAproval )
{
    float hipness;
    if (committeAproval == true ) 
        hipness = budget * .7f;
    else 
        hipness = 0.0f;
}

void Building::buildingCollapse(float age, float earthquakeMag )
{
    float fragility = age * .2f;
    if (fragility < earthquakeMag ) 
        std::cout << "doom" << std::endl;
}

void Building::newRoof( float angle )
{
    if (angle == 0.0f ) 
        std::cout << "Are you sure this won't collect rain?" << std::endl;
}

int Building::countWindows( int curCount, int total )
{
    while( curCount <= total )
    {
        std::cout << curCount << "windows" << std::endl;
        if ( curCount == 666 )
            {
                std::cout << "oh no, bad luck!" << std::endl;
                return curCount;
            }
    }
    return curCount;
}
 
Building::Building(){}

Building::~Building()
{
    std::cout << "stay true, building. see you tomorrow" << std::endl;
}



