//
// Created by Dilay Yiğit on 8.11.2021.
//

#ifndef HOMEWORK_2_BINARYNODE_H
#define HOMEWORK_2_BINARYNODE_H
#include <iostream>
using namespace std;

class BinaryNode {
public:
    BinaryNode();
    BinaryNode(const string anItem);
    BinaryNode(const string anItem, BinaryNode* leftPtr, BinaryNode* rightPtr);
    void increaseCounter();
    void setLeftChildPtr(BinaryNode* ptr);
    void setRightChildPtr(BinaryNode* ptr);
private:
    string item;
    int counter;
    BinaryNode* leftChildPtr;
    BinaryNode* rightChildPtr;

    friend class NgramTree;
};


#endif //HOMEWORK_2_BINARYNODE_H
