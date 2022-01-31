/*
* Title : Heaps and AVL Trees
* Author : Dilay Yigit
* ID : 21602059
* Section : 01
* Assignment : 3
* Description : MinHeap source file
*/

#include "MinHeap.h"
#include <iostream>
using namespace std;

MinHeap::MinHeap() {
    arrSize = 0;
}

bool MinHeap::isEmpty() const {
    return arrSize == 0;
}

int MinHeap::peek() {
    if (!isEmpty())
        return items[0];
    else
        return 0;
}

int MinHeap::size() {
    return arrSize;
}

void MinHeap::insert(int value) {
    if (arrSize == MIN_HEAP) {
        cout << "Heap is full!" << endl;
    }
    else {
        items[arrSize] = value;

        int currentIndex = arrSize;
        int parent = (currentIndex - 1) / 2;

        while ((currentIndex > 0) && (items[currentIndex] < items[parent])) {
            int temp = items[currentIndex];
            items[currentIndex] = items[parent];
            items[parent] = temp;

            currentIndex = parent;
            parent = (currentIndex - 1) / 2;
        }
        arrSize++;
    }
}

int MinHeap::extractMin() {
    int minItem = peek();
    if (isEmpty()) {
        cout << "Heap is empty!" << endl;
    }
    else {
        items[0] = items[--arrSize];
        heapRebuild(0);
    }
    return minItem;
}

void MinHeap::heapRebuild(int indexCount) {
    int leftChildIndex = (2*indexCount) + 1;
    if (leftChildIndex < arrSize) {
        int rightChildIndex = (2*indexCount) + 2;
        if ((rightChildIndex < arrSize) && (items[leftChildIndex] > items[rightChildIndex])) {
            leftChildIndex = rightChildIndex;
        }
        if (items[indexCount] > items[leftChildIndex]) {
            int temp = items[indexCount];
            items[indexCount] = items[leftChildIndex];
            items[leftChildIndex] = temp;

            heapRebuild(leftChildIndex);
        }
    }
}

void MinHeap::printMinHeap() {
    for (int i = 0; i < arrSize; i++) {
        cout << items[i] << " ";
    }
    cout << endl;
}