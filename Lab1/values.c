/*
 * Filename: values.c
 *
 * Description: Reads a floating point value from stdin, then outputs (in this order):
 *      1. The smallest integer larger than or equal to its value.
 *      2. The nearest integer to this value, with hallway values rounded away from zero.
 *      3. The largest integer smaller than or equal to this value.
 *
 * Author: Steven Wong
 * Date: May 27, 2022
 */

#include<stdio.h>
#include<math.h>

int main(void) {
    float value = 0;
    printf("Please, enter a floating point value: ");
    scanf("%f", &value);
    printf("The smallest integer larger than or equal to %.6f is %.0f.\n", value, ceil(value));  // decimal places of ceiling
    printf("The nearest integer to %.6f is %.0f.\n", value, round(value));  // decimal places of round
    printf("The largest integer smaller than or equal to %.6f is %.0f.\n", value, floor(value));  // decimal places of floor
    return 0;
}