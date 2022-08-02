// Selection sort test


#include <stdio.h>


insertionSort(int *arr, int size);

int main (void)
{ 
	int arr[] = {1, 5, 12, 10, 12, 15};
	insertionSort(arr);
} 



insertionSort(int *arr, int size) 
{
	for (int i = 1; i < size; i++) 
	{ 
		int unsorted = arr[i];
		int j = i -1;
		while (j >= 0 && unsorted > arr[j]) 
		{ 
			arr[j + 1] = arr[j]; 
			{
				int 
			}
		} 
	}
} 
