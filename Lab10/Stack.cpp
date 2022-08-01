 /* File: Stack.cpp
 *
 * Description: Implementation of a SHSL-based Stack of char with push/pop ...
 * Class Invariant: ... in a LIFO order.
 *
 * Author: Steven Wong
 * Date: July 31, 2022
 */

#include <cassert>  // For assert()
#include "Stack.h"


using namespace std;

// Constructor 
Stack::Stack() 
{
    // Initialize the head pointer to NULL
    this->head = NULL;
}

// Destructor
Stack::~Stack() 
{   
    // Start at the head of the list...
    StackNode *current = this->head;
    StackNode *next = NULL;
    
    // While there are still nodes in the stack
    while (current != NULL) 
    {
        // Save the next node
        next = current->next;
        // Delete the current node
        delete current;
        // Move to the next node
        current = next;
    }
}

// Insert a new element onto the top of the stack
void Stack::push(char newElement) 
{
    // Create a new StackNode
    StackNode *newNode = new StackNode(newElement);

    // Check that the new node is not NULL
    assert(newNode != NULL);

    // Set the next pointer of the new node to the current head
    newNode->next = this->head;
    // Set the head pointer to the new node
    this->head = newNode;
}

// Remove and return the top most element of the stack
char Stack::pop() 
{
    // Save the letter at the top of the stack
    char letter = this->head->letter;
    // Save the next node
    StackNode *next = this->head->next;
    // Delete the current head
    delete this->head;
    // Set the head pointer to the next node
    this->head = next;
    // Return the letter
    return letter;
}

// Retrieve and return the top most element of the stack 
char Stack::peek() const 
{
    return this->head->letter;
}

// Returns true if the Stack is empty and false otherwise
bool Stack::isEmpty() const
{
    return this->head == NULL;
}






