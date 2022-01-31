/*
* Title : Heaps and AVL Trees
* Author : Dilay Yigit
* ID : 21602059
* Section : 01
* Assignment : 3
* Description : MedianHeap header file
*/

#ifndef HOMEWORK3_MEDIANHEAP_H
#define HOMEWORK3_MEDIANHEAP_H
#include "MaxHeap.h"
#include "MinHeap.h"

class MedianHeap {
public:
    MedianHeap();
    void insert(int value);
    int findMedian();

private:
    MinHeap min;
    MaxHeap max;
    int arrSize;
};


#endif //HOMEWORK3_MEDIANHEAP_H
