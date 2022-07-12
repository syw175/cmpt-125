// This is a test driver 
// Name: Steven Wong
// Date: July 11, 2022


#include <stdio.h>  // for printf
#include <stdlib.h> // for malloc + free
#include "dataStructure.h"  // For Linked List functions


int main (void) { 

    // Create an empty Linked List and verify that mem was allocated successfully
    printf("Now testing the list_create() function...\n");
    // Create a new empty linked list
    list_t *testDoublyHeadedLL = list_create(); 
    // Check if the list was created successfully
    if (testDoublyHeadedLL == NULL) { 
        printf("list_create() failed to malloc... exiting now\n");
        return 1;

    } else { 
        printf("list_create() successfully created an empty Linked List!\n\n");
    }


    // Printing an empty Linked List  
    printf("Now testing the list_print() function...\n");
    if (list_print(testDoublyHeadedLL) != OK) { 
        printf("list_print() failed to print... exiting now\n");
        return 1;
        
    } else { 
        printf("list_print() successfully printed the correct values!\n\n");
    }


    // Creating a new element node 
    printf("Now testing the element_t create() function with value of 5...\n");
    // Create a new element node with value of 5
    element_t *newNode = element_create(5);
    if (newNode == NULL) { 
        printf("element_t create() failed to create a new element... exiting now\n");
        return 1; 

    } else { 
        printf("element_t create() successful! The element_t value is %d\n", newNode->val);
        free(newNode);
        newNode = NULL;
        printf("New element has been freed from memory.\n\n");
    }


    // Adding an element to the front of the Linked List 
    printf("Now testing the list_prepend() function with a value of 150...\n");
    // If prepend is not successful, return error
    if (list_prepend(testDoublyHeadedLL, 150) != OK) { 
        printf("list_prepend() failed... exiting now\n"); 
        return 1;

    } else { 
        printf("list_prepend() successfully added the element 5 to the Linked List\n");
        printf("The new contents of the Linked List is...\n");
        // Issues running list_print() on clang, working on test machines
        list_print(testDoublyHeadedLL);
        printf("\n\n");
    }


    // Checking if a target element can be found in a Linked List 
    printf("Now testing list_find function with a value of 150. Expected: found\n");
    // If find is not successful, return error
    element_t *searchResult = list_find(testDoublyHeadedLL, 150);
    if (searchResult == NULL) { 
        printf("Actual: Target was not found\n");
    } else { 
        printf("Actual: The target was successfully found.\nThe element_t has an address of %p\n\n", searchResult);
    }


    // Verifying that a non-existant element cannot be found in a linkedlist 
    // Invstigate why this does not work with clang (it works with gcc)
    // Assume it works for now
    printf("Now testing list_find function with a value of 72. Expected: Not found!\n"); 
    element_t *newSearch = list_find(testDoublyHeadedLL, 72);
    if (newSearch == NULL) { 
        printf("Actual: Target was not found\n\n");
    } else { 
        printf("Actual: The target was successfully found.\nThe element_t has an address of %p\n\n", searchResult);
    }


    // Prepending additional elements to the linked list
    printf("Now prepending 15, 25, 35, 45 95\nExpected result: { 95 45 35 25 150 }\n");
    list_prepend(testDoublyHeadedLL, 15);
    list_prepend(testDoublyHeadedLL, 25);
    list_prepend(testDoublyHeadedLL, 35);
    list_prepend(testDoublyHeadedLL, 45);
    list_prepend(testDoublyHeadedLL, 95);
    list_print(testDoublyHeadedLL);


    // Adding to the end of a linked list
    printf("Now appending 100 101 102 103\nExpected result: { 95 45 35 25 15 150 100 101 102 103 }\n");
    list_append(testDoublyHeadedLL, 100);
    list_append(testDoublyHeadedLL, 101);
    list_append(testDoublyHeadedLL, 102);
    list_append(testDoublyHeadedLL, 103);
    list_print(testDoublyHeadedLL);
    printf("\n");


    // Getting an element from a linkedlist at a index value
    element_t *elementAtIndexInRange;
    element_t *elementAtIndexOutOfRange; 
    // Testing a valid index value
    int indexInRange = 5; 
    // Testing an invalid index value
    int indexOutOfRange = 100;
    printf("Now getting the elements at index %i %i\n", indexInRange, indexOutOfRange);
    printf("Expected: Value at indexInRange = 150, Value at indexOutOfRange = NULL\n");
    // Testing with an index in range
    elementAtIndexInRange = list_get(testDoublyHeadedLL, indexInRange);
    // Testing with an index out of range
    elementAtIndexOutOfRange = list_get(testDoublyHeadedLL, indexOutOfRange);
    // If get is not successful, return error
    if (elementAtIndexInRange != NULL) { 
        printf("index_get() succeeded for elementAtIndexInRange! The actual value is: %i\n", elementAtIndexInRange->val);
    }  else { 
        printf("Something went wrong\n");
        return 1;
    }

    // If get is not successful, return error
    if (elementAtIndexOutOfRange == NULL) { 
        printf("index_get() succeeded for elementAtIndexOutOfRange! The actual value is NULL\n\n"); 
    } else { 
        printf("Something went wrong\n\n");
        return 1;
    }

    
    // Removing the first element from a linkedlist 
    printf("Now testing the list_removeFront() function on testDoublyHeadedLL\n");
    printf("Expected list: 9 elements and { 45 35 25 15 150 100 101 102 103 }\n");
    // Save the result of removeFront to a variable
    result_t removalResult = list_removeFront(testDoublyHeadedLL);
    // If removeFront is not successful, return error
    if (removalResult == OK) { 
        printf("First element successfully removed...\n");
        printf("Actual list is:\n"); 
        list_print(testDoublyHeadedLL);
        printf("\n");
    } else { 
        printf("Removal failed\n\n");
        return 1;
    }


    // Testing append function with an empty linkedlist
    printf("Now creating an empty list and appending one element to it\n");
    // Create an empty linkedlist
    list_t *emptyList = list_create();
    // Append an element to the empty linkedlist
    list_append(emptyList, 5);
    list_print(emptyList);
    printf("\n");


    // Removing the first element from a linked list with only one element
    printf("Now removing an element from a single element linked list\n");
    printf("Expected list: 0 elements and { }\n");
    // Save the result of removeFront to a variable
    result_t removeFromSingleElement = list_removeFront(emptyList); 
    // If removeFront is not successful, return error
    if (removeFromSingleElement == OK) { 
        printf("First element successfully removed...\n");
        printf("Actual list is:\n"); 
        list_print(emptyList);
        printf("\n");
    } else { 
        printf("Removal failed\n\n");
        return 1;
    }


    // Attemping to remove a element from a empty linkedlist
    printf("Now removing an element from an empty linked list\n");
    printf("Expect: ERROR\n");
    // Save the result of removeFront to a variable
    result_t removeFromEmpty = list_removeFront(emptyList); 
    // If removeFront is not successful, return error
    if (removeFromEmpty != OK) { 
        printf("Actual: Function correctly did not try to remove from empty\n");
        list_print(emptyList);
        printf("\n");
    } else { 
        printf("Something went wrong\n\n");
        return 1;
    }

    // Destroying a linkedlist
    printf("Now testing list_destroy() function. Expected: success\n");
    // Save the result of destroy to a variable
    result_t destroyResult= list_destroy(emptyList);
    // If destroy is not successful, return error
    if (destroyResult == OK) { 
        printf("Actual: Linked List successfully destroyed\n\n"); 
    } else { 
        printf("Actual: Something went wrong\n");
        return 1;
    }


    // Attempting to print a destroyed Linked List 
    emptyList = NULL;
    printf("Now attempting to print a destroyed linked list, Expected: NULL PARAM ERROR\n");
    // Save the result of print to a variable
    result_t actualResult = list_print(emptyList); 
    // If print is not as expected, return error
    if (actualResult == NULL_PARAM) { 
        printf("Actual: NULL_PARAM\n\n");
    } else { 
        printf("Actual: OK\n");
        return 1;
    }

    return 0;
}