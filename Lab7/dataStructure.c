/* 
 * dataStructure.c
 *
 * Provides a bound-checked data structure made of an array of integers
 * in which duplicated elements are allowed.
 *
 * The interface of this data structure includes several utility 
 * functions that operate on this array of integers as well as 
 * file i/o functions: saving into and loading from json files. 
 * 
 * Do not change this dataStructure.h file.
 *
 * Author: RV + AL 
 * Modified Date: July 2022
 * 
 * Completed by: Steven Wong
 * Completed on: July 8, 2022
*/

#include <stdlib.h> // for malloc() and for rand()
#include <stdio.h>  // for file i/o calls
#include <time.h>   // for time()
#include <string.h> // for strlen()
#include <assert.h> 
 
#include "dataStructure.h"


/* 
 * Description: Creates a new intArray_t data structure 
 *              with initial array size "size".
 *              If successful (i.e. memory allocation succeeds), 
 *              returns a pointer to a newly-allocated intArray_t. 
 *              If unsuccessful, returns a NULL pointer.
 * Time Efficiency: O(1)
 */
intArray_t* intArray_create( unsigned int size ) {

  // Allocate memory on the heap for intArray_t struct 
  intArray_t *ia = malloc( sizeof( intArray_t ) );
  if ( ia != NULL ) {

    // Set its field "size"
    ia->size = size;

    // Allocate memory on the heap for array
    ia->data = malloc( size * sizeof(int) );
    if ( ia->data == NULL ) {
      free( ia );
      ia = NULL;
    }
	else
	  // Set its field "elementCount" to zero -> empty array
	  ia->elementCount = 0;
  }
  return ia;
}


/* 
 * Description: Frees all memory allocated for "ia".
 *              If the pointer "ia" is NULL, it does nothing. 
 *              If the pointer "ia->data" is NULL, it does not 
 *              attempt to free it. Returns INTARR_OK.
 * Time Efficiency: O(1)
 */ 
intArrayResult_t intArray_destroy( intArray_t* ia ) {

  // If heap memory has been allocated for intArray_t struct ...
  if ( ia != NULL ) {
  
    // If heap memory has been allocated for array ...
    if ( ia->data != NULL ) {
      // ... then free it
      free( ia->data );
      ia->data = NULL;
    }
  
    // ... then free it.
    free( ia );
    ia = NULL;
  }

  return INTARR_OK;
}


/* Description: Appends "newElement" and returns INTARR_OK. 
 *              If "newElement" cannot be appended, leaves the 
 *              data structure unmodified and returns INTARR_ERROR.
 *              If "ia" is NULL, returns INTARR_BADPARAM.
 * Time efficiency: O(1)
 */
intArrayResult_t intArray_append( intArray_t* ia, int newElement ) {
	
  // TODO DOUBLE CHECK ESP THE EDGE INDEXES -> SEEMS OK 
  // If the array is full, do not apend and return error 
  if (ia->size <= ia->elementCount)
  {
    return INTARR_ERROR;
  }

  // If bad pointer, return error 
  if (ia == NULL) 
  { 
    return INTARR_BADPARAM; 
  }

  unsigned int indexToAppend = ia->elementCount;
  ia->data[indexToAppend] = newElement;
  ia->elementCount++;
	
  return INTARR_OK;
}


/* Description: Removes the element at "indexToBeRemoved" in the data structure
 *              and returns INTARR_OK. If the data structure was initially sorted,
 *              it does not remain sorted after removing the element at "indexToBeRemoved".
 *              If "ia" is NULL or "indexToBeRemoved" is out of bounds, returns INTARR_BADPARAM.
 * Time efficiency: O(1)
 */
intArrayResult_t intArray_remove( intArray_t* ia, unsigned int indexToBeRemoved ) {
	
  // Stubbing this function
  // This stub is to be removed when you have successfully implemented this function.
  printf( "Calling intArray_remove(...) with the parameter indexToBeRemoved -> %u.\n" , indexToBeRemoved );

  // Test the edge cases REQ.
  if (ia == NULL || ia->elementCount <= indexToBeRemoved) { 
    return INTARR_BADPARAM;
  }

  int lastElementIndex = ia->elementCount-1;
  ia->data[indexToBeRemoved] = ia->data[lastElementIndex];
  ia->elementCount--;

	
  return INTARR_OK; // You are free to modify this return statement.
}


/* Description: Modifies (overwrites) the element at "index" with "newElement"
 *              and returns INTARR_OK. If "ia" is NULL or "index" is out of bounds,
 *              returns INTARR_BADPARAM.
 * Time Efficiency: O(1)
 */
intArrayResult_t intArray_modify( intArray_t* ia, int newElement, unsigned int index ) {
	
  printf( "Calling intArray_modify(...) with the parameters newElement -> %d and index -> %u.\n" , newElement, index );
	
  if (ia == NULL || index >= ia->size) 
  { 
    return INTARR_BADPARAM;
  }

  ia->data[index] = newElement; 

  return INTARR_OK;
}


/* Description: Finds the first occurrence of "targetElement" in the data structure,
 *              sets *index to its index and returns INTARR_OK. If "targetElement" 
 *              does not occur in the data structure, leaves *index unmodified 
 *              and returns INTARR_NOTFOUND. If "ia" is NULL, returns INTARR_BADPARAM.
 * Time efficiency: O(n)
 */
