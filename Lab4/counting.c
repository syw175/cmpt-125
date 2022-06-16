/*
 * Filename: counting.c
 *
 * Description: Counts the number of characters, words and lines read from standard input (stdin) until EOF is reached
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
 * Date: June 15, 2022
 */


#include<stdio.h> 
#include<stdbool.h>
#include<ctype.h>

// Check if char is a letter in the alphabet or apostrophy
bool isLetterInWord(char character) {
    // ASCII 39 - Apostrophy
    // ASCII 65 - 90 A-Z
    // ASCII 97 - 122 a-z

    const int ascii = (int)character; 
    if (ascii == 39) { 
        return 1;
    }

    if (65 <= ascii && ascii <= 90) { 
        return 1;
    }

    if (97 <= ascii && ascii <= 122) { 
        return 1;
    }
    return 0;
}


void letterFreq(void) {
    unsigned long charCount = 0;
    unsigned long wordCount = 0;
    unsigned long lineCount = 0;

    char symbol = getchar();

    while (symbol != EOF) {
        charCount++;
        char nextSymbol = getchar();

        if (isLetterInWord(symbol) && !isLetterInWord(nextSymbol)) { 
            wordCount++;
        }

        if(symbol == '\n') { 
            lineCount++;
        }
        symbol = nextSymbol;
    }
    printf("Char count: %lu \nWord Count: %lu \nLine count: %lu\n", charCount, wordCount, lineCount);
}

int main(int argc, char **argv) {
    // Testing isLetterIn Word Function
    // char letter = 'p'; 
    // if (isLetterInWord(letter)) { 
    //     printf("true\n");

    letterFreq();
    return 0;
}


