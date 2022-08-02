Points: Points.o PointTestDriver.o
	g++ -Wall Points.o PointTestDriver.o -o Points

PointTestDriver.o: PointTestDriver.cpp
	g++ -Wall -c PointTestDriver.cpp

Points.o: Points.cpp
	g++ -Wall -c Points.cpp

clean: 
	rm *.o Points
