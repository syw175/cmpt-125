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
    printf("\nNow testing the intArray_append function with size %d\n", size);
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
    printf("\nNow testing the intArray_print function with an array of size %i\n", size);
    intArray_print(array);


    // Testing the intArray_modify function
    printf("\n\nNow testing the intArray_modify function with a index value of 2 and element of 500\n");
    if (intArray_modify(array, 500, 5) == INTARR_OK) 
    {
        printf("Result: Succeeded\n");
    }
       else 
    { 
        printf("Result: Failed\n");
    }

    printf("\nNow printing out the modified array\n");
    intArray_print(array);


    // Testing the intArray_find function 
    unsigned int search; 
    if (intArray_find(array, 500, &search) == INTARR_OK) {
        printf("\nThe value 500 was found at index %i\n", search);
    }

    // Testing the intArray_copy function
    printf("Now making a copy of the array\n");
    intArray_t *arrayCopy = intArray_copy(array);

    if (arrayCopy != NULL) { 
        printf("Array copy succeeded, now printing\n");
        intArray_print(arrayCopy);
    }


    // Testing the intArray_sort function 
    printf("\nNow testing the sort function\n");
    if (intArray_sort(arrayCopy) == INTARR_OK) { 
        printf("\nSort succeeeded, now printing\n");
        intArray_print(arrayCopy);
    }

    // Testing the intArray_remove function 
    printf("\nNow removing the value at index 2 in the copy array\n");
    if (intArray_remove(arrayCopy, 2) == INTARR_OK) { 
        printf("\nRemove succeeded, now printing\n");
        intArray_print(arrayCopy);
    }

    // Testing the intArray_destroy array function
    printf("\nNow testing the destroy array function\n");
    intArrayResult_t newReslt = intArray_destroy(array);
    if (newReslt == INTARR_OK)
    {
        printf("Result: Destroyed\n");
    }

    // Testing the intArray_write_to_json
    printf("\nNow printing to a file called: newFile\n");
    intArray_write_to_json(arrayCopy, "newFile");


 
        // WHY IS MY POINTER NOT GOING TO NULL AFTER DESTROY????
    // if (array != NULL) 
    // { 
    //     printf("ok\n");
    // }
}