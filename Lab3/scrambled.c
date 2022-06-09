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
 * Date: June 9, 2022
 */


#include<stdio.h>


unsigned int scrambled (int arr1[], int arr2[], unsigned int size) { 
    // Declare two array from [0-99] to record appearances of integers.
    int arr1ValuesCounter[100] = {0};
    int arr2ValuesCounter[100] = {0};   

    // Iterate through given arrays and count apperances of integers.
    for (int i = 0; i < size; ++i) { 
        arr1ValuesCounter[arr1[i]]++;
        arr2ValuesCounter[arr2[i]]++;
    }

    // Check equality of arr1 integers and arr2 integers appearances.
    for (int i = 0; i < size; ++i) { 
        if (arr1ValuesCounter[arr1[i]] != arr2ValuesCounter[arr1[i]]) {
            return 0;
        }
    }
    return 1;
}