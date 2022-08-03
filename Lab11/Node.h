/*
 * Node.h - D103-104
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of int data type.
 *
 * Modified: August 2022 
 * Author: AL
 */
 
#pragma once

class Node {
	
public:

  // Data members
  int data;      // The data in the node
  Node * next;   // Pointer to next node
	
  // Method members - Constructors
  Node( );
  Node( int theData );
  Node( int theData, Node * theNextNode );

}; // end Node
