/*
 * Node.cpp - D103-104
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of int data type.
 *
 * Modified: August 2022 
 * Author: AL
 */

#include <cstdio>    // Needed for NULL
#include "Node.h"

using namespace std; 

Node::Node( ): next( NULL ) {
}

Node::Node( int theData ) {
  data = theData;
  next = NULL;
}

Node::Node( int theData, Node * theNextNode ) {
  data = theData;
  next = theNextNode;
}
