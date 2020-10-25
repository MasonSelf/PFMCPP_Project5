#include <iostream>
#include "PlaceToCallHome.h"

int PlaceToCallHome::homeSquareFootage( int length, int width )
{
    return ( length * width );
}

void PlaceToCallHome::payRent( bool isRenter, int rent, float proRate )
{
    if( isRenter )
        std::cout << "pay the rent of $" << rent * proRate << std::endl;
}

PlaceToCallHome::PlaceToCallHome(){}

PlaceToCallHome::~PlaceToCallHome()
{
    std::cout << "don't forget to settle up on rent" << std::endl;
    PlaceToCallHome::payRent(true, 1500, .5f );
}
