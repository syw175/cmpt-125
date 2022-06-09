/*
 * Filename: pyramid_2.c
 *
 * Description: Reads three integers within the range [1 .. 50] from stdin. These integers represent
 *              the width (x dimension), breath (y dimension) and height (z dimension) of a symmetrical
 *              rectangular-based pyramid. On stdout, render front of the pyramid.
 * 
 * 
 * Sample Input: 7 7 4
 *
 * Sample Output:  ###
 *                #...#
 *               #.....#
 *               #######
 *
 * Author: Steven Wong
 * Date: June 9, 2022
 */

#include <stdio.h>
#include <math.h> 

#include <stdio.h>
#include <math.h> 

int main(int argc, char **argv) {
    const int SIZE = 3;
    int dimensions[SIZE] = {0}; 
    int width = 7; 
    int breadth = 7; 
    int height = 4; 

    printf("Enter your width, breadth, and height values [0-50], separated by one or more spaces: ");
    // for (int i = 0; i < 3; ++i) { 
    //     scanf("%d", &dimensions[i]);
    // }

    for (int row = height; row > 0; --row) { 
        printf("\n");
        for (int i = 0; i < row; i++) { 
            printf(" ");
        }
        for (int i = 0; i < width-row-1; i++) {
            printf("#");
        }
        for (int i = 0; i < row; i++) { 
            printf(" ");
        }
    }
    printf("\n");
}