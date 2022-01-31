/*
* Title : Heaps and AVL Trees
* Author : Dilay Yigit
* ID : 21602059
* Section : 01
* Assignment : 3
* Description : MaxHeap header file
*/

#ifndef HOMEWORK3_MAXHEAP_H
#define HOMEWORK3_MAXHEAP_H

const int MAX_HEAP = 50;
class MaxHeap {
public:
    MaxHeap();
    bool isEmpty() const;
    void insert(int value); // inserts integer into heap
    int peek(); // returns the value of the max element
    int extractMax(); // retrieves and removes the max element
    int size(); // returns the number of elements in the heap
    void printMaxHeap();

protected:
    void heapRebuild(int indexCount);

private:
    int arrSize;
    int items[MAX_HEAP];

};


#endif //HOMEWORK3_MAXHEAP_H
