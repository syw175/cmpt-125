/*
 * Filename: reverse.c
 *
 * Description: Reverses the contents of an array in-place without using another array.
                Integer values are given by the user are input is well-formed. 
 * 
 * Sample Input: 1 2 3 4 5 6 7 8 9 10
 * Sample Output: 
 * 
 * Content of array before reversing: 1 2 3 4 5 6 7 8 9 10
 * Content of array after reversing: 10 9 8 7 6 5 4 3 2 1
 *
 * Author: Steven Wong
 * Date: May 31, 2022
 */

#include<stdio.h> 


int main(int argc, char **argv) { 
    const int ARRAY_SIZE = 10;
    int helperValue = 0;
    int numList[ARRAY_SIZE];

    // Prompt the user to enter 10 values and assign their values into an array
    printf("Please, enter 10 integers then press Enter: ");
    for (int i = 0; i < ARRAY_SIZE; i++) { 
        scanf("%d", &numList[i]);
    }

    // Iterate through elements of array before swapping and print values
    printf("Contents of array before reversing: ");
    for (int i = 0; i < ARRAY_SIZE; i++) { 
        printf("%d ", numList[i]);
    }

    // Swap elements from outer elements to inner elements with a temp value
    for (int i = 0; i < ARRAY_SIZE/2; i++) { 
        helperValue = numList[i]; 
        numList[i] = numList[ARRAY_SIZE-i-1];
        numList[ARRAY_SIZE-i-1] = helperValue;
    }

    // Iterate through elements of array after swapping and print values
    printf("\nContents of array after reversing: ");
    for (int i = 0; i < ARRAY_SIZE; i++) { 
        printf("%d ", numList[i]);
    }
    printf("\n");

    return 0;
}





