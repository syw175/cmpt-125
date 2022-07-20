// Dicking around with binary search 


#include <stdio.h>
 

int binarySearch(int arr[], int target, int low, int high); 

int main (void) 
{ 
	int arr[] = {1, 2, 5, 7, 9, 12, 15, 20, 21, 25, 29};
	int searchTarget; 
	printf("Give me a target to search for");
	scanf("%d", &searchTarget);

	for (int i = 0; i < 10; i++) 
	{
		printf("%d ", arr[i]); 
	}
	printf("\n");



	if (binarySearch(arr, searchTarget, 0, 10)) 
	{ 
		printf("Target was found\n");  
	} else { 
		printf("Target wasn't found\n");
	}

	return 0; 
}


int binarySearch(int arr[], int target, int low, int high) 
{ 
	if (low > high)
	{
		return 0; 
	} 

  	int middle = low + ((high - low) / 2);
	if (target == arr[middle])
	{ 
		return 1;

	} else if (target < arr[middle]) { 
		return binarySearch(arr, target, low, middle-1); 
	
	} else { 
		return binarySearch(arr, target, middle+1, high);
	}
}

