Stack: Stack.o testDriver.o
	g++ -Wall Stack.o testDriver.o -o Stack

testDriver.o: testDriver.cpp
	g++ -Wall -c testDriver.cpp

Stack.o: Stack.cpp
	g++ -Wall -c Stack.cpp

clean: 
	rm *.o Stack
