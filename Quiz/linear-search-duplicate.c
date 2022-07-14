/* Description: Finds the first occurrence of "targetElement" in the data structure,
*               sets *index to its index and returns INTARR_OK. If "targetElement"
*               does not occur in the data structure, leaves *index unmodified
*               and returns INTARR_NOTFOUND. If "ia" is NULL, returns INTARR_BADPARAM.
* 
*               Time efficiency: O(n)
*/


// Rewrite it such that it returns all occurrences of the targetElement
// Answer these questions: 


// 1. Has this change affected its time efficiency? 
// The function now has to traverse the entire array to find all occurrences of the targetElement.
// The time efficiency is O(n) because it has to traverse the entire array.

// 2. Has this change affected its space efficiency?
// The function now has to allocate memory for the array of indices.


#include <stdio.h> // for printf
#include <stdlib.h> // for malloc and free


// Function prototypes
intArrayResult_t intArray_find( intArray_t* ia, int targetElement, int *index);

int main (void) { 
    // Array of integers for test
    int exampleArr[] = {1, 2, 5, 7, 12, 9, 13, 15, 20, 5, 5, 10, 100};
    int *index;
    // Test the function
    intArray_find(exampleArr, 5, index);
}

// Find all occurrences of targetElement in the data structure
intArrayResult_t intArray_find(intArray_t *ia, int targetElement, int *index) { 
    // Count the number of occurrences of targetElement in the data structure
    int instancesFound = 0;
    for (int i = 0, n = ia->elementCount; i < n; i++) { 
        if (ia->data[i] == targetElement) { 
            instancesFound++;
        }
    }

    // Allocate memory for the index array
    index = realloc(index, instancesFound * sizeof(int));

    // If the index array is NULL, return INTARR_BADPARAM
    if (index == NULL) { 
        return INTARR_BADPARAM;
    }

    // Set the index array to the indices of the targetElement
    for (int i = 0; n = ia->elementCount; i < n; i++) { 
        if (ia->data[i] == targetElement) { 
            index[i] = i;
        }
    }

    // Successful return
    return OK;

}



