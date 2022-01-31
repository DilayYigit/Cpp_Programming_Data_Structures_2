/*
* Title : Heaps and AVL Trees
* Author : Dilay Yigit
* ID : 21602059
* Section : 01
* Assignment : 3
* Description : MedianHeap source file
*/

#include "MedianHeap.h"

MedianHeap::MedianHeap() {
    max = MaxHeap();
    min = MinHeap();
    arrSize = 0;
}

//void MedianHeap::insert(int value) {
//    if (arrSize > 1) {
//        if (value > max.peek())
//            min.insert(value);
//        else
//            max.insert(value);
//
//        if (min.size() + 2 == max.size())
//            min.insert(max.extractMax());
//        else if (max.size() + 2 == min.size())
//            max.insert(min.extractMin());
//    }
//    else if (arrSize == 0)
//        min.insert(value);
//    else {
//        if (min.peek() > value) {
//            min.insert(value);
//            max.insert(min.extractMin());
//        }
//        else
//            max.insert(value);
//    }
//    arrSize++;
//}

void MedianHeap::insert(int value) {
    max.insert(value);
    min.insert(max.extractMax());
    if (min.size() > max.size())
        max.insert(min.extractMin());
}

int MedianHeap::findMedian() {
    int median;
    if (max.size() > min.size())
        median = max.peek();
    else if (min.size() > max.size())
        median = min.peek();
    else {
        if (min.peek() > max.peek())
            median = min.peek();
        else
            median = max.peek();
    }
    return median;
}