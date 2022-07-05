testDriver: testDriver.o dataStructure.o
	gcc -o testDriver testDriver.o dataStructure.o 

dataStructure.c: dataStructure.c dataStructure.h
	gcc -Wall -c dataStructure.c dataStructure.h

testDriver.o: testDriver.c dataStructure.h
	gcc -Wall -c testDriver.c 

clean: 
	rm -f testDriver *.o
	rm -f dataStructure *.gch