// Testing recursion with factorials 
// Visualizer https://pythontutor.com/render.html#mode=display


#include <stdio.h>

unsigned int factorial(unsigned int n) { 
	// Base case
	// Negative val causes error
	if (n <= 1) { 
		return 1;
	} 

	// Recursive case
	return n * factorial(n - 1);
}

int main (void) { 
	unsigned int n = 5; 
	printf("Factorial of %i is: %i", n, factorial(n));
}

