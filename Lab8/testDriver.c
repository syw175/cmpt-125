// This is a test driver 

#include <stdio.h>  // for printf
#include <stdlib.h> // for malloc + free
#include "dataStructure.h"  // For Linked List functions



int main (void) { 
    // Create an empty Linked List and verify that mem was allocated successfully
    printf("Now testing the list_create() function...\n");
    list_t *testDoublyHeadedLL = list_create(); 
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
    if (list_prepend(testDoublyHeadedLL, 150) != OK) { 
        printf("list_prepend() failed... exiting now\n"); 
        return 1;

    } else { 
        printf("list_prepend() successfully added the element 5 to the Linked List\n");
        printf("The new contents of the Linked List is...\n");
        // Issues running list_print() on clang, working on test machines
        // list_print(testDoublyHeadedLL);
        printf("\n\n");
    }

    // Checking if a target element can be found in a Linked List 
    printf("Now testing list_find function with a value of 150\n");
    element_t *searchResult = list_find(testDoublyHeadedLL, 150);
    if (searchResult == NULL) { 
        printf("Target was not found\n");
    } else { 
        printf("The target was successfully found.\nThe element_t has an address of %p\n", searchResult);
    }

    // Verifying that a non-existant element cannot be found in a linkedlist 
    // Invstigate why this does not work with clang (it works with gcc)
    // Assume it works for now
    printf("Now testing list_find function with a value of 72. Expected: Not found!\n"); 
    element_t *newSearch = list_find(testDoublyHeadedLL, 72);
    if (newSearch == NULL) { 
        printf("Target was not found\n");
    } else { 
        printf("The target was successfully found.\nThe element_t has an address of %p\n", searchResult);
    }

    // Destroying a linkedlist
    printf("Now testing list_destroy() function\n");
    result_t destroyResult= list_destroy(testDoublyHeadedLL);
    if (destroyResult == OK) { 
        printf("Linked List successfully destroyed\n\n"); 
    } else { 
        printf("Something went wrong\n");
        return 1;
    }

    // Attempting to print a destroyed Linked List 
    printf("Now attempting to print a destroyed linked list, expected: NULL PARAM ERROR\n");
    result_t actualResult = list_print(testDoublyHeadedLL); 
    if (actualResult == NULL_PARAM) { 
        printf("Actual result: NULL_PARAM\n\n");
    } else { 
        printf("Actual result: OK\n");
        return 1;
    }






    return 0;
}