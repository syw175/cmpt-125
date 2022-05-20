/*
 * Filename: bits.c
 *
 * Description: Outputs on stdout the memory size (in bits) of ten (10) numerical data types in C
 *
 * Author: Steven Wong
 * Date: May 27, 2022
 */


// unsigned/signed: char, short, int, long, float, double 
// sizeof
//%lu 
#include<stdio.h>

int main(void) { 
    printf("%lu", (unsigned)sizeof(char));
    printf("%lu", sizeof(char));
    printf("%lu", (unsigned)sizeof(short));
    printf("%lu", sizeof(short));
    printf("%lu", (unsigned)sizeof(int));
    printf("%lu", sizeof(int));
    printf("%lu", (unsigned)sizeof(long));
    printf("%lu", sizeof(long));
    printf("%lu", (unsigned)sizeof(float));
    printf("%lu", sizeof(float));
    printf("%lu", (unsigned)sizeof(double));
    printf("%lu", sizeof(double));

    return 0;
}

