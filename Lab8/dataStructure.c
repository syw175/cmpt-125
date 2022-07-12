/* 
 * dataStructure.c
 *
 * Provides a data structure made of a doubly-headed singly-linked list (DHSL) 
 * of unsorted elements (integers) in which duplicated elements are allowed.
 * 
 * A DHSL list is comprised of a single header and zero or more elements. 
 * The header contains pointers to the first and last elements in the list,
 * or NULL if the list is empty. The first element contains a pointer to
 * the next element, and so on. The last element in the list has its
 * "next" pointer set to NULL.
 *
 * The interface of this data structure includes several utility 
 * functions that operate on this data structure.
 *
 * Precondition: Functions that operate on such data structure
 *               require a valid pointer to it as their first argument.
 *
 * Your name: Steven Wong
 * Modified Date: July 11, 2022
*/

#include <stdio.h>
#include <stdlib.h>

#include "dataStructure.h"


/* 
 * Description: Creates a new empty data structure of list_t type and 
 *              if successful, returns a pointer to it. 
 *              If unsuccessful, returns NULL.
 * Time Efficiency: O(1)
 */
list_t* list_create( void ) {
  // Initialize and allocate memory for the linked list
  list_t* aList = malloc( sizeof(list_t) );

  // Validate that memory was correctly allocated to the heap
  if (aList != NULL) { 
    // Set the head and tail of the empty linked list to NULL
    aList->head = NULL;
    aList->tail = NULL;

    // Set initial elementCount value of 0
    aList->elementCount = 0;
  }

  // Return the linkedlist... if malloc failed, a NULL pointer will be returned
  return aList;
}


//TO-DO - FUNCTION STUB
/*
 * Description: Frees all memory used by the data structure pointed to by "list". 
 *              Returns OK.
 * Time Efficiency: O(n)
 */ 
result_t list_destroy( list_t* list ) {
  printf( "Calling list_destroy(...).\n" );

  // Check if the list is NULL
  if (list == NULL) {
    printf( "Error: list_destroy(...) called with NULL list.\n" );
    return NULL_PARAM;
  }

  // TO-DO... FREE ALL ELEMENTS IN THE LINKEDLIST

  // Free the memory allocated to the list
  free(list);

  //  Do I need more? 

  
  return OK;
}


/* 
 * Description: Returns a pointer to a new element i.e., a node  
 *              containing "newElement" and a next-pointer set to NULL, 
 *              or NULL if memory allocation fails.
 * Time Efficiency: O(1)
 */
element_t* element_create( int newElement ) {

  // Allocate memory for the element
  element_t* anElement = malloc( sizeof(element_t) );

  // Validate that memory was correctly allocated to the heap and set the element's value
  if (anElement != NULL) { 
    anElement->val = newElement;
  }

  // Return the element... if malloc failed, a NULL pointer will be returned
  return anElement;
}



// TO-DO - FUNCTION STUB
/* Description: Appends a new element, i.e., a node containing "newElement", 
 *              to this data structure pointed to by "list" and returns OK. 
 *              If "newElement" cannot be appended, leaves the 
 *              data structure unmodified and returns ERROR.
 *              Returns NULL_PARAM if "list" is NULL.
 * Time efficiency: O(1)
 */
result_t list_append( list_t* list, int newElement ) {
	
  result_t result = OK;
  
  printf( "Calling list_append(...): appending newElement %d to list.\n", newElement );
  
  return result;
}


//COMPLETE DO NOT MODIFY
/* Description: Prepends a new element, i.e., a node containing "newElement", 
 *              to this data structure pointed to by "list" and returns OK. 
 *              If "newElement" cannot be prepended, leaves the 
 *              data structure unmodified and returns ERROR.
 *              Returns NULL_PARAM if "list" is NULL.
 * Time efficiency: O(1)
 */
result_t list_prepend( list_t* list, int newElement ) {
  
  result_t result = OK;

  // Returns NULL_PARAM if "list" is NULL.
  if ( list == NULL ) result = NULL_PARAM; 
  else {
	// Creates a new element (node) containing "newElement" 
    element_t* anElement = element_create( newElement );    
    if ( anElement == NULL ) result = ERROR;
    else {
      if ( list->tail == NULL ) // Empty list
        list->tail = anElement;
  
      if ( list->head ) // Non-empty list
        anElement->next = list->head;

      list->head = anElement;

      list->elementCount++; // One more element in the list
    }
  }  
  return result;
}


//TO-DO FUNCTION STUB
/* Description: Removes the front (first) element (node) in the data 
 *              structure pointed to by "list" and returns OK. 
 *              If no elements (no nodes) can be removed, leaves the 
 *              data structure unmodified and returns ERROR.
 *              Returns NULL_PARAM if "list" is NULL.
 * Time efficiency: O(1)
 */
result_t list_removeFront( list_t* list ) {
  result_t result = OK;

  printf( "Calling list_removeFront(...): remove first element at the fron of the list.\n" );
  
  return result;
}
							


// TO-DO FUNCTION STUB
/* Description: Returns a pointer to the element (i.e., to the node) at 
 *              "position" in the data structure pointed to by "list". 
 *              The head of "list" is at "position" 0, the first element 
 *              (node) in "list" is at "position" 1, etc. Returns NULL 
 *              if "position" is out of range. Returns NULL if "list" is NULL.
 *              This function does not modify the data structure.
 * Time efficiency: O(n)
 */ 
element_t* list_get( list_t* list, unsigned int position ){

  element_t* anElement = NULL;

  printf( "Calling list_get(...): getting element (node) at position %u in the list.\n", position );    
    
  return anElement;
}


// TO-DO FUNCTION STUB
/* Description: Returns a pointer to the element (i.e., to the node) that 
 *              contains the first occurrence of "targetElement" in the data 
 *              structure pointed to by "list". Returns NULL if "targetElement"
 *              is not found. Returns NULL if "list" is NULL.
 *              This function does not modify the data structure.
 * Time efficiency: O(n)
 */ 
element_t* list_find( list_t* list, int targetElement ) {

  element_t* anElement = NULL; 
  
  printf( "Calling list_find(...): find the first occurrence of targetElement %d in the list.\n", targetElement );
  
  return anElement;
}



// COMPLETE - DO NOT MODIFY 
/* Description: Prints the content of the data structure pointed to by "list",
 *              in human-readable form from the first element
 *              to the last element, between curly braces, then returns OK.
 *              Returns NULL_PARAM if "list" is NULL.
 *              This function does not modify the data structure.
 * Time Efficiency: O(n)
 */
result_t list_print( list_t* list ) {

  result_t result = OK;

  // Returns NULL_PARAM if "list" is NULL.
  if ( list == NULL ) result = NULL_PARAM;
  else {  
    printf( "This data structure has %d element%c:\n", list->elementCount,
             list->elementCount > 0 ? 's': ' ' );
    printf( "{" );
  
    // Prints each element
    for ( element_t* eachElement = list->head; eachElement; eachElement = eachElement->next )
      printf( " %d", eachElement->val );

    printf( " }\n" );
  }
  
  return result;
}
