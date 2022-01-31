
/*
* Title : Heaps and AVL Trees
* Author : Dilay Yigit
* ID : 21602059
* Section : 01
* Assignment : 3
* Description : MaxHeap source file
*/

#include "MaxHeap.h"
#include <iostream>
using namespace std;

MaxHeap::MaxHeap() {
    arrSize = 0;
}

int MaxHeap::size() {
    return arrSize;
}

bool MaxHeap::isEmpty() const {
    return arrSize == 0;
}

int MaxHeap::peek() {
    if (!isEmpty())
        return items[0];
    else
        return 0;
}

int MaxHeap::extractMax() {
    int maxItem = peek();
    if (isEmpty()) {
        cout << "Heap is empty!" << endl;
    }
    else {
        items[0] = items[--arrSize];
        heapRebuild(0);
    }
    return maxItem;
}

void MaxHeap::heapRebuild(int indexCount) {
    int leftChildIndex = (2*indexCount) + 1;
    if (leftChildIndex < arrSize) {
        int rightChildIndex = (2*indexCount) + 2;
        if ((rightChildIndex < arrSize) && (items[leftChildIndex] < items[rightChildIndex])) {
            leftChildIndex = rightChildIndex;
        }
        if (items[indexCount] < items[leftChildIndex]) {
            int temp = items[indexCount];
            items[indexCount] = items[leftChildIndex];
            items[leftChildIndex] = temp;

            heapRebuild(leftChildIndex);
        }
    }
}

void MaxHeap::insert(int value) {
    if (arrSize == MAX_HEAP) {
        cout << "Heap is full!" << endl;
    }
    else {
        items[arrSize] = value;

        int currentIndex = arrSize;
        int parent = (currentIndex - 1) / 2;

        while ((currentIndex > 0) && (items[currentIndex] > items[parent])) {
            int temp = items[currentIndex];
            items[currentIndex] = items[parent];
            items[parent] = temp;

            currentIndex = parent;
            parent = (currentIndex - 1) / 2;
        }
        arrSize++;
    }
}

void MaxHeap::printMaxHeap() {
    for (int i = 0; i < arrSize; i++) {
        cout << items[i] << " ";
    }
    cout << endl;
}