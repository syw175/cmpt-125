/*
 * Filename: letterFreq.c
 *
 * Description: Calculates the frequency of letter occurrences in text. On reaching EOF, 
 *              print to stdout the normalized frequency of occurrence for each letter 
 *              a-z that appeared in the input, one per line, in alphabetical order.
 * 
 * 
 * Sample Input: aaab
 *
 *
 * Sample Output: a 0.7500
 *                b 0.2500
 *
 * Author: Steven Wong
 * Date: June 16, 2022
 */


#include<stdio.h>


// Return 1 if char is a character in the English Alphabet
int isAlphabetLetter(char character) {
    return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
}


// Return 1 if char is a upper case character in the English Alphabet
int isUpperCase(char character) { 
    return (character >= 'A' && character <= 'Z');
}


int main(int argc, char **argv) {
    // Initalize counter to record frequency of each letter 
    const int alphabetLength = 26;
    float letterFreq[alphabetLength];

    // Set all elements in array to 0
    for (int i = 0; i < alphabetLength; i++) { 
        letterFreq[i] = 0;
    }

    // Initialize counter for total number of characters read 
    int numCount = 0;

    // Read character until EOF 
    char symbol = getchar();
    while (symbol != EOF) {
        if (isAlphabetLetter(symbol)) {
            numCount++;
            if (isUpperCase(symbol)) { 
                symbol += 32;
            }
            symbol -= 'a';
            letterFreq[symbol]++;
        }
        symbol = getchar();
    }

    // Print frequency of alphabet letters by %, if none appeared, skip that letter
    for (int i = 0; i < alphabetLength; i++) { 
        if (letterFreq[i] != 0) { 
            printf("%c: %.4f\n", 'a'+i, letterFreq[i]/numCount);
        }
    }

    printf("\n");
    return 0;
}
