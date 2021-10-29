/**
*Title: Algorithm Efficiency and Sorting
*Author: Dilay Yigit
*ID: 21602059
*Section: 1
*Assignment: 1
*Description: Test Class for Sorting Algorithms
*/

#include <iostream>
#include "Sorting.h"
using namespace std;
int main() {

    Sorting s;

    int arr1[] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};
    int arr2[] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};
    int arr3[] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};
    int arr4[] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};

    int compCount = 0;
    int moveCount = 0;

    cout << "\n--------------- Insertion Sort ---------------";
    cout << "\nOriginal array is: ";
    s.printArray(arr1, 16);
    s.insertionSort(arr1, 16, compCount, moveCount);
    cout << "\nSorted array is: ";
    s.printArray(arr1, 16);

    compCount = 0;
    moveCount = 0;

    cout << "\n--------------- Merge Sort ---------------";
    cout << "\nOriginal array is: ";
    s.printArray(arr2, 16);
    s.mergeSort(arr2, 0, 15, compCount, moveCount);
    cout << "\nSorted array is: ";
    s.printArray(arr2, 16);

    compCount = 0;
    moveCount = 0;

    cout << "\n--------------- Quick Sort ---------------";
    cout << "\nOriginal array is: ";
    s.printArray(arr3, 16);
    s.quickSort(arr3, 0, 15, compCount, moveCount);
    cout << "\nSorted array is: ";
    s.printArray(arr3, 16);

    compCount = 0;
    moveCount = 0;

    cout << "\n--------------- Radix Sort ---------------";
    cout << "\nOriginal array is: ";
    s.printArray(arr4, 16);
    s.radixSort(arr4, 16);
    cout << "\nSorted array is: ";
    s.printArray(arr4, 16);

    cout << endl;
    s.performanceAnalysis();
    return 0;
}
