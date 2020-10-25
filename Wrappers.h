
#include "CamperVan.cpp"
#include "HouseBoat.cpp"

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