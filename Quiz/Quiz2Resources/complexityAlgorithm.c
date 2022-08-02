// Preparation for Quiz 3 
// Analyze the following code fragments and for each of them give the
// overall time efficiency expressed using the Big O notation:

int main (void) { 

    // Snippet 1
    // I would expect this to be O(2n) which is the same as O(n) in complexity analysis
    // CORRECT!
    int a = 0, b = 0;
    for (i = 0; i < SIZE; i++) {
        a = rand() % SIZE;
    }

    for (j = 0; j < SIZE; j++) { b = rand() % SIZE;
        b = rand() % SIZE;
    }


    // Snippet 2
    // I would expect this to be O(logn)
    // Almost Correct! O(log_2n)
    int a = 0, i = n; 
    while (i > 0) {
        a += i;
        i /= 2; 
    }

    // Snippet 3
    // I would expect this code to do (n/2)*(logn) which is O(nlogn)
    // Almost Correct! O(nlog_2n)
    int i, j, k = 0;
    for (i = n / 2; i <= n; i++) {
        for (j = 2; j <= n; j = j * 2) {
            k = k + n / 2;
        }
    }


}

// Snippet 4
// I would expect this code to be O(n^2log_2n)
// CORRECT!
void function(int n) {
    int count = 0;
    // outer loop executes n/2 times 
    for (int i=n/2; i<=n; i++) { 
        // middle loop executes  n/2 times
        for (int j=1; j+n/2<=n; j = j++) { 
            // inner loop executes log n times 
            for (int k=1; k<=n; k = k * 2) { 
                count++;
            }
        }
    }
}
                                    




