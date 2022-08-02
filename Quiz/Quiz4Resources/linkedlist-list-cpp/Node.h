/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of Grade clas type.
 *
 * Created on: August 2, 2022
 * Author: Steven Wong
 */
 
// #pragma once is shorthand for the 2 #include guards:
// #ifndef _NODE and #define _NODE
// and it means: do not include me more than once.
#pragma once

class Node {
	
public:
	// Public data members - Why are the data members public?
	int data;     // The data in the node
	Node* next;     // Pointer to next node
	
	// Constructors
	Node();
	Node(int theData);
	Node(int theData, Node* theNextNode);

}; // end Node