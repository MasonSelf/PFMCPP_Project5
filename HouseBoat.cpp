#include <iostream>
#include "HouseBoat.h"

HouseBoat::HouseBoat() :
numEngines(2),
numRooms(3),
numLifeJackets(4),
deckArea(44.4f),
boatLength(22.f)
{

}

HouseBoat::~HouseBoat()
{
    std::cout << "goodbye house boat. thanks for all the memories. now destroy your member variables..." << std::endl;
}

HouseBoat::ReturnToShore HouseBoat::getThereFunction ( int curDistance )
{
    for ( int i = curDistance; i > 0; i-- )
    {
        std::cout << "distance left: " << i << "\n";
        if (i <= 1 )
        {
            std::cout << "slow down, we're getting close" << "\n";
            return i;
        }
    }
    std::cout << "oh no! We're getting swept out to sea right as we were arriving to shore..." << "\n";
    return  HouseBoat::ReturnToShore{ 1000 };
}
    

void HouseBoat::moveBoat( float knotsperGallon, float windknots ) 
{
    float knotsTravelled = 0.0f;
    knotsTravelled += knotsperGallon - windknots;
    std::cout << "knots travelled: " << knotsTravelled << std::endl;
}

void HouseBoat::rockInWaves( int swell ) 
{
    if (swell >= 7 ) 
        std::cout << "oh dear" << std::endl; 
}

void HouseBoat::scarePelicans( int crewSize, float crewVoiceVolume, float boatSpeed )
{
    float pelicanScareRating = crewVoiceVolume * crewSize * boatSpeed;
    if (pelicanScareRating > 5.0f ) 
        std::cout << "pelicans are tripping" << std::endl; 
}
