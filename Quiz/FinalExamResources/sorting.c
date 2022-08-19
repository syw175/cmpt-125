#include <stdio.h>
#include <stdlib.h>

// Prototypes
void selectionSort(int *array, int size);
void bubbleSort(int *array, int size);
void insertionSort(int *array, int size);


int main(void)
{
  const int size = 6;
  int arr1[size] = {54, 3, 5, 25, 100, 99};
  int arr2[size] = {88, 4, 6, 1, 52, 100};
  int arr3[size] = {1, 5, 6, 49, 36, 72};


  selectionSort(arr1, size);
  bubbleSort(arr2, size);
  insertionSort(arr3, size);

  for (int i = 0; i < size; i++)
  {
	printf("%d\t%d\t%d\n", arr1[i], arr2[i], arr3[i]);
  }

  return 0;
}

void selectionSort(int *array, int size)
{
  for (int i = 0; i < size; i++)
  {
	int min = array[i];
	int index = i;
	for (int k = i+1; k < size; k++)
	{
	  if (array[k] < min)
	  {
		min = array[k];
		index = k;
	  }
	}
	int temp = array[i];
	array[i] = array[index];
	array[index] = temp;
  }
}

void bubbleSort(int *array, int size)
{
  // Iterate through array
  for (int i = 0; i < size; i++)
  {
    for (int k = 0; k < size - i - 1; k++)
    {
      if (array[k] > array[k+1])
      {
        int temp = array[k];
        array[k] = array[k+1];
        array[k+1] = temp;
      }
    }
  }
  return;
}

void insertionSort(int *array, int size)
{
  // Assume that the first element is sorted and iterate through array
  for (int i = 1; i < size; i++)
  {
    int current = array[i];
    int j = i - 1;

    while (current < array[j] && j >=0)
    {
      array[j + 1] = array[j];
      --j;
    }
    array[j+1] = current;
  }


  return;
}



