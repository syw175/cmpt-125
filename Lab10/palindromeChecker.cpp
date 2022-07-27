/*
 * palindromeChecker.cpp
 * 
 * Class Description: C++ program that determines when a given word is a palindrome.
 *                    Note that words of length 1 are palindromes.
 *
 * Author:
 * Date:
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include "Stack.h"

using namespace std;

int main() {

  /* Some variables declaration - you may need more. */
  Stack * aStack = new Stack(); 
  string theWord = "";
  // Put some code here!
  
  /* Prompt user for a word and read the word. */
  cout << "Please, enter a word: ";
  /* Remove all leading whitespace -> ws */ 
  getline(cin >> ws, theWord);
  
  // Put more code here!
  
  return 0;
}
