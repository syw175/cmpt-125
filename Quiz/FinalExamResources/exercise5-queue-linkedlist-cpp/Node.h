// Node.h 
// SHSL Node of Integers

#pragma once
class Node 
{
    public: 
        int data;
        Node *next;

        // Default Constructor  
        Node();
        
        // Constructor with data
        Node(int d);

        // Constructor with data and next
        Node(int d, Node *n);
};