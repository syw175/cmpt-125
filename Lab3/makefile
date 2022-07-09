scrambled: testDriver.o scrambled.o
	clang -o scrambled testDriver.o scrambled.o 

scrambled.o: scrambled.c scrambled.h
	clang -Wall -c scrambled.c scrambled.h

testDriver.o: testDriver.c scrambled.h
	clang -Wall -c testDriver.c scrambled.h

clean: 
	rm -f scrambled *.o