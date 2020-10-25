
#include "CamperVan.cpp"
#include "HouseBoat.cpp"
#include "Building.cpp"
#include "PlaceToCallHome.cpp"
#include "WorkPlace.cpp"

struct CamperVanWrapper
{
    CamperVanWrapper( CamperVan* p ) : cvPointer( p ) {} 
    ~CamperVanWrapper()
    {
        delete cvPointer;
        cvPointer = nullptr;
    }  
    CamperVan* cvPointer = nullptr;
};

struct HouseBoatWrapper
{
    HouseBoatWrapper( HouseBoat* p ) : hbPointer( p ) {}
    ~HouseBoatWrapper()
    {
        delete hbPointer;
        hbPointer = nullptr;
    }
    HouseBoat* hbPointer = nullptr;
};

struct BuildingWrapper
{
    BuildingWrapper( Building* p ) : buildingPointer( p ) {}
    ~BuildingWrapper()
    {
        delete buildingPointer;
        buildingPointer = nullptr;
    }
    Building* buildingPointer = nullptr;
};

struct PlaceToCallHomeWrapper
{
    PlaceToCallHomeWrapper( PlaceToCallHome* p ) : placePointer( p ) {}
    ~PlaceToCallHomeWrapper()
    {
        delete placePointer;
        placePointer = nullptr;
    }
    PlaceToCallHome* placePointer = nullptr;
};

struct WorkPlaceWrapper
{
    WorkPlaceWrapper( WorkPlace* p ) : workPointer( p ) {}
    ~WorkPlaceWrapper()
    {
        delete workPointer;
        workPointer = nullptr;
    }
    WorkPlace* workPointer = nullptr;
};

