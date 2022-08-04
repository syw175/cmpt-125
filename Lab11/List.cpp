/*
 * List.cpp - D103-104
 * 
 * Class Description: An linked list-based implementation of a List data collection class. 
 *
 * Modified on: August 2022
 * Author: AL and Steven Wong
 */                 

#include <cstdio>   // Needed for NULL
#include <iostream>
#include <climits>  // Needed for INT_MIN and INT_MAX
#include "Node.h"
#include "List.h"

using namespace std;
	
// Default constructor
// Not to be modified!
List::List() {
  elementCount = 0;
  head = NULL;
  tail = NULL;
}

// Destructor
// Not to be modified!
List::~List() {
  while ( getElementCount() > 0 ) {
    if ( head ) {
      Node* tobeRemoved = head;
      head = head->next;
    
      tobeRemoved->next = NULL;
      delete tobeRemoved;
      tobeRemoved = NULL;
      
      if ( head == NULL ) tail = NULL;
    
      elementCount--; 
    }
  }
} 

// Description: Returns the current number of elements in the List.
// Postcondition: List unchanged.
// Time Efficicency: O(1)
// Not to be modified!
unsigned int List::getElementCount() const {
  return elementCount;
}

// Description: Inserts "newElement" at the back of the List 
//              and returns true if successful, false otherwise.
// Time Efficicency: O(1)
// Not to be modified!    
bool List::insertAtBack( int newElement ) {

  bool result = true;
  
  Node* newNode = new Node( newElement );  
  if ( newNode ) {
    
    if ( head == NULL ) // Empty List
      head = newNode;
  
    if ( tail ) // Non-empty list
      tail->next = newNode;

    tail = newNode;
      
    elementCount++; // One more element in the list
  }
  else 
    result = false;
  
  return result;
} 

// Description: Removes the element from the front of the List 
//              and returns true if successful, false otherwise. 
// Precondition: List is not empty.
// Time Efficicency: O(1)
bool List::removeAtFront( ) {

  bool result = true;
  
  // Validate that the list contains at least one element
  if (this->getElementCount() > 0) {
    // Get the first element
    Node* tobeRemoved = head;
    // Save the head's next element
    head = head->next;
    
    // Delete the first element
    tobeRemoved->next = NULL;
    delete tobeRemoved;
    tobeRemoved = NULL;
    
    // Update the tail if the list is now empty
    if ( head == NULL ) tail = NULL;
    
    // Decrement the element count
    elementCount--;
  }

  // If the list is already empty, set result to false
  else
    result = false;

  // Return the result
  return result;
} 

// Description: Returns via the parameter the element at the back of the List
//              and returns true if successful, false otherwise.
// Precondition: List is not empty.
// Postcondition: List unchanged.
// Time Efficicency: O(1)
bool List::getBackElement( int * backElement ) const {
	
  bool result = true;

  // Check that the list contains at least one element
  if (this->getElementCount() > 0) {
    // Get the last element
    *backElement = tail->data;
  }
  // Otherwise, set the result to false
  else
    result = false;
  
  // Return the result     
  return result;
}

// Description: Prints all elements in the List.
// Postcondition: List unchanged.
// Time Efficicency: O(n)
// Not to be modified!
void List::displayList() const {

  cout << "This List has " << elementCount << " elements: {";
  if ( head ) {
    Node * current = head;
    for ( unsigned int i = 1; i <= elementCount; i++ ) {
      cout << " " << current->data;
      current = current->next;
    }
  }
  cout << " }" << endl;
  return;
}
