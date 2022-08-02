List: List.o testDriver.o
	g++ -Wall List.o testDriver.o -o List

testDriver.o: testDriver.cpp
	g++ -Wall -c testDriver.cpp

List.o: List.cpp
	g++ -Wall -c List.cpp

clean: 
	rm *.o List
