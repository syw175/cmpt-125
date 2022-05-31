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
    int temp = 0;
    int numList[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    const int SIZE = 10;

    // Take string of 10 numbers as input 
    // Perhaps use strtok to split numbers into an array of 10 integers?
    // // Type cast to String or what does scanf receive? 

    // Use int temp to swap positions in the array
    for (int i = 0; i < SIZE/2; i++) { 
        temp = numList[i]; 
        printf("Before swapping: %d %d\n", numList[i], numList[SIZE-i-1]);
        numList[i] = numList[SIZE-i-1];
        numList[SIZE-i-1] = temp;
        printf("After swapping: %d %d\n", numList[i], numList[SIZE-i-1]);
    }
    // printf("Please, enter 10 integers then press Enter:\n");
    // scanf("")

    // test printing array
    for (int index = 0; index < 10; index++) { 
        printf("%d\n", numList[index]);
    }

    return 0;
}





