/*
 * List.h  ***Using a heap-allocated array***
 * 
 * Class Description: An array-based List data collection in which
 *                    List position of elements start at 1 (not 0). 
 *
 * Inspired on: May 2016 (from CMPT 225 textbook)
 * Modified on: July 2022
 * Author: AL
 */

#pragma once
#include <iostream>
using namespace std;


class List {

private:
   static const int DEFAULT_CAPACITY = 5; // Default capacity of array 
   int *elements;                         // Array of elements
   unsigned int elementCount;             // Current number of elements in List
   
public:
   // Default constructor
   List();
   
   // Copy constructor - deep copy
   List(const List& lst); 
	
   // Destructor
   ~List();

   // Description: Returns the current number of elements in the List.
   // Postcondition: List unchanged.
   int getElementCount() const;

   // Description: Inserts "newElement" at "newPosition" in the List 
   //              and returns true if successful, false otherwise. 
   bool insert(int newPosition, int newElement);

   // Description: Removes the element at "position" in the List
   //              and returns true if successful, false otherwise. 
   // Precondition: 1 <= "position" <= getElementCount().
   bool remove(int position);

   // Description: Removes all elements from the List.
   void removeAll();
   
   // Description: Returns the element at "position" in the List.
   // Precondition: 1 <= position <= getElementCount().
   // Postcondition: List unchanged.
   int getElement(int position) const;

   // Description: Prints all elements in the List as well as its "elementCount".
   // Postcondition: List unchanged.
   void displayList() const;   

}; // end header file List