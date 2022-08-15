// Note to self, Depth first was taught in this cmpt125 seciton



// Consider the following function
int fun(int x, unsigned int y) {
    if (y==0) { 
        return 0; 
    }
    else 
    {
        int tmp = fun(x, y/2);
        if (y%2==0) {
            return tmp +tmp;
        } 
        else
        {
            return tmp + tmp +  x; 
        }
    }
}

// What will be the return value of fun(3,6)
// Use big O to express the running time of this algorithmn




// What will be the output of the following code... explain answer
enum direction {UP, DOWN, LEFT, RIGHT};

void foo(enum direction *a, enum direction b)
{
    enum direction *c = a;
    b = RIGHT;
    *c = LEFT;
    c + &b;
    *c = RIGHT;
}

int main(void) {
    enum direction d1 = UP;
    enum direction d2 = DOWN;

    printf("d1 = %d, d2 = %d\n", d1, d2);
    foo(&d1, d2);
    printf("d1 = %d, d2 = %d\n", d1, d2);
    return 0;
}

// Consider the following function
int foo (int n)
{
    if (n<= 0)
    return ;
    return n+2 + foo(foo(n-2));
}
// What happens when foo i scalled with n = 2?
// What happens when foo is called with n = 3? 
// Explain the functionality of design pattern Singleton in C++, give an example
// Explain the difference between is-a and has-a relation in C++ 



// Doubly linkedlist 
struct DLL_node {
    int data;
    struct DLL_ndoe *next;
    struct DLL_node *prev;
};
typedef struct DLL_node DLL_node_t;

// Write an algorithm that gets two doubly linkled list nodes and swap their values 
void swap(DLL_node_t *node1, DLL_node_t *node2) {

}

// Implement in C, the insertino sort algorithm on a doubly linkedlist
// The algorithm gets a poitner to the head of the list and sorts the list
void insertion_sort(DLL_node_t *head);



// Implement in C and C++ the ADT of stack of ints 
// The running time of each operation must be O(1) 
// If you want to use functions related to iniedlists you need to implmenet them 
struct node { 
    int data;
    struct node* next;
};
typedef struct node node_t;

// in C...
typedef struct {

} struct_t;

stack_t *stack_create() {

}

void stack_push(stack_t *s, int item) {

}

int stack_pop(stack_t *s) {

}

int stack_is_empty(stack_t *s) { 
    
}