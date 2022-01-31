//
// Created by Dilay Yiğit on 10.11.2021.
//

#ifndef HOMEWORK_2_NGRAMTREE_H
#define HOMEWORK_2_NGRAMTREE_H
#include <iostream>
#include "BinaryNode.h"
using namespace std;

class NgramTree {
    friend ostream& operator<<( ostream& out, NgramTree tree );
public:
    NgramTree();
    ~NgramTree();
    void addNgram(string ngram );
    int getTotalNgramCount();
    bool isComplete();
    bool isFull();
    void generateTree(string fileName, int n);
    void printInorder(ostream& out, BinaryNode* node);
    BinaryNode* getRoot();
    BinaryNode* findNode(BinaryNode* subTree, string target);
    void deleteNodes(BinaryNode* subPtr);
private:
    BinaryNode* root;
    BinaryNode* insertNode(BinaryNode* subPtr, BinaryNode* newPtr);
    void inorderCount (BinaryNode* root, int &counter);
    bool fullBinaryTree (BinaryNode* root);
    bool completeBinaryTree(BinaryNode *root);
};


#endif //HOMEWORK_2_NGRAMTREE_H
