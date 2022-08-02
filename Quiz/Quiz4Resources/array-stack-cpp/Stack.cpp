// Array based implementation of a stack data collection created for quiz ref purposes
// LAST IN FIRST OUT
// FIRST IN LAST OUT
// Stack.cpp

#include <cstdio> // for NULL constant
#include <iostream> // for cout 

#include "Stack.h"


using namespace std;


// Constructor
// Postcondition: Stack is empty.
Stack::Stack() 
{
    elements = new int[DEFAULT_CAPACITY];
    elementCount = 0;
}


// Destructor
Stack::~Stack()
{
    delete [] elements;
}


// Description: Inserts "newElement" at the top of the Stack.
// Postcondition: "newElement" is the new topmost element; other elements unchanged.
void Stack::push(int newElement)
{  
    if (elementCount == DEFAULT_CAPACITY)
    {
        cout << "Stack is full. Cannot add new element." << endl;
    }
    else
    {
        elements[elementCount] = newElement;
        elementCount++;
    }
}


// Description: Removes and returns element at the top of the Stack.
// Precondition: Stack non empty.
// Postcondition: Topmost element is removed and returned; 
//                other elements unchanged.
int Stack::pop()
{
    if (elementCount == 0)
    {
        cout << "Stack is empty. Cannot remove element." << endl;
        return 0;
    }
    else
    {
        elementCount--;
        return elements[elementCount];
    }
}


// Description: Returns the topmost element of the stack.
// Precondition: Stack non empty.
// Postcondition: Elements unchanged (const).
int Stack::peek() const
{
    return elements[elementCount - 1];
}


// Description: Returns true if and only if Stack is empty.
// Postcondition: Elements unchanged (const).
bool Stack::isEmpty() const
{
    return this->elementCount == 0;
}
