// Array and Pointers
// Possible output of the followng code
// 1 
#include <stdio.h>

int main(void)
{
    int m[7] = {1, 1, 5, 5, 6, 6, 5};
    printf("%d, %d, %d, %d\n", sizeof(int), m, m[4], &m[4]);
}


// 2 
int main() {
    int m[2] = {5, 8};
    int *n = m;
    printf("m = %d, n = %d\n", m, n);
}



// Character arrays and strings
// Possible output of the following code 
// 1
#include <stdio.h>
int main(void)
{
    char greet[14] = "Hello world!";
    for (int i = 0; i < 13; i++)
    {
        printf("%d ", greet[i]);
        i++;
    }
    printf("\n");
}


// 2 
int main(void) { 
    char x[5] = "Hello, world!";
    printf("%s, ", x);
    printf("%c\n", x+7);
}


// Recursion 
// Complete this unfinished implementation of binary search 
// Return 1 if target is found, otherwise return 0 
int binarySearch(int arr[], int len, int target) { 

}






// Linked Lists 
// Implementation of the following linkedlist is given... 
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} node_t

typedef struct {
    node_t *head;
} LL_t;

LL_t *LLcreate() { 
    LL_t *ret = malloc(sizeof(LL_t));
    ret->head = NULL;
    return ret;
}

// Complete the following functions: LLappend that adds a new node of a speicfied value to the linked lists. 
//                                   LLlength that returns the number of elements in the list 

void LLappend(LL_t *intlist, int value)
{
    // Create the new node
    node_t *newNode = malloc(sizeof(node_t)); 

    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty update the head pointer
    if (intlist->head == NULL)
    {
        intlist->head = newNode;
        return;
    }

    // If the list is non-empty, transver the list to the end while keeping track of previous node
    node_t *prev = intlist->head;
    node_t *curr =  intlist->head->hext; 

    while(curr != NULL)
    {
        curr = curr->next;
        prev = prev->next;
    }

    // Once curr pointer finishes traversing the array
    // The prev pointer would point to the last node, whose next pointer should be updated
    prev->next = newNode;
}

int LLlength(LL_t intlist)
{
    int length = 0;
}


// Write a function LLcomp taht compares two linkedlists, return 1 if lists are
// Equal in length and contain all the same elements in order 
int LLcomp(LL_t *intlist1, LL_t *intlist2)
{

}


// Write a function LLupdate that updates the value of a node in a linkedlist. If the node
// is not found, the linked list should not change, instead the user should get the following message
// Node is not found!

void LLupdate(LL_t *intlist, node_t *n, int value)
{

}


// Write a function that makes a copy of a given linked list 
LL_t *LLcopy(LL_t *source_list) { 
    
}
