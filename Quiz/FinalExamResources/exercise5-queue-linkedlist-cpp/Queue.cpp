/*
 * Queue.cpp 
 * 
 * Description: Linked list-based implementation of Queue data collection class.
 * Class invariant: FIFO / LILO
 *
 * Author: Steven Wong
 * Modification Date: Aug 4, 2022
 *
 */ 


#include <cstdio>
#include <iostream>
#include <cassert>

#include "Queue.h"
#include "Node.h"

using namespace std;

// Default constructor
Queue::Queue() 
{
    this->head = NULL;
    this->tail = NULL;
    this->elementCount = 0;
}


// Destructor
Queue::~Queue()
{
    // NEED to check for memory leaks
    while(!this->isEmpty())
    {
        this->dequeue();
    }
}

// Description: Returns true if this Queue is empty otherwise false. 
// Postcondition: This Queue is unchanged.
// Time Efficiency: O(1)
bool Queue::isEmpty() const 
{
    // If elementCount is 0, then the queue is empty
    return this->elementCount == 0;
}


// Description: Inserts "newElement" to the back of this Queue.  
//              Returns true if successful, otherwise false. 
// Time Efficiency: O(1)
bool Queue::enqueue(int newElement)
{   
    // Create a new node with newElement to be inserted
    Node *newNode = new Node(newElement);

    // If memory allocation failed, return false
    if (!newNode) 
    { 
        return false;
    }

    // If queue is empty when this is called, the head and tail are both the newElement
    if (this->isEmpty())
    {
        this->head = newNode;
        this->tail = newNode;
    }

    // Otherwise, add newElement to the tail and reassign tail
    else
    {
        this->tail->next = newNode;
        this->tail = newNode;
    }

    // At this point, increment elementCount and return true
    this->elementCount++;
    return true;
}
	

// Description: Removes the front element of this Queue. 
//              Returns true if successful, otherwise false. 	
// Precondition: This Queue is not empty.  
// Time Efficiency: O(1)
bool Queue::dequeue()
{
    // If the queue is element, do not try to remove an element and return false
    if (this->isEmpty())
    {
        return false;
    }
    else
    {
        // Save a temporary pointer to the current head 
        Node *temp = this->head;
        // Set the head to the next element in the queue
        this->head = this->head->next;
        // Delete the temporary variable
        delete temp;
        // Decrement element count and return true
        this->elementCount--;
        return true;
    }
}

// Description: Returns (but does not remove) the front element of this Queue.
//              Returns true if successful, otherwise false. 
// Precondition: This Queue is not empty. 
// Postcondition: This Queue is unchanged.
// Time Efficiency: O(1)
bool Queue::peek(int *frontElement) const
{
    // If the queue is element, do not try to remove an element and return false
    if (this->isEmpty())
    {
        return false;
    }

    // Set frontElement to the front element and return true
    *frontElement = this->head->data;
    return true;
}

// Description: Displays the contents of this Queue from front to back.
// Postcondition: This Queue is unchanged.
// Time Efficiency: O(n)
void Queue::display() const
{
    Node *current = this->head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


