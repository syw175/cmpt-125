/*
 * List.cpp  ***Using a heap-allocated array***
 * 
 * Class Description: An array-based List data collection in which
 *                    List position of elements start at 1 (not 0). 
 *
 * Inspired on: May 2016 (from CMPT 225 textbook)
 * Modified on: August 2, 2022
 * Author: Steven Wong
 */

#include <iostream>
#include <cassert>
#include "List.h"

using namespace std;


// Default constructor 
List::List() 
{
    elements = new int[DEFAULT_CAPACITY];
    elementCount = 0;
}

// Copy constructor - Deep Copy 
List::List(const List& lst) 
{
    elementCount = lst.elementCount;
    elements = new int[elementCount];
    for (int i = 0; i < elementCount; i++)
    {
        elements[i] = lst.elements[i];
    }
}

// Destructor 
List::~List() 
{
    delete [] elements;
}

// Return the current number of elements in the List 
int List::getElementCount() const
{
    return this->elementCount;
}

// Inserts "newElement" at "newPosition" in the List, return true if successful
bool List::insert(int newElement, int newPosition) 
{
    // Check if the newPosition is valid
    if (newPosition < 1 || newPosition > elementCount + 1)
    {
        return false;
    }

    // Check if the List is full
    if (elementCount == DEFAULT_CAPACITY)
    {
        return false;
    }

    // Check if the newPosition is the last position
    if (newPosition == elementCount + 1)
    {
        elements[elementCount] = newElement;
        elementCount++;
        return true;
    }

    // Shift the elements to the right to make room for the new element
    for (int i = elementCount; i >= newPosition; i--)
    {
        elements[i] = elements[i - 1];
    }

    // Insert the new element
    elements[newPosition - 1] = newElement;
    elementCount++;
    return true;
}


// Remove the element at "position" in the List, return true if successful
bool List::remove(int position) 
{
    // Assert that position is valid
    if (position < 1 || position > elementCount)
    {
        return false;
    }

    // Move all elements after position one position back
    for (int i = position; i < elementCount; i++)
    {
        this->elements[i - 1] = this->elements[i];
    }
    this->elementCount--;
    return true;

}


// Removes all elements from the List.
void List::removeAll() 
{
    // If the list is already element, return
    if (this->getElementCount() == 0)
    {
        return;
    }

    // Set the elementCount to 0    
    this->elementCount = 0;
}


// Returns the element at "position" in the List.
int List::getElement(int position) const 
{
    // Assert that position is valid
    assert(position >= 1 && position <= this->getElementCount());
    // Return the element at position
    return this->elements[position - 1];
}


// Description: Prints all elements in the List as well as its "elementCount".
void List::displayList() const 
{
    // Print the elementCount
    cout << "Element Count: " << this->getElementCount() << endl;
    // Print the elements
    for (int i = 0; i < this->getElementCount(); i++)
    {
        cout << this->getElement(i + 1) << " ";
    }
    cout << endl;
}