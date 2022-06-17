/*
 * Filename: verticalHistogram.c
 *
 * Description: Reads integer values from stdin, separated by one or more spaces or newlines, until reaching EOF.
 *              The input contains no more than 80 values. On standard output (stdout), it renders a simple 
 *              vertical column graph representation of the input values using hash '#' characters.
 * 
 * Sample Input: #1 --> 1 1 3 1
 *               #2 --> 3 4 5
 *
 * Sample Output: 
 *      #1 -->   #
 *               #
 *             ####
 * 
 *      #2 -->   #
 *              ##
 *             ###
 *             ###
 *             ###
 *
 * Author: Steven Wong
 * Date: June 9, 2022
 */


#include<stdio.h>


int getArrayMax (int arr[], unsigned int arrSize) {
    int max = 0;
    for (int i = 0; i < arrSize; ++i) { 
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main (int argc, char **argv) {
    const int ARRAY_SIZE = 80; 
    int arr[ARRAY_SIZE];

    // Initialize counter to track values read by scanf
    unsigned int index = 0;
    printf("Enter your integer values separated by one or more spaces \n"); 

    // Read values from user until EOF or 80 integers are entered
    while (scanf("%d", &arr[index]) != EOF && index < 80) { 
        index++;
    }

    // Print vertical histogram on stdout
    int max = getArrayMax(arr, index);
    for (int row = max; row > 0; --row) { 
        for (int space = 0; space < index; space++) { 
            if(arr[space] >= row) { 
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    } 
}