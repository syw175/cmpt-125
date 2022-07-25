// Description: Test if a string is a palindrome

#include <stdio.h> 
#include <string.h>

int is_palindrome(char *string);

int main (void) 
{
	char *word1 = "test";
	char *word2 = "rotator";

	if (is_palindrome(word1))
	{
		printf("%s is a palindrome", word1);
	}
	else
	{
		printf("%s is not a palindrome", word1);
	}

	if (is_palindrome(word2))
	{
		printf("%s is a palindrome", word2);
	}
	else
	{
		printf("%s is not a palindrome", word2);
	}
}


int is_palindrome(char *string) 
{

	if (strlen(string) == 1) 
	{
		return 1;
	}




}
