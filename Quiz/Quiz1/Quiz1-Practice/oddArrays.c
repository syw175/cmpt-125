/*
 * Filename: oddArrays.c
 *
 * Description: Quiz Practice Questions: 
 * 
 *              #1 Write a function that uses a for loop to fill an array with eight integers 
 *                 entered by a well-behaved user. 
 * 
 *              #2 Write a second function that calculates and returns the sum of all odd integers in the array.
 * 
 *              #3 Create a header file named oddArrays.h
 * 
 *              #4 Test the functions using testDriver.c
 *
 * Author: Steven Wong
 * Date: June 8, 2022
 */


#include <stdio.h> 

// Question #1
void fillArray(int arr[]) { 
    const int ARRAY_SIZE = 8; 
    int arr[ARRAY_SIZE] = {}; 

    for (int i = 0; i < ARRAY_SIZE; ++i) { 
        scanf("%d", &arr[i]);
    }
}

// Question #2 
int getOddInts(int arr[], int arrSize) { 
    int sum = 0; 

    if (size==0){ 
        return sum;
    }

    for (int i = 0; i < arrSize; ++i) { 
        if (arr[i]%2 != 0) { 
            sum += arr[i];
        }
    }
    return sum;
}


int searchForTarget(int arr[], int &target)  {
    for () { 
        return;
    }
}
return; 
return null;

