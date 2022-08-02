/*
 * Node.cpp
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of Grade data type.
 *
 * Created on: 
 * Author: 
 */

#include <cstdio>    // Needed for NULL
#include "Node.h"

using namespace std; 


Node::Node()
{
	next = NULL;
}

Node::Node(int theData)
{
	data = theData;
	next = NULL;
}

Node::Node(int theData, Node* theNextNode)
{
	data = theData;
	next = theNextNode;

}

// end Node.cpp