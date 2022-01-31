//
// Created by Dilay Yiğit on 10.11.2021.
//

#include "NgramTree.h"
#include <string>
#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

NgramTree::NgramTree() {
    root = NULL;
}
NgramTree::~NgramTree() {
    deleteNodes(root);
}
void NgramTree::deleteNodes(BinaryNode* subPtr) {
    if( subPtr != NULL ){
        deleteNodes(subPtr->leftChildPtr);
        deleteNodes(subPtr->rightChildPtr);
        delete subPtr;
        subPtr = NULL;
    }
}

BinaryNode *NgramTree::findNode(BinaryNode* subTree, string target) {
    if( subTree == NULL ){
        return NULL;
    }
    else if (subTree->item == target) {
        return subTree;
    }
    else if (subTree->item > target) {
        return findNode(subTree->leftChildPtr, target);
    }
    else {
        return findNode(subTree->rightChildPtr, target);
    }
}
void NgramTree::addNgram(string ngram) {
    BinaryNode* newNode = new BinaryNode(ngram);
    root = insertNode(root, newNode);
}

BinaryNode* NgramTree::insertNode(BinaryNode* subPtr, BinaryNode* newPtr) {
    if (subPtr == NULL) {
        return newPtr;
    }
    else if (subPtr->item > newPtr->item) {
        BinaryNode* tempPtr = insertNode(subPtr->leftChildPtr, newPtr);
        subPtr->setLeftChildPtr(tempPtr);
    }
    else if (subPtr->item < newPtr->item) {
        BinaryNode* tempPtr = insertNode(subPtr->rightChildPtr, newPtr);
        subPtr->setRightChildPtr(tempPtr);
    }
    else if (subPtr->item == newPtr->item) {
        subPtr->increaseCounter();
    }
    return subPtr;
}

void NgramTree::generateTree(string fileName, int n) {

    ifstream text;
    text.open(fileName.c_str());
    string str;

    if (!text.is_open()) {
        cout << "File cannot opened." << endl;
    }
    else {
        while (text >> str) {
            if (str.length() >= n) {
                for (int i = 0; i <= str.length() - n; i++) {
                    addNgram(str.substr(i, n));
                }
            }
        }
    }
}

void NgramTree::inorderCount (BinaryNode* root, int &counter) {
    if (root != NULL) {
        inorderCount(root->leftChildPtr, counter);
        counter++;
        inorderCount(root->rightChildPtr, counter);
    }
}

int NgramTree::getTotalNgramCount() {
    if (root == NULL) {
        return 0;
    }
    int totalNgram = 0;
    inorderCount(root, totalNgram);
    return totalNgram;
}

bool NgramTree::isFull() {
    return fullBinaryTree(root);
}

bool NgramTree::fullBinaryTree(BinaryNode* root) {
    if (root == NULL || !(root->leftChildPtr) && !(root->rightChildPtr)) {
        return true;
    }
    if (!(root->leftChildPtr) || !(root->rightChildPtr)) {
        return false;
    }
    return fullBinaryTree(root->leftChildPtr) && fullBinaryTree(root->rightChildPtr);
}

bool NgramTree::isComplete() {
    return completeBinaryTree(root);
}

bool NgramTree::completeBinaryTree(BinaryNode *root) {
    if (root != NULL) {
        queue<BinaryNode*> queue;
        queue.push(root);

        bool notFullNode = false;
        while(!queue.empty())
        {
            BinaryNode *temp = queue.front();
            queue.pop();
            if(temp != NULL) {
                if(notFullNode)
                    return false;
                queue.push(temp->leftChildPtr);
                queue.push(temp->rightChildPtr);
            }
            else
                notFullNode = true;
        }
    }
    return true;
}
BinaryNode *NgramTree::getRoot() {
    return root;
}
void NgramTree::printInorder (ostream& out, BinaryNode* node) {
    if (node != NULL) {
        printInorder(out, node->leftChildPtr);
        out << node->item << "[" << node->counter << "]" << " ";
        printInorder(out, node->rightChildPtr);
    }
}
ostream& operator<<(ostream& out, NgramTree tree) {
    tree.printInorder(out, tree.getRoot());
    return out;
}



