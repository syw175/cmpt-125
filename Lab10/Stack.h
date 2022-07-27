 /* File: Stack.h
 *
 * Description: Implementation of a SHSL-based Stack of char with push/pop ...
 * Class Invariant: ... in a LIFO order.
 *
 * Author: Steven Wong
 * Date: July 26, 2022
 */

#pragma once
#include "StackNode.h"


class Stack { 

private:
    // Some Data Structure
    char data;
    StackNode *head;

public: 
    // Constructor 
    Stack();

    // Destructor 
    ~Stack();

    // Insert a new element onto the top of the stack
    void push(char newElement);

    // Remove and return the top most element of the stack
    char pop(void); 

    // Retrieve and return the top most element of the stack 
    char peek(void) const; 

    // Returns true if the Stack is empty and false otherwise
    bool isEmpty(void) const;
};