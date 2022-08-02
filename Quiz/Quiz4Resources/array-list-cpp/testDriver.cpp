// TestDriver for Array based List.cpp 

#include <cassert> 
#include <iostream>
#include <stdio.h>

#include "List.h"

int main () 
{
    // Create a new instance of a list on the heap
    List *list = new List();

    // Assert that the list was created on the heap 
    assert(list != NULL);

    // Assert that the new list is empty
    assert(list->getElementCount() == 0);
    
    // Insert an element at position 1
    assert(list->insert(1, 1));

    // Assert that the list now has one element
    assert(list->getElementCount() == 1);

    // Assert that the element at position 1 is 1
    assert(list->getElement(1) == 1);

    // Insert an element at position 2
    assert(list->insert(2, 2));

    // Assert that the list now has two elements
    assert(list->getElementCount() == 2);

    // Assert that the element at position 2 is 2
    assert(list->getElement(2) == 2);

    // Insert an element at position 3
    assert(list->insert(3, 3));

    // Assert that the list now has three elements
    assert(list->getElementCount() == 3);

    // Assert that the element at position 3 is 3
    assert(list->getElement(3) == 3);

    // Add an element at position 4 and 5
    assert(list->insert(4, 4));
    assert(list->insert(5, 5));

    // Check that the list now has five elements
    assert(list->getElementCount() == 5);

    // Try to insert an element at position 6
    assert(!list->insert(6, 6));

    // Check that the list still has five elements
    assert(list->getElementCount() == 5);

    // Remove the element at position 1
    assert(list->remove(1));

    // Check that the list now has four elements
    assert(list->getElementCount() == 4);

    // Check that the element at position 1 is 2
    assert(list->getElement(1) == 2);

    // Print out expected list
    std::cout << "Expected List: 2, 3, 4, 5" << std::endl;

    // Print out actual list
    list->displayList();

    // Remove all elements from the list
    list->removeAll();

    // Check that the list is now empty
    assert(list->getElementCount() == 0);

    // Printing an empty list should print nothing
    list->displayList();
    assert(std::cout << "" << std::endl);

    // Make a copy of the list
    List *copy = new List(*list);

    // Check that the copy has the same number of elements as the original
    assert(copy->getElementCount() == list->getElementCount());

    // Check that the copy has the same elements as the original
    for (int i = 0; i < list->getElementCount(); i++)
    {
        assert(copy->getElement(i + 1) == list->getElement(i + 1));
    }
    
    // Delete the original list
    delete list;
    
    return 0;
}