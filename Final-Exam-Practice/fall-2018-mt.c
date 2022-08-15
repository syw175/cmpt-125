// Node to self... binary  trees were taught in previous cmpt125

// What will be the output of the following code? 
int foo (int *x, int *y, int z) 
{
    y =x; 
    z=7; 
    *y =z;
}

int main() {
    int a= 0, b = 1, c = 2;
    foo(&a, &b, c);
    printf("a = %d, b= %d, c = %d", a, b, c);
    return 0;
}



// Consider the following function
void bar(int n) 
{
    int i = 1, sum = 0;
    while (sum < n*(n+1)/2) {
        printf("%d ", i);
        sum += i; 
        i++
    }
}
// What will it print on input n = 3, show intermediate calculations 
// Use the big O notation to express the running time of bar(n) 


// Will the following code compile, if yes write output, if no explain
int main() {
    int b[5] = {1, 2, 3, 4, 5};
    int *a = b;
    printf("a[2] = %d\n", a [2]); 
    return 0;
}



// Will the following code compile, if yes write output, if no explain
int main() {
    int *a = (int *)malloc(5 *sizeof(int));
    for (int i = 0; i < 5; i++)
        a[i] = i; 
    int b[5];
    b = a; 
    printf("b[2] = %d\n", b[2]);
    return 0;
}


// Given the following linked list of ints using LLnode_t
struct node {
    int data;
    struct node* next;
};

typedef struct node LLnode_t;

// consider the following function 
void fun_list (LLnode_t *head) 
{
    if (head == NULL) { 
        printf("\n");
        return;
    }

    printf("%d ", head->data);
    if (head->next != NULL) 
        fun_list(head->next);
    printf("%d ", head->data);
}

// What will be the output of fun_list on input 1-2-3-4-5?
// What is the running time in big O of fun_list()


// Write a function in C that gets a srorted linkedlist and removes duplicates 
// for exmaple 1-1-1-2-2-2-5-6-6-6-7
// Becomes 1-2-5-6-7
// Need to free memory used by nodes removed
void remove_duplicates(LLnode_t *head) { 

}

// What is the running time of this funciton? 



// You may assume functions are implemented but cannot make assumptions about
// How they are implemented
typedef struct {
    ...
} stack_t;

stack_t *stack_create();  // Create empty stack
void push(stack_t *s, int item); // Add item to the stack
int pop(stack_t *s); // remove the top of the stack and return it 
bool is_empty(stack_t *s); // Check if the stack is empty 
void stack_free(stack_t *s) // free the memory used by the stack

// Write a function that creates a copy of the stack
// Original stack must be unmodified, memory for temp variables must be freed

stack_t *stack_copy(stack_t *original)

// What is the running time of this function? 

// Consider the following sequence of operations on a stack
stack_t *s = stack_create(); 
push(s, 1);
push(s, 2);
push(s, 3);

printf("%d ", pops));
push(s, 4);
push(s, 5);
push(s, 6); 

printf("%d ", pop(s));
printf("%d ", pop(s));

push(s, 7);

// What will be the stack of the stack at the end 
// Write intermediate steps


// How many swaps will insertion sort perform on this input
[9, 6, 2, 1, 4];

// List all recursive calls made by merge sort on input [9, 6, 7, 2, 1, 4]

// What is the running time of selection sort on a sorted array of length n? Use big O



