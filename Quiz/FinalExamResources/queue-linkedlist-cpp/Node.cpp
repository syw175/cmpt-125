// Node.cpp 
// SHSL Node of Integers 
// Steven Wong

#include <cstdio>
#include <iostream>
#include <cassert>

#include "Node.h"

using namespace std;

// Default Constructor
Node::Node() 
{
    this->next = NULL;
}

// Constructor with data given
Node::Node(int d) 
{
    this->data = d;
    this->next = NULL;
}

// Constructor with data and next given
Node::Node(int d, Node *n) 
{
    this->data = d;
    this->next = n;
}