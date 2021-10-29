HW01_CS202: main.o Sorting.o
	g++ main.o Sorting.o -o hw1

main.o: main.cpp
	g++ -c main.cpp

Sorting.o: Sorting.cpp Sorting.h
	g++ -std=c++11 -c Sorting.cpp

clean:
	rm *.o HW01_CS202