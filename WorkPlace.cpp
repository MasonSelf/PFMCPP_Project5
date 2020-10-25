#include <iostream>
#include "WorkPlace.h"

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

void WorkPlace::fireCodeInside( int length, int width, int floors )
{
    std::cout << "Firecode capacity of this workplace (via fireCodeInside) is " << this->determineFireCodeCapacity (length, width, floors) << std::endl;
}

