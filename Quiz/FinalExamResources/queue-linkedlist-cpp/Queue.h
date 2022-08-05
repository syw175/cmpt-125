/*
 * Queue.h
 *
 * Description: Linked list-based implementation of Queue data collection class.
 * Class invariant: FIFO / LILO
 *
 * Author: Steven Wong
 * Modification Date: Aug 3, 2022
 *
 */


#include <cstdio>
#include <iostream>
#include "Node.h"


#pragma once

class Queue {

  private:
    Node *head;
    Node *tail;
    int elementCount;
    

  public:

    // Constructor
    Queue( );

    // Destructor
    ~Queue( );

    // Description: Returns true if this Queue is empty otherwise false.
    // Postcondition: This Queue is unchanged.
    // Time Efficiency: O(1)
    bool isEmpty( ) const;

    // Description: Inserts "newElement" to the back of this Queue.
    //              Returns true if successful, otherwise false.
    // Time Efficiency: O(1)
    bool enqueue( int newElement );

    // Description: Removes the front element of this Queue.
    //              Returns true if successful, otherwise false.
    // Precondition: This Queue is not empty.
    // Time Efficiency: O(1)
    bool dequeue( );

    // Description: Returns (but does not remove) the front element of this Queue.
    //              Returns true if successful, otherwise false.
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged.
    // Time Efficiency: O(1)
    bool peek( int * frontElement ) const;

    // Description: Displays the contents of this Queue from front to back.
    // Postcondition: This Queue is unchanged.
    // Time Efficiency: O(n)
    void display() const;

};



