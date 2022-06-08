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
 * Date: June 7, 2022
 */


/* To-Do... get the integers from the user
 * 
 * 
 */


#include<stdio.h>

int getArrayMax(int arr[], int arrSize) { 
    int max = 0;
    for (int i = 1; i < arrSize; ++i) { 
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// To-Do
int getArraySize(int arr[]) { 
    int size = 0;

    return size;
}

int main (int argc, char **argv) { 
    // unsigned int arr[80] = {0};
    // int result = 0;
    // int index = 0;
    // printf("Enter your integer values separated by one or more spaces "); 

    // while ((result = scanf("%d", &arr[index])) != EOF && result < 80) { 
    //     index++;
    // }

    // for (int i = 0; i < 80; i++) { 
    //     printf("\n%d", arr[i]);
    // }

    int arr[] = {5, 15, 16, 15, 12, 12, 12, 0, 8, 7, 15, 7, 7, 12};
    int max = 16;
    int size = 14;
    for (int row = max; row > 0; --row) { 
        for (int space = 0; space < size; space++) { 
            if(arr[space] >= row) { 
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }  
}