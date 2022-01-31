HW04_CS202: main.o HashTable.o
	g++ main.o HashTable.o -o hw4

main.o: main.cpp
	g++ -c main.cpp

HashTable.o: HashTable.cpp HashTable.h
	g++ -std=c++11 -c HashTable.cpp

clean:
	rm *.o HW04_CS202