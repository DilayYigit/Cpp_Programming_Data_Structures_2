/**
*Title: Algorithm Efficiency and Sorting
*Author: Dilay Yigit
*ID: 21602059
*Section: 1
*Assignment: 1
*Description: Source File for Insertion, Merge, Quick and Radix Sorting Functions
*/

#include <iostream>
#include <chrono>
#include "Sorting.h"
using namespace std;

void Sorting::insertionSort (int *arr, int size, int &compCount, int &moveCount) {
    if (size > 1) {
        for (int i = 1; i < size; ++i) {
            int next = arr[i];
            int pos = i;
            for (; (pos > 0) && (arr[pos - 1] > next); --pos) {
                compCount++;
                arr[pos] = arr[pos - 1];
                moveCount++;
            }
            arr[pos] = next;
            moveCount++;
        }
    }
}

/*
 * Helper function for Merge Sort.
 * This function divides array into two and sort them separately.
 */
void Sorting::merge (int *arr, int first, int mid, int last, int &keyComp, int &dataMove) {
    int length = (last - first) + 1;
    int* tempArray = new int[length];

    int i = first;
    int j = mid + 1;
    int index = 0;
    while (i <= mid && j <= last) {
        keyComp++;
        if (arr[i] < arr[j]) {
            tempArray[index++] = arr[i];
            i++;
        } else {
            tempArray[index++] = arr[j];
            j++;
        }
        dataMove++;
    }

    for (; i <= mid; i++, index++) {
        tempArray[index] = arr[i];
        dataMove++;
    }
    for (; j <= last; j++, index++) {
        tempArray[index] = arr[j];
        dataMove++;
    }
    for (int k = 0; k < index; k++) {
        arr[k + first] = tempArray[k];
        dataMove++;
    }
    delete[] tempArray;
}

void Sorting::mergeSort (int *arr, int first, int last, int &compCount, int &moveCount) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSort(arr, first, mid, compCount, moveCount);
        mergeSort(arr, mid+1, last, compCount, moveCount);
        merge(arr, first, mid, last, compCount, moveCount);
    }
}

/*
 * Helper function for Quick Sort.
 * This function swaps two integers.
 */
void Sorting::swap (int *firstItem, int *secondItem) {
    int temp = *firstItem;
    *firstItem = *secondItem;
    *secondItem = temp;
}

/*
 * Helper function for Quick Sort.
 * This function selects a pivot as a key,
 * and sort the array according to the pivot.
 */
int Sorting::partition (int *arr, int first, int last, int &keyComp, int &dataMove) {
    int pivot = arr[first];
    int lastS1 = first;
    int checkIndex = first + 1;

    while (checkIndex <= last) {
        keyComp++;
        if (arr[checkIndex] < pivot) {
            ++lastS1;
            swap (&arr[checkIndex], &arr[lastS1]);
            dataMove = dataMove + 3;
        }
        checkIndex++;
    }
    swap (&arr[first], &arr[lastS1]);
    dataMove = dataMove + 3;
    return lastS1;
}

void Sorting::quickSort (int *arr, int first, int last, int &compCount, int &moveCount) {
    if (first < last) {
        int pivotIndex = partition(arr, first, last, compCount, moveCount);
        quickSort(arr, first, pivotIndex - 1, compCount, moveCount);
        quickSort(arr, pivotIndex + 1, last, compCount, moveCount);
    }
}

/*
 * Helper function for Radix Sort
 * This function finds maximum number in the array,
 * and returns number of digits of the maximum number.
 */
int Sorting::findMaxDigit (int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int digitNum = 0;
    while (max != 0) {
        max = max / 10;
        digitNum++;
    }
    return digitNum;
}

void Sorting::radixSort (int *arr, int size) {
    int maxDigit = findMaxDigit(arr, size);
    int index;
    int div = 1;
    for (int j = 0; j < maxDigit; j++) {
        int groups[10][size];
        int counter[10] = {0,0,0,0,0,0,0,0,0,0};
        for (int i = 0; i < size; i++) {
            int k = ((int)(arr[i] / div) % 10);
            groups[k][counter[k]] = arr[i];
            counter[k] += 1;
        }
        index = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < counter[i]; j++) {
                arr[index++] = groups[i][j];
            }
        }
        div = div * 10;
    }
}

void Sorting::printArray (int *arr, int size) {
    if (size != 0) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }
    else
        cout << "Array size is zero." << endl;
}

/*
 * Helper function for Performance Analysis.
 * This function starts time, run the algorithm (according to the sortNo),
 * and after execution, prints the data.
 */
void Sorting::test (int *arr, int size, int sortNo) {
    int compCount = 0;
    int moveCount = 0;
    int first = 0;
    int last = size - 1;
    chrono::time_point< chrono::system_clock > startTime;
    chrono::duration< double, milli > elapsedTime;

    startTime = chrono::system_clock::now();

    if (sortNo == 1) {
        insertionSort(arr, size, compCount, moveCount);
    }
    else if (sortNo == 2) {
        mergeSort(arr, first, last, compCount, moveCount);
    }
    else if (sortNo == 3) {
        quickSort(arr, first, last, compCount, moveCount);
    }
    else if (sortNo == 4) {
        radixSort(arr, size);
    }

    elapsedTime = chrono::system_clock::now() - startTime;

    cout << size << "\t\t" << elapsedTime.count() << "\t\t" << compCount << "\t\t" << moveCount << endl;
}

void Sorting::performanceAnalysis () {

    for (int no = 1; no <= 4; no++) {
        if (no == 1) cout << "\nPart a – Time Analysis of Insertion Sort" << endl;
        else if (no == 2) cout << "\nPart b – Time Analysis of Merge Sort" << endl;
        else if (no == 3) cout << "\nPart c – Time Analysis of Quick Sort" << endl;
        else cout << "\nPart d – Time Analysis of Radix Sort" << endl;

        cout << "-------------------------------------------------" << endl;
        cout << "Array Size\t" << "Time Elapsed\t" << "compCount\t" << "moveCount" << endl;

        // Random array creation
        for (int size = 2000; size <= 30000; size = size + 4000) {
            int arr[size];
            for (int j = 0; j < size; j++) {
                arr[j] = rand() % 500 + 1;
            }
            test(arr, size, no);
        }
    }
}






