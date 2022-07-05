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

int main (void) 
{
    
    printf("What size array do you want? "); 
    int size = scanf("%d", &size);
    intArray_t *array = intArray_create(size);


    printf("Now printing an array of size %d\n ", size);
    intArray_print(array);


    printf("Now testing the destroy array function\n");
    intArray_destroy(array);
    if (array == NULL)
    {
        printf("Array has been destroyed\n");
    }
    else 
    { 
        printf("Array destroy failed");
    }


    

}