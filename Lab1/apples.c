/*
 * Filename: apples.c
 *
 * Description: Prompts the user to enter the number of apples available and to enter the number of apples each bag holds. 
 *              Echos what the user has just inputted and also print the number of bags produced and any apples leftover.
 *              Keeps prompting the user for data until EOF is reached, then print Done and exit the program.
 *
 * Author: Steven Wong
 * Date: May 24, 2022
 */

#include<stdio.h>

int main(int argc, char *argv[]) { 

    int apples = 0;
    int appleBags = 0; 
    int bagsProduced = 0;
    int applesLeft = 0;

    printf("Please, enter the number of apples available and the number of apples each bag holds: ");

    while (scanf("%d %d", &apples, &appleBags) == 2) { 
        printf("Number of apples available => %d, number of apples each bag holds => %d.\n", apples, appleBags);

        bagsProduced = apples/appleBags;
        applesLeft = apples%appleBags;

        printf("Number of bags produced => %d, number of apples left over => %d.\n", bagsProduced, applesLeft);
        printf("Please, enter the number of apples available and the number of apples each bag holds: ");

    }
    printf("\nDone\n");
    return 0;
}