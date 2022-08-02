// Array based implementation of a stack data collection created for quiz ref purposes
// LAST IN FIRST OUT
// FIRST IN LAST OUT
// Stack.h

#include <cstdio> // for NULL constant
#include <iostream> // for cout 
#include <cassert>

#pragma once 

using namespace std;

class Stack { 
    private:
        static const int DEFAULT_CAPACITY = 5; // Default capacity of array 
        int *elements;                      // Array of elements
        unsigned int elementCount;             // Current number of elements in List


    public:
        // Default constructor
        // Postcondition: Stack is empty.
        Stack();
        

        // Destructor 
        ~Stack();


        // Description: Inserts "newElement" at the top of the Stack.
        // Postcondition: "newElement" is the new topmost element; other elements unchanged.
        void push(int newElement);


        // Description: Removes and returns element at the top of the Stack.
        // Precondition: Stack non empty.
        // Postcondition: Topmost element is removed and returned; 
        //                other elements unchanged.
        int pop();


        // Description: Returns the topmost element of the stack.
        // Precondition: Stack non empty.
        // Postcondition: Elements unchanged (const).
        int peek() const;


        // Description: Returns true if and only if Stack is empty.
        // Postcondition: Elements unchanged (const).
        bool isEmpty() const;
};