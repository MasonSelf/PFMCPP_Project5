#pragma once

struct CamperVan;
struct HouseBoat;
struct Building;
struct PlaceToCallHome;
struct WorkPlace;

struct CamperVanWrapper
{
    CamperVanWrapper( CamperVan* p );
    ~CamperVanWrapper();
    CamperVan* cvPointer = nullptr;
};

struct HouseBoatWrapper
{
    HouseBoatWrapper( HouseBoat* p );
    ~HouseBoatWrapper();
    HouseBoat* hbPointer = nullptr;
};

struct BuildingWrapper
{
    BuildingWrapper( Building* p );
    ~BuildingWrapper();
    Building* buildingPointer = nullptr;
};

struct PlaceToCallHomeWrapper
{
    PlaceToCallHomeWrapper( PlaceToCallHome* p );
    ~PlaceToCallHomeWrapper();
    PlaceToCallHome* placePointer = nullptr;
};

struct WorkPlaceWrapper
{
    WorkPlaceWrapper( WorkPlace* p );
    ~WorkPlaceWrapper();
    WorkPlace* workPointer = nullptr;
};



