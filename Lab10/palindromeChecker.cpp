/*
 * palindromeChecker.cpp
 * 
 * Class Description: C++ program that determines when a given word is a palindrome.
 *                    Note that words of length 1 are palindromes.
 *
 * Author: Steven Wong
 * Date: August 1, 2022
 */
 

#include <iostream>
#include <cstring>
#include <cctype>
#include "Stack.h"


using namespace std;

// Function prototype 
void loadStringIntoStack(Stack *aStack, string aWord);
bool isPalindrome(Stack *aStack, string word);



int main() {

  /* Some variables declaration - you may need more. */
  Stack *aStack = new Stack(); 
  string theWord = "";
  
  /* Prompt user for a word and read the word. */
  cout << "Please, enter a word: ";
  /* Remove all leading whitespace -> ws */ 
  getline(cin >> ws, theWord);

  // Load word into the stack
  loadStringIntoStack(aStack, theWord);


  // Check if theWord is a palindrome
  if (isPalindrome(aStack, theWord))
  {
    cout << "The word " << theWord << " is a palindrome." << endl;
  } 
  else 
  {
    cout << "The word " << theWord << " is not a palindrome." << endl;
  }

  return 0;
}


// Check whether two strings in a given stack are valid palindromes
bool isPalindrome(Stack *aStack, string word) 
{
  // Check that stack are valid 
  assert(aStack != NULL);

  // Iterate through half the word and check it against the back half by popping in the stack
  for (int i = 0; i < word.length()/2; i++)
  {
    // If the current letter is not a match... then, the word is not a palindrome
    if (aStack->pop() != word[i]) return false;
  }

  // At this point, the back and front halves equal and the word is a palindrome
  return true;
}


// Load a string into a stack
void loadStringIntoStack(Stack *aStack, std::string aWord)
{ 
  // Check that the stack is valid
  assert(aStack != NULL);

  // For each char in the word, push the letter into the Stack
  for (int i = 0; i < aWord.length(); i++)
  {
    aStack->push(aWord[i]);
  }
  return;
}
