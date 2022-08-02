/*
 * List.cpp  ***Using a SHSL list***
 * 
 * Class Description: An linked list-based List data collection in which
 *                    List position of elements start at 1 (not 0). 
 *
 * Inspired on: May 2016 (from CMPT 225 textbook)
 * Modified on: Aug 2, 2022
 * Author: Steven Wong
 */                 

#include <iostream>
#include <cassert>
#include <stdio.h>

#include "List.h"

using namespace std;


// Helper method - Private
Node * List::getNodeAt(int position) const 
{
    Node* current = head;
    for (int i = 1; i < position; i++)
    {
        current = current->next;
    }
    return current;
}


 // Default constructor
List::List() 
{
    head = NULL;
    elementCount = 0;
}

// Copy constructor - deep copy
List::List(const List& lst) 
{
    head = NULL;
    elementCount = 0;
    Node* current = lst.head;
    while (current != NULL)
    {
        insert(elementCount + 1, current->data);
        current = current->next;
    }
}

// Destructor
List::~List()
{
    Node* current = head;
    Node* temp;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        delete temp;
    }
}

    // Description: Returns the current number of elements in the List.
int List::getElementCount() const
{
    return this->elementCount;
}

// Description: Inserts "newElement" at "newPosition" in the List 
//              and returns true if successful, false otherwise. 
bool List::insert(int newPosition, int newElement) 
{
    if (newPosition < 1 || newPosition > elementCount + 1)
    {
        return false;
    }
    Node* newNode = new Node(newElement);
    if (newPosition == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node* previous = getNodeAt(newPosition - 1);
        newNode->next = previous->next;
        previous->next = newNode;
    }
    elementCount++;
    return true;
}

// Description: Removes the element at "position" in the List
//              and returns true if successful, false otherwise. 
// Precondition: 1 <= "position" <= getElementCount().
bool List::remove(int position) 
{
    if (position < 1 || position > elementCount)
    {
        return false;
    }
    if (position == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Node* previous = getNodeAt(position - 1);
        Node* temp = previous->next;
        previous->next = temp->next;
        delete temp;
    }
    elementCount--;
    return true;
}

// Description: Returns the element at "position" in the List.
// Precondition: 1 <= position <= getElementCount().
// Postcondition: List unchanged.
int List::getElement(int position) const
{
    assert(position >= 1 && position <= elementCount);
    return getNodeAt(position)->data;
}

// Description: Prints all elements in the List as well as its "elementCount".
// Postcondition: List unchanged.
void List::displayList() const 
{
    Node* current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    cout << "Element count: " << elementCount << endl;
}