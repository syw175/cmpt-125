palindromeChecker: palindromeChecker.o Stack.o StackNode.o
	g++ -Wall palindromeChecker.o Stack.o StackNode.o -o palindromeChecker

StackNode.o: StackNode.cpp
	g++ -Wall -c StackNode.cpp

Stack.o: Stack.cpp
	g++ -Wall -c Stack.cpp

clean: 
	rm *.o palindromeChecker
