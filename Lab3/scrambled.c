/*
 * Filename: scrambled.c
 *
 * Description: Takes two arrays of equal length that contains integer values within the range [0 .. 99].
 *              If the arrays contain the same values in any order, returns 1; otherwise, return 0. The 
 *              solution must be in O(n) time complexity, regardless of the array lengths.
 * 
 * 
 * Sample Input: #1 --> arr1 = {10,15,20}, arr2 = {10,15,20}
                 #2 --> arr1 = {99}, arr2 {99}
                 #3 --> arr1 = {10,15,20}, arr2 = {10,15,21}
                 #4 --> arr1 = {1,2,3,4,5}, arr2 = {5,3,4,2,2}
 *
 *
 * Sample Output: 
 *      #1 --> Returns 1 
 *      #2 --> Returns 1 
 *      #3 --> Returns 0
 *      #4 --> Returns 0
 *
 * Author: Steven Wong
 * Date: June 7, 2022
 */



/* TO DO
 * Verify that the time complexity is O(n).
 * 
 * 
 * 
 */


#include<stdio.h>

unsigned int scrambled (int arr1[], int arr2[], unsigned int size) { 
    // Declare two array from 0-99 to track frequency of integers.
    int arr1ValuesCounter[100] = {};
    int arr2ValuesCounter[100] = {};   

    // Iterate through argument arrays and count their values.
    for (int i = 0; i < size; ++i) { 
        arr1ValuesCounter[arr1[i]]++;
        arr2ValuesCounter[arr2[i]]++;
    }

    // Check appearance counts of arr1 integers. If they unequal, return 0; else return 1.
    for (int i = 0; i < size; ++i) { 
        if (arr1ValuesCounter[arr1[i]] != arr2ValuesCounter[arr1[i]]) {
            return 0;
        }
    }
    return 1;
}

// Test driver to validate function output.
int main (int argc, char **argv) { 
    int arr1[] = {5,3,4,2,2};
    int arr2[] = {1,2,3,4,5};

    if (scrambled(arr1, arr2, 3) == 1) { 
        printf("\nThe arrays are the same\n");
    } else { 
        printf("\nThe arrays are different\n");
    }
}