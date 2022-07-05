/* 
 * testDriver.c
 *
 * Description: Test the functions from dataStructure.c
 * 
 * Completed by: Steven Wong
 * Completed on: July 8, 2022
*/


#include <stdio.h>
#include "dataStructure.h"
#include <stdlib.h>  // for rand()

int main (void) 
{
    // Testing the create function 
    unsigned int size = 10;
    intArray_t *array = intArray_create(size);

    // Testing the intArray_append function
    for (int i = 0; i < size; i++) 
    {
        int val = rand(); 
        intArrayResult_t result = intArray_append(array, val); 
        if (result == INTARR_OK)
        {
            printf("Added %d to index %d\n", val, i);
        }
    }

    // Testing the intArray_print function
    printf("\nNow printing an array of size %i\n", size);
    intArray_print(array);


    // Testing the intArray_destroy array function
    printf("\nNow testing the destroy array function\n");
    intArrayResult_t newReslt = intArray_destroy(array);
    if (newReslt == INTARR_OK)
    {
        printf("Destroyed\n");
    }
}

    // WHY IS MY POINTER NOT GOING TO NULL AFTER DESTROY????
    // if (array == NULL) 
    // { 
    //     printf("ok\n");
    // }
// }