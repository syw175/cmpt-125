/*
 * testDriver.cpp - D103-104
 * 
 * Class Description: Tests the List data collection class.
 *
 *   *** Put your code anywhere you need! ***
 *   *** Feel free to use the existing code or modify/remove it! ***
 *
 * Modified on: August 2022
 * Author: AL and Steven Wong
 */

#include <iostream>
#include <cctype>
#include <cstdlib>
#include "List.h"

using namespace std;

int main() {

  /* Variables declaration */
  const unsigned int MIN_NUMBER_OF_ELEMENTS = 5;
  List * aList = new List(); 
  
  /* Populating the List */
  cout << "Populating the List." << endl;  
  srand( time( 0 ) );
  unsigned int limit = MIN_NUMBER_OF_ELEMENTS + rand( ) % 10;
  for ( unsigned int i = 0; i < limit; i++ )
    if ( ! aList->insertAtBack( rand( ) % 100 ) ) 
      cout << "Could not aList->insertAtBack( )." << endl;

  /* Displaying the List */ 
  cout << "Displaying the List with " << aList->getElementCount( ) << " elements." << endl; 
  aList->displayList( );


  // Removing an element from the front
  cout << "Removing the first element From the List" <<endl;
  aList->removeAtFront();
  cout << "Displaying the List with " << aList->getElementCount( ) << " elements." << endl; 
  aList->displayList( );

  // Now getting the back element
  cout << "Now getting the back element from the List" << endl;
  int *element;
  aList->getBackElement(*element);
  // cout << "The last element in the list is" << *element << endl;







  delete aList;
  aList = NULL;
 
  return 0;
}
