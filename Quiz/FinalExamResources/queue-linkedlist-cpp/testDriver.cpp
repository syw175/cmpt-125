// testDriver to test the Queue.cpp 

#include <cstdio>
#include <cassert>
#include <iostream> 

#include "Queue.h" 
#include "Node.h" 

using namespace std;

int main() 
{
    // Create a new Queue
    Queue *q = new Queue();

    // Test isEmpty()
    assert(q->isEmpty() == true);

    // Add elements to the Queue
    q->enqueue(1);
    q->enqueue(2);

    // Test the peek() function
    int frontElement;
    q->peek(&frontElement);
    assert(frontElement == 1);

    // Test the dequeue() function
    q->dequeue();
    q->peek(&frontElement);
    assert(frontElement == 2);

    // Remove all elements from the Queue
    while(!q->isEmpty())
    {
        q->dequeue();
    }

    // Test isEmpty()
    assert(q->isEmpty() == true);

    // Add 5 elements to the Queue
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);

    // Test the display function
    cout << "Expected: " << "1 2 3 4 5" << endl;
    q->display();
    cout << endl;

    // Test the delete function
    delete q;
    assert(q == NULL);
}