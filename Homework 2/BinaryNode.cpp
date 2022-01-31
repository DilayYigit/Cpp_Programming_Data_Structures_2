//
// Created by Dilay Yiğit on 8.11.2021.
//

#include "BinaryNode.h"
#include <iostream>
using namespace std;

BinaryNode::BinaryNode() {
    item = "";
    counter = 1;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}
BinaryNode::BinaryNode(const string anItem) {
    item = anItem;
    counter = 1;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}
BinaryNode::BinaryNode(const string anItem, BinaryNode *leftPtr, BinaryNode *rightPtr) {
    item = anItem;
    counter = 1;
    leftChildPtr = leftPtr;
    rightChildPtr = rightPtr;
}
void BinaryNode::increaseCounter() {
    counter++;
}
void BinaryNode::setLeftChildPtr(BinaryNode* ptr){
    leftChildPtr = ptr;
}
void BinaryNode::setRightChildPtr(BinaryNode* ptr){
    rightChildPtr = ptr;
}

