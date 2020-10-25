
#include "LeakedObjectDetector.h"


struct PlaceToCallHome
{
    CamperVan rvHome;
    HouseBoat yachtHome;
    Building apartmentHome;
    PlaceToCallHome();
    ~PlaceToCallHome();

    int homeSquareFootage( int length, int width);
    void payRent( bool isRenter, int rent, float proRate );

    JUCE_LEAK_DETECTOR(PlaceToCallHome)
};
