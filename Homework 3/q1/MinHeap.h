/*
* Title : Heaps and AVL Trees
* Author : Dilay Yigit
* ID : 21602059
* Section : 01
* Assignment : 3
* Description : MinHeap header file
*/

#ifndef HOMEWORK3_MINHEAP_H
#define HOMEWORK3_MINHEAP_H

const int MIN_HEAP = 50;

class MinHeap {
public:
    MinHeap();
    bool isEmpty() const;
    void insert(int value); // inserts integer into heap
    int peek (); // returns the value of the min element
    int extractMin(); // retrieves and removes the min element
    int size(); // returns the number of elements in the heap
    void printMinHeap();

protected:
    void heapRebuild(int indexCount);

private:
    int arrSize;
    int items[MIN_HEAP];
};


#endif //HOMEWORK3_MINHEAP_H
