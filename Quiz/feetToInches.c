// Exercise completed as preparation for Quiz 3 
// July 13, 2022

#include <stdio.h> 

int feetToInches(int feet, int inches);

int main (void) { 
    int myFeet = 5;
    int myInches = 6;
    printf("Now testing feetToInches with feet: %d, inches: %d\n", myFeet, myInches);
    printf("Expected: 66 inches\n Actual: %d inches\n", feetToInches(myFeet, myInches));

    return 0;
}


int feetToInches(int feet, int inches) { 
    return (feet*12) + inches;
}