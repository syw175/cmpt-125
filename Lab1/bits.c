/*
 * Filename: bits.c
 *
 * Description: Lab Exercise 1 -> Outputs on stdout the memory size (in bits) of ten (10) numerical data types in C
 *
 * Author: Steven Wong
 * Date: May 27, 2022
 */


// unsigned/signed: char, short, int, long, float, double 
// sizeof
//%lu 
#include<stdio.h>

int main(void) { 


    printf("%u\n", (unsigned)sizeof(char));
    printf("%lu\n", sizeof(char));
    printf("%u\n", (unsigned)sizeof(short));
    printf("%lu\n", sizeof(short));
    printf("%u\n", (unsigned)sizeof(int));
    printf("%lu\n", sizeof(int));
    printf("%u\n", (unsigned)sizeof(long));
    printf("%lu\n", sizeof(long));
    printf("%u\n", (unsigned)sizeof(float));
    printf("%lu\n", sizeof(float));
    printf("%u\n", (unsigned)sizeof(double));
    printf("%lu\n", sizeof(double));

    return 0;
}

