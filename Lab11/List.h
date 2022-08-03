/*
 * List.h - D103-104 - *** Not to be modified! ***
 * 
 * Class Description: An linked list-based implementation of a List data collection class. 
 *
 * Modified on: August 2022
 * Author: AL
 */                

#pragma once

#include "Node.h"

using namespace std;

class List {

private:
    Node * head;                // Pointer to the first node (element) in the List.
    Node * tail;                // Pointer to the last node (element) in the List.
    unsigned int elementCount;  // Current number of elements in List.
	
public:
    // Default constructor
    // Not to be modified!
    List();

    // Destructor
    // Not to be modified!
    ~List();

    // Description: Returns the current number of elements in the List.
    // Postcondition: List unchanged.
    // Time Efficicency: O(1)
    // Not to be modified!
    unsigned int getElementCount() const;
    
    // Description: Inserts "newElement" at the back of the List 
    //              and returns true if successful, false otherwise.
    // Time Efficicency: O(1)
    // Not to be modified!    
    bool insertAtBack( int newElement );
    
    // Description: Removes the element from the front of the List 
    //              and returns true if successful, false otherwise. 
    // Precondition: List is not empty.
    // Time Efficicency: O(1)
    bool removeAtFront( );
    
    // Description: Returns via the parameter the element at the back of the List
    //              and returns true if successful, false otherwise. 
    // Precondition: List is not empty.
    // Postcondition: List unchanged.
    // Time Efficicency: O(1)
    bool getBackElement( int * backElement ) const;

    // Description: Prints all elements in the List.
    // Postcondition: List unchanged.
    // Time Efficicency: O(n)
    // Not to be modified!
    void displayList() const;   

};
