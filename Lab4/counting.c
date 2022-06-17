/*
 * Filename: counting.c
 *
 * Description: Counts the number of characters, words and lines read from standard input (stdin) until EOF
 * 
 * 
 * Sample Input: paul
 *               ringo
 *               george
 *               john
 *
 *
 * Sample Output: 23 4 4
 *
 * Author: Steven Wong
 * Date: June 16, 2022
 */


#include<stdio.h> 


// Check if a given char is a letter in the alphabet or an apostrophy
int isLetterInWord(char character) {
    // ASCII 39 - Apostrophy
    // ASCII 65 - 90 A-Z
    // ASCII 97 - 122 a-z

    const int apostrophy = 39;
    const int capitalA = 65;
    const int capitalZ = 90; 
    const int lowerA = 97;
    const int lowerZ = 122;

    // Typecast char to an integer representation 
    const int ascii = (int)character; 
    if (ascii == apostrophy) { 
        return 1;
    }

    if (capitalA <= ascii && ascii <= capitalZ) { 
        return 1;
    }

    if (lowerA <= ascii && ascii <= lowerZ) { 
        return 1;
    }
    return 0;
}


void letterFreq(void) {
    // Initialize counter variables for chars, words, and lines
    unsigned long charCount = 0;
    unsigned long wordCount = 0;
    unsigned long lineCount = 0;

    // Get first char
    char symbol = getchar();

    while (symbol != EOF) {
        // Increment char count in every iteration
        charCount++;
        char nextSymbol = getchar();

        // If previous char is a letter in a word and the current char is not, increment word count
        if (isLetterInWord(symbol) && !isLetterInWord(nextSymbol)) { 
            wordCount++;
        }

        // If current symbol is newline, increment line count
        if(symbol == '\n') { 
            lineCount++;
        }

        // Update previous char
        symbol = nextSymbol;
    }
    // Print totals of all counters
    printf("%lu %lu %lu\n", charCount, wordCount, lineCount);

}


// Start counting chars, words, and lines
int main(int argc, char **argv) {
    letterFreq();
    return 0;
}


