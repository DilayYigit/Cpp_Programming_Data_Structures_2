/**
*Title: Algorithm Efficiency and Sorting
*Author: Dilay Yigit
*ID: 21602059
*Section: 1
*Assignment: 1
*Description: Header File for Insertion, Merge, Quick and Radix Sorting Functions
*/
#ifndef HOMEWORK_01_SORTING_H
#define HOMEWORK_01_SORTING_H


class Sorting {
public:
    void insertionSort (int*, int, int&, int&);

    void mergeSort (int*, int, int, int&, int&);
    void merge (int*, int, int, int, int&, int&);

    void quickSort (int*, int, int, int&, int&);
    int partition (int*, int, int, int&, int&);
    void swap (int*, int*);

    void radixSort (int*, int);
    int findMaxDigit (int*, int);

    void printArray (int*, int);
    void performanceAnalysis();
    void test (int*, int, int);
};


#endif //HOMEWORK_01_SORTING_H
