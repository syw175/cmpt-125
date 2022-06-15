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
 * Date: June 14, 2022
 */


#include<stdio.h> 


int isLetterInWord(char character) {
    // ASCII 39 - Apostrophy?
    // ASCII 65 - 90 A-Z
    // ASCII 97 - 122 a-z

    int ascii = (int)character; 
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


void letterFreq() {
    unsigned long charCount = 0;
    unsigned long wordCount = 0;
    unsigned long lineCount = 0;

    int symbol = getchar();

    while (symbol != EOF) {
        if (isLetterInWord(symbol)) { 
            charCount++;
        }
    }
    printf("%lu %lu %lu\n", charCount, wordCount, lineCount);
}

int main(int argc, char **argv) {
    // Testing isLetterIn Word Function
    // char letter = 'p'; 
    // if (isLetterInWord(letter)) { 
    //     printf("true\n");

    letterFreq();
    return 0;
}


