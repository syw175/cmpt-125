testDriver: testDriver.o Queue.o Node.o
	g++ -Wall testDriver.o Queue.o Node.o -o testDriver

Node.o: Node.cpp
	g++ -Wall -c Node.cpp

Queue.o: Queue.cpp
	g++ -Wall -c Queue.cpp

clean: 
	rm *.o testDriver
