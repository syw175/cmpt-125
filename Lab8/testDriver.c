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
        list_print(testDoublyHeadedLL);
    }



    return 0;
}