#include "Wrappers.h"
#include "CamperVan.h"
#include "HouseBoat.h"
#include "Building.h"
#include "PlaceToCallHome.h"
#include "WorkPlace.h"

CamperVanWrapper::CamperVanWrapper( CamperVan* p ) : cvPointer( p ) {} 

CamperVanWrapper::~CamperVanWrapper()
{
    delete cvPointer;
    cvPointer = nullptr;
}  

HouseBoatWrapper::HouseBoatWrapper( HouseBoat* p ) : hbPointer( p ) {}

HouseBoatWrapper::~HouseBoatWrapper()
{
    delete hbPointer;
    hbPointer = nullptr;
}

BuildingWrapper::BuildingWrapper( Building* p ) : buildingPointer( p ) {}

BuildingWrapper::~BuildingWrapper()
{
    delete buildingPointer;
    buildingPointer = nullptr;
}

PlaceToCallHomeWrapper::PlaceToCallHomeWrapper( PlaceToCallHome* p ) : placePointer( p ) {}

PlaceToCallHomeWrapper::~PlaceToCallHomeWrapper()
{
    delete placePointer;
    placePointer = nullptr;
}

WorkPlaceWrapper::WorkPlaceWrapper( WorkPlace* p ) : workPointer( p ) {}

WorkPlaceWrapper::~WorkPlaceWrapper()
{
    delete workPointer;
    workPointer = nullptr;
}



