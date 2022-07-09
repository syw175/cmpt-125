// Test driver to validate function output of scrambled.c


#include<stdio.h>
#include"scrambled.h"


int main (int argc, char **argv) { 
    const unsigned int ARRAY_SIZE = 5;
    int arr1[] = {5,3,4,2,2};
    int arr2[] = {1,2,5,4,5};

    if (scrambled(arr1, arr2, ARRAY_SIZE) == 1) { 
        printf("\nThe arrays are the same\n");
    } else { 
        printf("\nThe arrays are different\n");
    }
}