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
 * Date: June 7, 2022
 */

#include <stdio.h>
#include <math.h> 

int main(int argc, char **argv) {
    // char vars[] = {"width (x)", "breadth (y)", "height (z)"}; 
    int dimensions[3] = {0}; 
    int width = 7; 
    int breadth = 7; 
    int height = 4; 


    // Validation of integers within range required? Check before submission.
    printf("Enter your width, breadth, and height values [0-50], separated by one or more spaces: ");
    for (int i = 0; i < 3; ++i) { 
        scanf("%d", &dimensions[i]);
    }

    for (int row = height; row > 0; --row) { 
        for (int column = 0; column < width; ++column) {
            // print spaces/2 of width
            for (int i = 0; i <2; i++) { 
                printf(" ");
            }

            for (int i = 0; i < width; i++) {
                printf("#");
            }

            for (int i = 0; i < 2; i++) { 
                printf(" ");
            }
        printf("\n");
        }
    }
}