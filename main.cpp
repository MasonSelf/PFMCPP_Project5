/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
		
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
		{ 
            // 2b) explicitly using 'this' inside this member function.
			std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
		}  
		
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
		
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
		
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}

#include <iostream>
/*
 copied UDT 1:
 */

struct CamperVan
{
    int numSpareTires { 1 };
    int numJerryCans { 0 };
    int numBumpStickers = { 44 };
    float windshieldBugPercentage { 0.7f };
    int personCapacity { 3 };
    CamperVan();
    ~CamperVan();

    void driveCamper( bool tankHasSomeGas = true );
    void popCamperTop( bool isRaining = false, int outsideTemperature = 70 );
    int consumeGas( float gasRemaining, bool airConditioningOn );
    int addJerryCans(int curCans, int maxCans);

    void printCans()
    {
        std::cout << "Current number of cans (via printCans) is now " << this->numJerryCans << std::endl; 
    }
};

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

/*
 copied UDT 2:
 */

struct HouseBoat
{
    int numEngines, numRooms, numLifeJackets;
    float deckArea, boatLength;
    struct ReturnToShore
    {
        int nautMilesRemaining = 1;
        ReturnToShore( int n ) : nautMilesRemaining(n) {}
    };

    ReturnToShore getThereFunction( int curDistance );
    HouseBoat();
    ~HouseBoat();

    void moveBoat( float knotsperGallon, float windknots );
    void rockInWaves( int swell = 10 );
    void scarePelicans( int crewSize = 7, float crewVoiceVolume = 80.1f, float boatSpeed = 30.f);
};

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
    CamperVan sprinter;

    //std::cout << "Let's add one jerry can to our camper." << std::endl;
    sprinter.numJerryCans = sprinter.addJerryCans(sprinter.numJerryCans, 3);
    std::cout << "Current number of cans is now " << sprinter.numJerryCans << std::endl; //orignal printout 
    sprinter.printCans(); //nearly identical printout via 'this' in new member function


    // HouseBoat raft;
    
    // raft.getThereFunction(5);
    // raft.getThereFunction(0);

    // PlaceToCallHome adventureMobile;
    WorkPlace NYHeadquarters;

    std::cout << "Firecode capacity of this workplace is " << NYHeadquarters.determineFireCodeCapacity(4, 5, 6) << std::endl; //printout via outside function
    NYHeadquarters.fireCodeInside( 4, 5, 6 );


    std::cout << "good to go!" << std::endl;
}

