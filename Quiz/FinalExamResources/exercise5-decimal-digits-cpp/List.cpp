// Program: List.cpp
// Description: An array based list class 
//	Date: August 15, 2022
//	Name: Steven Wong

#include <cstdio>

#include "List.h"

using namespace:std;

// Default Constructor
List::List()
{
    this->elementCount = 0;
    this->data = new int[DEFAULT_CAPACITY];
}

// Deep Copy
List::List (const List& lst)
{
    
}



// Destructor
List::~List()
{
    delete this->data;
}

// Get Element Count In the List
int List::getElementCount() const
{
    return this->elementCount;
}

// Insert "newElement" at "position" in the List and returns
// true if successful, false otherwise
bool List::insert(int newElement, int position)
{
    // Check if position is valid 
    if (position < 0 || position > this->getElementCount())
    {
        return false;
    }


}




