#include <iostream>
#include "CamperVan.h"

CamperVan::CamperVan(){}

CamperVan::~CamperVan()
{
    std::cout << "goodbye camper van. thanks for all the memories." << std::endl;
}

void CamperVan::driveCamper( bool tankHasSomeGas ) 
{
    if( tankHasSomeGas )
        std::cout << "driving..." << std::endl; 
}

void CamperVan::popCamperTop( bool isRaining, int outsideTemperature )
{
    if( isRaining == false && outsideTemperature >= 70 )
        std::cout << "pop the top!" << std::endl;
    if ( isRaining )
        std::cout << "don't pop the top, but the good news is that our windshield bug percentage, which is currently " << windshieldBugPercentage << " may go down because it is raining" << std::endl;
}

int CamperVan::consumeGas( float gasRemaining, bool airConditioningOn )
{
    if ( gasRemaining != 0.0f )
    {
        if ( airConditioningOn ) 
            {
                std::cout << "you've consumed 2 gallons of gas. consider either turning your ac off, or taking person capacity (" << personCapacity << "} down to save feul." << std::endl;
                return 2;
            }
        return 1;
    }
    std::cout << "no gas, bro" << std::endl; 
    return 0; 
}

int CamperVan::addJerryCans(int curCans, int maxCans)
{
    while( curCans < maxCans)
    {
        curCans += 1;
        if (curCans == maxCans)
        {
            std::cout << "maximum jerry can amount has been reached!" << std::endl; 
            return curCans;
        }
    }
    if ( curCans >= maxCans )
        std::cout << "There is no room for any more cans!\nConsuming a can now to make space..." << std::endl;
    curCans -= 1;
    return curCans;
}

void CamperVan::printCans()
{
    std::cout << "Current number of cans (via printCans) is now " << this->numJerryCans << std::endl; 
}
