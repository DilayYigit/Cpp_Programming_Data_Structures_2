/*
* Title : Heaps and AVL Trees
* Author : Dilay Yigit
* ID : 21602059
* Section : 01
* Assignment : 3
* Description : AVLTree source file
*/

#include "AVLTree.h"

#include <iostream>
using namespace std;

static int rotationCounter;

AVLTree::AVLTree() {
    root = NULL;
    rotationCounter = 0;
}

AVLTree::~AVLTree() {
    deleteAVLTree(root);
}

bool AVLTree::isEmpty() const {
    return root == NULL;
}

int AVLTree::height(Node *root) {
    if (root == NULL)
        return 0;
    return 1 + max(height(root->leftChild), height(root->rightChild));
}

int AVLTree::rotationChecker(Node* root) {
    if (root != NULL) {
        return (height(root->leftChild) - height(root->rightChild));
    }
    else return 0;
}

void AVLTree::insertAtTheEnd(Node*& root, int value) {
    if (root == NULL) {
        root = new Node(value);
    }
    else {
        if (value < root->data) {
            if (root->leftChild == NULL)
                root->leftChild = new Node(value);
            else
                insertAtTheEnd(root->leftChild, value);
        } else {
            if (root->rightChild == NULL)
                root->rightChild = new Node(value);
            else
                insertAtTheEnd(root->rightChild, value);
        }


        if (rotationChecker(root) > 1 && value < root->leftChild->data) {
            singleRight(root);
        }
        if (rotationChecker(root) > 1 && value > root->leftChild->data) {
            singleLeft(root->leftChild);
            singleRight(root);
        }
        if (rotationChecker(root) < -1 && value > root->rightChild->data) {
            singleLeft(root);
        }
        if (rotationChecker(root) < -1 && value < root->rightChild->data) {
            singleRight(root->rightChild);
            singleLeft(root);
        }
        else
            return;
    }
}

void AVLTree::singleRight(Node* k2) {
    Node* k1 = k2->leftChild;
    Node* child = k1->rightChild;
    k1->rightChild = k2;
    k2->leftChild = child;
    rotationCounter++;
}

void AVLTree::singleLeft(Node *k1) {
    Node* k2 = k1->rightChild;
    Node* child = k2->leftChild;
    k2->leftChild = k1;
    k1->rightChild = child;
    rotationCounter++;
}

int AVLTree::getNumberOfRotations() {
    return rotationCounter;
}

void AVLTree::insert(int value) {
    insertAtTheEnd(root, value);
}

void AVLTree::deleteAVLTree(Node *root) {
    if (root != NULL) {
        deleteAVLTree(root->leftChild);
        deleteAVLTree(root->rightChild);
        delete root;
    }
}