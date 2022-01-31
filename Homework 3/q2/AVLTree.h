/*
* Title : Heaps and AVL Trees
* Author : Dilay Yigit
* ID : 21602059
* Section : 01
* Assignment : 3
* Description : AVLTree header file
*/

#ifndef HOMEWORK3_AVLTREE_H
#define HOMEWORK3_AVLTREE_H
#include <iostream>
using namespace std;

struct Node {
    Node* leftChild;
    Node* rightChild;
    int data;
    Node(int val) {
        data = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    bool isEmpty() const;
    bool isBalanced(Node* root);
    void insert(int value);
    int height(Node* root);
    void insertAtTheEnd(Node*& curr, int value);
    int getNumberOfRotations();
    int rotationChecker(Node* root);
    void singleRight(Node* k2);
    void singleLeft(Node* k1);
    void deleteAVLTree(Node* root);
private:
    Node* root;
};


#endif //HOMEWORK3_AVLTREE_H
