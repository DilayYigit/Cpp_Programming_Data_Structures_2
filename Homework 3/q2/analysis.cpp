/*
* Title : Heaps and AVL Trees
* Author : Dilay Yigit
* ID : 21602059
* Section : 01
* Assignment : 3
* Description : analysis source file
*/

#include <cstdlib>
#include "analysis.h"
#include <iostream>
using namespace std;

void rotationAnalysis() {

    cout << "Array Size\t\t Random\t\t Ascending\t\t Descending\t\t" << endl;

    for (int i = 10000; i > 999; i = i - 1000) {
        cout << i << "\t\t\t";
        int size = i;

        AVLTree a;
        for (int j = 0; j < size; j++) {
            a.insert((rand() % 100000) + 1);
        }
        cout << a.getNumberOfRotations() << "\t\t\t";

        AVLTree b;
        for (int j = 0; j < size; j++) {
            b.insert(j);
        }
        cout << b.getNumberOfRotations() << "\t\t\t";

        AVLTree c;
        for (int j = size; j > 0; j--) {
            c.insert(j);
        }
        cout << c.getNumberOfRotations() << "\t\t\t" << endl;
    }
}