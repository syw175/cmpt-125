/*
 * StackNode.cpp
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of char data type.
 *
 * Created on: July 31, 2022
 * Author: Steven Wong
 */

#include <cstdio>    // Needed for NULL
#include <iostream>  // for printing out data
#include "StackNode.h"


using namespace std; 


StackNode::StackNode() 
{
    this->letter = NULL;
    this->next = NULL;
}

StackNode::StackNode(char aLetter)
{
    this->letter = aLetter;
    this->next = NULL;
}

StackNode::StackNode(char aLetter, StackNode *nextNode)
{
    this->letter = aLetter;
    this->next = nextNode;
}