/**
* Author : Dilay Yigit
* ID: 21602059
* Section: 01
* Assignment : 4 */

#include "HashTable.h"
#include <iostream>
using namespace std;

int main() {
    int probes;
    int succ;
    int unsucc;


    cout << "-----------------------LINEAR--------------------------" << endl;
    HashTable l(20, LINEAR);

    l.insert(123);
    l.insert(124);
    l.insert(253);
    l.insert(618);
    l.insert(534);
    l.insert(412);
    l.insert(513);
    l.insert(617);
    l.insert(136);
    l.insert(497);
    l.display();

    probes = 0;
    l.search(253, probes);
    probes = 0;
    l.remove(412);
    l.search(497, probes);
    probes = 0;
    l.search(253, probes);
    l.remove(617);
    probes = 0;
    l.search(211, probes);
    l.display();

    succ = 0;
    unsucc = 0;
    l.analyze(succ, unsucc);

    cout << endl;
    cout << "-----------------------QUADRATIC--------------------------" << endl;
    HashTable q(20, QUADRATIC);
    q.insert(123);
    q.insert(124);
    q.insert(253);
    q.insert(618);
    q.insert(534);
    q.insert(412);
    q.insert(513);
    q.insert(617);
    q.insert(136);
    q.insert(497);
    q.display();

    probes = 0;
    q.search(253, probes);
    probes = 0;
    q.remove(412);
    q.search(497, probes);
    probes = 0;
    q.search(253, probes);
    q.remove(617);
    probes = 0;
    q.search(211, probes);
    q.display();

    succ = 0;
    unsucc = 0;
    q.analyze(succ, unsucc);

    cout << endl;
    cout << "-----------------------DOUBLE--------------------------" << endl;
    HashTable d(20, DOUBLE);
    d.insert(123);
    d.insert(124);
    d.insert(253);
    d.insert(618);
    d.insert(534);
    d.insert(412);
    d.insert(513);
    d.insert(617);
    d.insert(136);
    d.insert(497);
    d.display();

    probes = 0;
    d.search(253, probes);
    probes = 0;
    d.remove(412);
    d.search(497, probes);
    probes = 0;
    d.search(253, probes);
    d.remove(617);
    probes = 0;
    d.search(211, probes);
    d.display();

    succ = 0;
    unsucc = 0;
    d.analyze(succ, unsucc);
    return 0;
}

