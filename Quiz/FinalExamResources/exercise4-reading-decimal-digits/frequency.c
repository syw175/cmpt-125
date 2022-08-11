// Program: frequency.c
// Description: Read 15 decimal digits in an array (A decimal digit is an integer between 0-9)
//				Output a 2-column list where the first column called Digit, is a list of distinct
//				digits that appeared in the array. The second column is called Frequency is  the number
//				of occurences of each decimal digit in the array.
//	Date: August 9, 2022
//	Name: Steven Wong


#include <stdio.h>
#include <stdlib.h>


// Function prototype
void printFrequency(int input[], int frequency[], int size);
void readInput(int input[], int size);
int* countFrequency(int input[], int size);

int main(void)
{
  int test[] = {1, 4, 6, 5, 4, 3, 7, 7, 8, 3, 5, 7, 4, 3, 2};
  int frequency[] = {0, 1, 1, 3, 3, 2, 1, 3, 1, 0};
  printFrequency(test, frequency, 10);

  // Another test
  printf("Now testing with my own numbers");
  const int size = 15;
  int array[size];
  readInput(array, size);
  int* myFrequency = countFrequency(array, size);
  printFrequency(array, myFrequency, size);

  return 0;
}


// For printing results
void printFrequency(int input[], int frequency[], int size)
{
  printf("You have entered the following 15 decimal digits: ");

  // Testing only
  for (int i = 0; i < 15; i++)
  {
	printf("%i ", input[i]);
  }

  printf("\n\n");

  printf("Digits\tFrequency\n");
  for (int i = 0; i < size; i++)
  {
	  if (frequency[i] != 0)
	  {
	    printf("%i\t%i", i, frequency[i]);
      printf("\n");
    }
  }

  return;
}


// For reading input from the user
void readInput(int input[], int size)
{
  printf("Please, enter 15 decimal digits. A decimal digit is any integer from 0 to 9.\n");
  printf("You will need to repeat some or all of them.\n");
  printf("Once you are done, press 'ENTER': ");

  // Catch errors here later...
  for (int i = 0; i < size; i++)
  {
    scanf("%u", &input[i]);
  }

  return;
}


// For counting the frequency of integers in an array
int* countFrequency(int input[], int size)
{
  const int nums = 9;
  int *frequency = malloc(nums * sizeof(int));

  for (int i = 0; i < size; i++)
  {
    frequency[input[i]]++;
  }

  return frequency;
}


