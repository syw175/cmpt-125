// What is the value of x at line 10 in the funciton call funny(2) 
// Give the big O notation estimate 
void funny (int N)
{
    int x = 1;
    int y = x-1;
    
    for (int i = 1; i <= N; i++) { 
        y += x;
        x += x;
    }

    printf("%d\n", y);
}

// What are the possible outputs of the following code?
int main() { 
    int arr[7] = {4096, 1024, 256, 64, 16};
    int m = arr[0]; 
    int n = arr +4;
    printf("%d, %d, %d\n", arr, m, n);
}

// Does the code contain an infinite loop? 
int main() 
{
    char x[50] =  "hello";
    int i = 0;
    while (x[i] != 0) { 
        printf("%c\n", x[i]);
        i++;
    }
}

// Reverse merge 
// Write a function that merges two arrays that are sorted in ascending order, such taht the resulting 
// array contain the same elements sorted in descending order. 
// Assume that slen 1 + slen2 = dlen is true 
void reverse_merge(int src1[], int slen1, int src2[], int slen2, int dest[], int dlen)
{
    // Recursion may be a good fit for this problem 


    
}