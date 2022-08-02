// Testing my ability to hand trace code
// I expect the following output: 

// You want to stop? 
// Play again? 
// $

// Actual output: 
// You want to stop? 
// Play again? 
// $

#include <stdio.h> 

int main (void) { 
    int goAhead = 0;
    int score = 198;

    if (goAhead) {
        if (score >= 200) {
            printf("You win!\n");
        }

    } else { 
        printf("You want to stop? \n");
        printf("Play again? \n");
    }
}
