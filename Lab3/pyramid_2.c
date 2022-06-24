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


int main(int argc, char **argv) {

	int width, breadth, height;
    printf("Enter your width, breadth, and height values [0-50], separated by one or more spaces: ");
    scanf("%d %d %d", &width, &breadth, &height);

    for (int j = height - 1; j >= 0 ; j--) {
        int left = floor(j*(width/(2.0*height)));
        int right = ceil((width-1) + -j*(width/(2.0*height)));

        for (int i = 0; i < width; i++) {
            if (i == left || i == right  || j == 0 ) {
            printf("#");
            }

            if ( j == (height-1) && (right-1) != left && i > left && i < right) {
                printf("#");
            }

            if (i > left && i < right && j > 0 && j != (height-1)) {
                printf(".");
            }

            if (i < left && j > 0) {
                printf(" ");
            }
        }	
        printf("\n");
    }
    return 0;
}