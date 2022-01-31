/**
* Author : Dilay Yigit
* ID: 21602059
* Section: 01
* Assignment : 4 */

#ifndef HOMEWORK4_HASHTABLE_H
#define HOMEWORK4_HASHTABLE_H

enum CollisionStrategy { LINEAR, QUADRATIC, DOUBLE };

class HashTable {
public:
    HashTable (const int tableSize, const CollisionStrategy option);
    ~HashTable();
    bool insert (const int item);
    bool remove (const int item);
    bool search (const int item, int& numProbes);
    void analyze (int& numSuccProbes, int& numUnsuccProbes);
    void display();
    bool isFull();
    bool isEmpty();
    int reverse(int num);
    
private:
    struct hashNode {
        int data;
        int state = 0; // first, it is empty.
        /*
         * LOCATION'S STATE:
         * 0 for empty,
         * 1 for occupied.
         */
    };
    int size;
    hashNode* arr;
    CollisionStrategy option;
};


#endif //HOMEWORK4_HASHTABLE_H
