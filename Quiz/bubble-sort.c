// Implement bubble sort 
// July 13, 2022

// Answer these Questions: 
// 1. Give an example of an array which would represent the worst case scenario
//    of the time efficiency of bubble sort?

// Ans: An array of size n, where the nth value is the lowest value. {5, 4, 3, 2, 1}
// Correct!


// 2. What is the time efficiency of this worst case scenario expressed using the
//    Big O notation?

//    Ans: The time efficiency of this worst case scenario would be O(n^2)
//    Correct!


// 3. Give an example of an array which would represent the best case scenario of
//    the time efficiency of bubble sort?

//    Ans: The best case scenario of bubble sort would be O(n) where it checked and saw that no swaps were made 
//    Correct!


// 4. What is the time efficiency of this best case scenario expressed using the Big
//    O notation?

//    Ans: O(n) 
//    Correct!

// 5. What is the space efficiency of bubble sort expressed using the Big O
//    notation?

//    Ans: The space efficiency of bubble sort expressed in Big O is O(1) because no additional space is required
//    Correct!


// 6. Why is it called bubble sort?

//    Ans: Because the greatest values "bubble" to the top of the array
//    Correct!


#include <stdio.h> 


void bubbleSort(int *array, int size); 

int main (void) { 
    // Initialize array
    int size = 8;
    int arr[] = {12, 5, 100, 8, 15, 11, 20, 25};

    // Sort array
    bubbleSort(arr, size);
    
    // Print sorted array
    for (int i = 0; i < size; i++) { 
        printf("%i ", arr[i]);
    }
    printf("\n");

    return 0;
}



// Sorts an array in place with bubble sort 
void bubbleSort(int *array, int size) { 
    // Iterate through array to the (n-1)th element
    for (int i = 0; i < size; i++) { 
        // Iterate through the remaining non-sorted elements
        for (int j = 0; j < size - i - 1; j++) { 
            // If a pair of values is not sorted, then swap them
            if (array[j] > array[j+1]) { 
                printf("Now swapping %d and %d\n", array[j], array[j+1]);
                // Swap values 
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    // Return upon success
    return;
}