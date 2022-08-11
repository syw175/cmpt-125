// Program: print-stars.c
// Description: Grab input from standard in, use a function to recursively print a pattern of stars
// Date: August 9, 2022
// Name: Steven Wong

#include <stdio.h>

// Function prototype
void printStars(unsigned int startingStars, unsigned int maxStars);


int main (void)
{
  int start = 1;
  int max = 5;

  printStars(start, max);
  return 0;
}


void printStars(unsigned int startingStars, unsigned int maxStars)
{
  // Base case:
  if (startingStars == maxStars)
  {
    for (int i = 0; i < startingStars; i++)
    {
      printf("*");
    }
	  return;
  }
  // Recursive case
  else
  {
    for (int i = 0; i < startingStars; i++)
    {
      printf("*");
    }
    printf("\n");
    printStars(startingStars + 1, maxStars);
  }
}