intArrayResult_t intArray_find( intArray_t* ia, int targetElement, unsigned int* index ) {
    
  printf( "Calling intArray_find(...) with the parameter targetElement -> %d.\n" , targetElement );

  // Check if a valid pointer to an array was given 
  if (ia == NULL) 
  {
    return INTARR_BADPARAM;
  }

  // Check if the targetElement exists in the intArray_t
  for (int i = 0, n = ia->elementCount; i < n; i++)
  {
    if (ia->data[i] == targetElement)
    {
      *index = i;
      return INTARR_OK;
    }
  }
	
  // If not found after searching, return INTARR_NOTFOUND
  return INTARR_NOTFOUND;
}


/* Description: Sorts the data structure by value in ascending sort order 
 *              (by smallest-to-largest), such that data[i] < data[i+1] for all valid i, 
 *              then returns INTARR_OK. If "ia" is NULL, returns INTARR_BADPARAM.
 *              Works in-place: content of "ia" is sorted on return. 
 *              Sorts the array using the Bubble Sort algorithm.
 * Time efficiency: O(n^2)
 * Space efficiency: O(1)
 */
intArrayResult_t intArray_sort( intArray_t* ia ) {
	
  // TO-DO OPTIMIZE BUBBLE SORT TO STOP IF NO SWAPS WERE MADE IN A ITERATION
  printf( "Calling intArray_sort(...).\n" );

  if (ia == NULL) { 
    return INTARR_BADPARAM;
  }

  for (int i = 0; i < ia->elementCount; i++) { 
    for (int k = 0; k < ia->elementCount-i-1; k++) { 
      if (ia->data[k] > ia->data[k+1]) { 
        int buffer = ia->data[k]; 
        ia->data[k] = ia->data[k+1];
        ia->data[k+1] = buffer;
      }
    }
  }
	
  return INTARR_OK;
}
							

/* Description: Returns a duplicate copy of "ia", allocating new storage 
 *              for this duplicate data (we call this a "deep copy"). 
 *              If unsuccessful (i.e. memory allocation for the copy fails, 
 *              or "ia" is NULL), returns a NULL pointer. 
 */
intArray_t* intArray_copy( const intArray_t* ia ) {
  printf( "Calling intArray_copy(...).\n" );

  // Check if the passed int array is valid
  if (ia == NULL) { 
    return NULL;
  }

  unsigned int size = ia->size;
  intArray_t *intArray_copy = intArray_create(size);

  if (intArray_copy != NULL) { 
    intArray_copy->elementCount = ia->elementCount;
      for (int i = 0, n = intArray_copy->elementCount; i < n; i++) {
        intArray_copy->data[i] = ia->data[i];
      }
  }
  return intArray_copy;
}


/* Description: Prints each field (member) of the data structure "ia" and
 *              prints each element of its array field then returns INTARR_OK.
 * Time Efficiency: O(n)
 */
intArrayResult_t intArray_print( intArray_t* ia ) {

  if (ia == NULL)
  {
    return INTARR_NOTFOUND;
  }

  for (int i = 0, n = ia->elementCount; i < n; i++) 
  {
    printf("%i ", ia->data[i]);
  }
  
  return INTARR_OK;
}


/* Description: Writes (saves) the entire array "ia" into a file 
 *              called "filename" in a JSON text file format (explained below)
 *              that can be loaded by the function intArray_load_from_json(...).
 *              Returns INTARR_OK on success, or INTARR_ERROR on failure. 
 *              Empty arrays (elementCount == 0) should produce an 
 *              output file containing an empty array.
 *              If "ia" is NULL or "filename" is NULL, returns INTARR_BADPARAM.
 *
 *              The JSON output should be human-readable.
 *
 * Example: The following lines are a valid JSON file content 
 *          produced by first saving "elemenCount" (3), then
 *          each of the 3 elements contained in the array
 *          (100, 200, 300) into a file:
 * [ 
 *  3,
 *  100, 
 *  200, 
 *  300 
 * ]
 */
intArrayResult_t intArray_write_to_json( intArray_t* ia, const char* filename ) {

  printf( "Calling intArray_write_to_json(...) with the filename -> %s.\n", filename );

  // Validate parameters
  assert(ia != NULL); 
  assert(filename != NULL);

  // Open file for writing
  FILE *newFile = fopen(filename, "w");
  if (newFile == NULL) { 
    return INTARR_ERROR;
  }

  // Write to file contents of intArray_t in JSON format
  if (ia->elementCount > 0) {
    fwrite("[\n", sizeof(char), 2, newFile);
    for (int i = 0; i < ia->elementCount; i++) { 
      if (fprintf(newFile, " %d%s", ia->data[i], i < ia->elementCount-1 ? ",\n" : "\n]") < 1) { 
        fclose(newFile); 
        return INTARR_ERROR;
      }
    }
  }

  // Close file and return INTARR_OK
  fclose(newFile);
  return INTARR_OK;
}





/* Description: Loads a new array from the file called "filename", that was
 *              previously saved using intArray_write_to_json(...). The file may 
 *              contain an empty array. Returns a pointer to a newly-allocated 
 *              data structure on success (even if the array is empty), 
 *              or NULL on failure.
 *              If "filename" is NULL, returns INTARR_BADPARAM.
 */
intArray_t* intArray_load_from_json( const char* filename ) {

  // Stubbing this function
  // This stub is to be removed when you have successfully implemented this function.
  printf( "Calling intArray_load_from_json(...) with the filename -> %s.\n", filename );

  // Validate parameters 
  assert(filename != NULL);

  // Open file 
  FILE *toReadFile = fopen(filename, "r");
  if (toReadFile == NULL) { 
    return NULL;
  }



  return NULL; // You are free to modify this return statement.
}
