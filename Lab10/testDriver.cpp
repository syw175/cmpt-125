// Description: Test Driver to test Stack.cpp
// Author: Steven Wong
// Date: July 31, 2022


#include <cassert>  // for assert 
#include "Stack.h"

using namespace std;


int main() 
{
    // Create a new Stack
    Stack *theStack = new Stack();

    // Assert that the stack is empty
    assert(theStack->isEmpty() == true);

    // Push a new element ('3') onto the stack
    theStack->push('3');

    // Assert that the top element in the stack is 3
    assert(theStack->peek() == '3');

    // Assert that the stack is not empty 
    assert(theStack->isEmpty() == false);

    // Pop the top element off the stack
    theStack->pop(); 

    // Assert that the stack is empty
    assert(theStack->isEmpty() == true);

    // Push a new element ('3') onto the stack
    theStack->push('3'); 

    // Assert that the top element in the stack is 3
    assert(theStack->peek() == '3');

    // Push a new element ('5') onto the stack
    theStack->push('5');

    // Assert that the top element in the stack is 5
    assert(theStack->peek() == '5');

    // Push a new element ('9') onto the stack
    theStack->push('9');

    // Assert that the top element in the stack is 9
    assert(theStack->peek() == '9');

    // Push a new element ('1') onto the stack
    theStack->push('1');

    // Assert that the top element in the stack is 1
    assert(theStack->peek() == '1');
    return 0;
}
