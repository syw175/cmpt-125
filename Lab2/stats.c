/*
 * Filename: stats.c
 *
 * Description: Reads floating point values from stdin until EOF, then the program outputs: 
 *                  1. The smallest value entered by the user.
 *                  2. The largest value entered by the user.
 *                  3. The arithmetic mean of all the values entered by the user.
 *
 * Author: Steven Wong
 * Date: May 31, 2022
 */

#include<stdio.h> 

int main(int argc, char **argv) { 
    const float MAX_VALUE = 100000;
    const float MIN_VALUE = -10000;
    float max = MIN_VALUE - 1;
    float min = MAX_VALUE + 1;

    int numCount = 0;
    float sum = 0;
    float value = 0;
    int result = 0;


    do { 
        printf("Please, enter a number between %.2f and %.2f: ", MIN_VALUE, MAX_VALUE);
        result = scanf("%f", &value) == 1;

        if (value < MIN_VALUE || value > MAX_VALUE) { 
            printf("%f is invalid!\n", value);
            continue;
        }

        if (value < min) { 
            min = value;
        }

        if (value > max) { 
            max = value;
        }

        sum += value;
        numCount++;

    } while(result == 1);

    printf("\nMin: %.2f, max: %.2f, mean: %.2f\n", min, max, sum/numCount);
    return 0;
}
