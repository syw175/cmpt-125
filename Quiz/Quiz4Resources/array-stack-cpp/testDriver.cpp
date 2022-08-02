// Test driver for array based Stack.cpp
// FIRST IN LAST OUT
// LAST IN FIRST OUT
// testDriver.cpp

#include <iostream>
#include <cassert>
#include "Stack.h"


int main() 
{
    // Create a new stack on the heap
    Stack *stack = new Stack();

    // Check that memory allocation did not fail
    assert(stack != NULL);

    // Check that the stack is empty
    assert(stack->isEmpty() == true);

    // Push some elements onto the stack
    stack->push(1);
    stack->push(2);

    // Check that the stack is not empty
    assert(stack->isEmpty() == false);

    // Check that the topmost element is correct
    assert(stack->peek() == 2);

    // Pop the topmost element
    stack->pop();

    // Check that the topmost element is correct
    assert(stack->peek() == 1);

    // Pop the topmost element
    stack->pop();

    // Check that the stack is empty
    assert(stack->isEmpty() == true);

    // Delete the stack
    delete stack;

    // Check that the stack is deallocated
    // assert(stack == NULL);

    return 0;
}