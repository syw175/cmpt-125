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

// Function prototype 
void loadStringIntoStack(Stack *aStack, std::string aWord);
bool isPalindrome(Stack *aStack, Stack *bStack);

using namespace std;


int main() {

  /* Some variables declaration - you may need more. */
  Stack * aStack = new Stack(); 
  Stack * bStack = new Stack();
  string theWord = "";
  
  /* Prompt user for a word and read the word. */
  cout << "Please, enter a word: ";
  /* Remove all leading whitespace -> ws */ 
  getline(cin >> ws, theWord);
  
  // Make a copy of the word but reversed
  string copy = theWord;
  reverse(copy.begin(), copy.end());
  
  // Load the two words into the stack
  loadStringIntoStack(aStack, theWord);
  loadStringIntoStack(bStack, copy);

  // Check if theWord is a palindrome
  if (isPalindrome(aStack, bStack)) 
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
bool isPalindrome(Stack *aStack, Stack *bStack) 
{
  // Check that both stacks are valid 
  assert(aStack != NULL);
  assert(bStack != NULL);

  // While both stacks are not empty... 
  while (!aStack->isEmpty() && !bStack->isEmpty()) 
  {
    // Pop the first element of aStack and bStack
    if (aStack->pop() != bStack->pop()) 
    {
      // If the first element aStack != first element bStack... the word is not a palindrome
      return false;
    }
  }

  // If either stack is empty, theWord is not a palindrome
  if (!aStack->isEmpty() || !bStack->isEmpty()) 
  {
    return false;
  }

  // At this point, theWord is a palindrome
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
