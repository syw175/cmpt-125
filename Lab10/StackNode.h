/*
 * StackNode.h
 * 
 * Class Description: Nodes for a singly-linked list in which the data is a char.
 *
 * Author: Steven Wong
 * Date: July 26, 2022
 */

#pragma once

class StackNode {

public: 

    // Class data members
    char letter;
    StackNode *next;

    // Constructor 
    StackNode();
    StackNode(char aLetter);
    StackNode(char aLetter, StackNode *nextNode);
};
