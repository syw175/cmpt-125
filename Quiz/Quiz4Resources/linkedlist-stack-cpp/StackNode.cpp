/*
 * StackNode.cpp
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of char data type.
 *
 * Created on: July 31, 2022
 * Author: Steven Wong
 */

#include <stdio.h>  // For NULL
#include "StackNode.h"


using namespace std; 

// Default Constructor
StackNode::StackNode() 
{
    this->next = NULL;
}

// Constructor when given a char data element
StackNode::StackNode(char aLetter)
{
    this->letter = aLetter;
    this->next = NULL;
}

// Constructor when given a char data element and a pointer to a StackNode
StackNode::StackNode(char aLetter, StackNode *nextNode)
{
    this->letter = aLetter;
    this->next = nextNode;
}