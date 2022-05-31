/*
 * Filename: pyramid.c
 *
 * Description: Reads three integers within the range [1 .. 20] from stdin until EOF.
 *                  1. Width (x dimension), breath (y dimension) and height (z dimension).
 *                  2. Renders a view from above the pyramid, showing its rectangular base.
 *                  3. Increases from left to right, and y increases from bottom to top.
 *                  4. Outline of the pyramid drawn in stdio with the # character.
 * 
 * Sample Input: 664
 * Sample Output: 
 *      ######
 *      #....#
 *      #....#
 *      #....#
 *      #....#
 *      ######
 *
 * Author: Steven Wong
 * Date: May 31, 2022
 */

#include<stdio.h>


int main (int argc, char **argv) { 
    const int MAX = 20;
    const int MIN = 1; 
    int width = 0;
    int breadth = 0;
    int height = 0;

    do { 
        printf("Please enter the width, breadth, and height of the desired pyramid: [%d, %d] \n", MIN, MAX);
        result = scanf("%d %d %d", &width, &breadth, &height);
        if (/// CONDITIONAL HERE!! ) {
            printf("Invalid input, please try again...")
            continue;
        }
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) { 
                if (y == 0 || y == height-1) {
                    printf("#");
                } 
                else if (x == 0 || x == width-1) {
                    printf("#");
                } else { 
                    printf(".");
                }
            }
            printf("\n");
    } while (result == 3);

    return 0;
}

