/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */


#include <iostream>
#include "LeakedObjectDetector.h"
#include "Wrappers.h"
#include "CamperVan.h"
#include "HouseBoat.h"

/*
 copied UDT 3:
 */

 struct Building
{
    int buildingAge = 50;
    int buildingStories = 12;
    float lotAcreage = 1.2f;
    float roofAngle = 30.33f;
    int numWindows = 100;
    Building();
    ~Building();

    void remodel( float budget = 80000.0f, bool committeeAproval = true );
    void buildingCollapse( float age = 100, float earthquakeMag = 5.0f );
    void newRoof( float angle = 20.5f );
    int countWindows( int start, int total );

    JUCE_LEAK_DETECTOR(Building)
};

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

/*
 new UDT 4:
 with 2 member functions
 */
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
/*
 new UDT 5:
 with 2 member functions
 */
struct WorkPlace
{
    CamperVan mobileOffice;
    HouseBoat marineResearchVessel;
    Building downtownOffice;
    WorkPlace();
    ~WorkPlace();

    void boastProductivity( bool atWorkPlace, int hoursWorked );
    int determineFireCodeCapacity( int length, int width, int floors );
    void fireCodeInside( int length, int width, int floors )
    {
        std::cout << "Firecode capacity of this workplace (via fireCodeInside) is " << this->determineFireCodeCapacity(length, width, floors) << std::endl;
    }

    JUCE_LEAK_DETECTOR(WorkPlace)
};

void WorkPlace::boastProductivity( bool atWorkPlace, int hoursWorked )
{
    if( atWorkPlace )
        std::cout << "I've clocked " << hoursWorked << " hours already!" << "\n";
    else 
        std::cout << "Out of the office today" << "\n";
}
int WorkPlace::determineFireCodeCapacity( int length, int width, int floors )
{
    return ( length * width * floors );
}
WorkPlace::WorkPlace(){}
WorkPlace::~WorkPlace()
{
    std::cout << "Wow, ";
    WorkPlace::boastProductivity( true, 8 );
    std::cout << "Time to go home." << std::endl;
}

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

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */


int main()
{
    CamperVanWrapper sprinterWrapper( new CamperVan() );

    std::cout << "Let's add one jerry can to our camper." << std::endl;
    sprinterWrapper.cvPointer->numJerryCans = sprinterWrapper.cvPointer->addJerryCans(sprinterWrapper.cvPointer->numJerryCans, 3);
    std::cout << "Current number of cans is now " << sprinterWrapper.cvPointer->numJerryCans << std::endl; //orignal printout 
    sprinterWrapper.cvPointer->printCans(); //nearly identical printout via 'this' in new member function


    HouseBoatWrapper raftWrapper( new HouseBoat() );
    
    raftWrapper.hbPointer->getThereFunction(5);
    raftWrapper.hbPointer->getThereFunction(0);

    PlaceToCallHomeWrapper adventureMobileWrapper( new PlaceToCallHome() );
    WorkPlaceWrapper NYHeadquartersWrapper( new WorkPlace() );

    std::cout << "Firecode capacity of this workplace is " << NYHeadquartersWrapper.workPointer->determineFireCodeCapacity(4, 5, 6) << std::endl; //printout via outside function
    NYHeadquartersWrapper.workPointer->fireCodeInside( 4, 5, 6 ); //nearly identical printout via 'this' in new member function


    std::cout << "good to go!" << std::endl;
}

