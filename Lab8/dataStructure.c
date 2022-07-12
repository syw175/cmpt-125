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


// Ready for Final Checks
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


// Ready for Final Checks
/*
 * Description: Frees all memory used by the data structure pointed to by "list". 
 *              Returns OK.
 * Time Efficiency: O(n)
 */ 
result_t list_destroy( list_t* list ) {

  // Check if the list is NULL, return error 
  if (list == NULL) {
    printf( "Error: list_destroy(...) called with NULL list.\n" );
    return NULL_PARAM;
  }

  // Free list if element count is 0 or list is empty 
  if (list->elementCount == 0) { 
    free(list);
    return OK;
  }

  // Does this work?
  element_t *currentNode = list->head;
  while (currentNode != NULL) { 
    element_t *nextNode = currentNode->next;
    free(currentNode);
    currentNode = nextNode;
    list->elementCount--;
  }

  // Free the memory allocated to the list
  // free(currentNode);
  // free(currentNode);
  free(list);
  return OK;
}


// Ready for Final Checks
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


// Ready for Final Checks
/* Description: Appends a new element, i.e., a node containing "newElement", 
 *              to this data structure pointed to by "list" and returns OK. 
 *              If "newElement" cannot be appended, leaves the 
 *              data structure unmodified and returns ERROR.
 *              Returns NULL_PARAM if "list" is NULL.
 * Time efficiency: O(1)
 */
result_t list_append( list_t* list, int newElement ) {
	
  // Check if the list is NULL, return error
  if (list == NULL) { 
    return NULL_PARAM;
  }

  // Create a new node with the integer newElement
  element_t *toAppendElement = element_create(newElement);

  // If memory allocation for new element failed, return ERROR
  if (toAppendElement == NULL) { 
    return ERROR;
  }

  // If list is empty, set head to the new element
  if (list->head == NULL) { 
    list->head = toAppendElement;
  }

  // If list is not empty, append to the end of the list
  if (list->tail) {
    list->tail->next = toAppendElement;
  }

  // Set the tail to the new element
  list->tail = toAppendElement;
  // Increment element count 
  list->elementCount++;
  return OK;
}


// Ready for Final Checks
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


// Ready for Final Checks
// Revision: What happens if there's only 1 element? Do I have to do anything with the tail?
/* Description: Removes the front (first) element (node) in the data 
 *              structure pointed to by "list" and returns OK. 
 *              If no elements (no nodes) can be removed, leaves the 
 *              data structure unmodified and returns ERROR.
 *              Returns NULL_PARAM if "list" is NULL.
 * Time efficiency: O(1)
 */
result_t list_removeFront( list_t* list ) {

  // Check if the list is NULL, return NULL_PARAM
  if (list == NULL) { 
    return NULL_PARAM;
  }

  // Check if the list is empty, return ERROR
  if (list->elementCount <= 0) { 
    return ERROR;
  }

  // Get a pointer to the next element from the head
  element_t *toBeRemoved = list->head;

  // Set the head to the next element
  list->head = toBeRemoved->next;
  // Free the memory allocated to the element
  free(toBeRemoved);  

  // Decrement element count
  list->elementCount--;
  return OK;
}
							

// Ready for Final Checks
/* Description: Returns a pointer to the element (i.e., to the node) at 
 *              "position" in the data structure pointed to by "list". 
 *              The head of "list" is at "position" 0, the first element 
 *              (node) in "list" is at "position" 1, etc. Returns NULL 
 *              if "position" is out of range. Returns NULL if "list" is NULL.
 *              This function does not modify the data structure.
 * Time efficiency: O(n)
 */ 
element_t* list_get( list_t* list, unsigned int position ){

  // Initialize the element to NULL
  element_t* anElement = NULL;

  // Check if the list is NULL, return NULL
  if (list == NULL) { 
    return anElement;
  }

  // Check if the position is out of range, return NULL
  if (list->elementCount <= position) {
    return anElement;
  }

  // Set the element to the head of the list
  int currentIndex = 0;
  element_t *currentElement = list->head;

  // Loop through the list until the element is found
  while (currentElement != NULL) { 
    // If the current index is the position, set the element to the current element and return it
    if (currentIndex == position) { 
      anElement = currentElement; 
      return anElement;
    }
    // Increment the current index and set the current element to the next element
    currentElement = currentElement->next;
    currentIndex++;
  }

  // Return the element if found, return NULL if not found
  return anElement;
}


// Ready for Final Checks
/* Description: Returns a pointer to the element (i.e., to the node) that 
 *              contains the first occurrence of "targetElement" in the data 
 *              structure pointed to by "list". Returns NULL if "targetElement"
 *              is not found. Returns NULL if "list" is NULL.
 *              This function does not modify the data structure.
 * Time efficiency: O(n)
 */ 
element_t* list_find( list_t* list, int targetElement ) {
  // Initialize placeholder value for a element_t
  element_t* anElement = NULL; 

  // Traverse the linked list if not NULL or EMPTY
  if (list->head != NULL && list->elementCount > 0) {

    //
    element_t *current = list->head;

  // Traverse the linked list until the end is reached or the target element is found
    do { 
      // If the current element's value is equal to the target element, set the placeholder to the current element
      if (current->val == targetElement) { 
        anElement = current;
        // Break out of the loop
        return anElement;
      }
      // Move to the next element
      current = current->next;
 
    } while (current != NULL);
  }
  
  return anElement;
}


// Ready for Final Checks
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
