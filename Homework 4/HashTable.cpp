/**
* Author : Dilay Yigit
* ID: 21602059
* Section: 01
* Assignment : 4 */

#include <iostream>
#include "HashTable.h"
using namespace std;

HashTable::HashTable(const int tableSize, const CollisionStrategy option) {
    this->option = option;
    size = tableSize;
    arr = new hashNode[size];
}

HashTable::~HashTable() {
    if (size != 0)
        delete[] arr;
}

bool HashTable::insert (const int item) {
    if(!isFull()) {
        if (option == LINEAR) {
            int hashKey = item % size;
            while(arr[hashKey].data != NULL) {
                hashKey = (hashKey + 1) % size;
            }
            arr[hashKey].data = item;
            arr[hashKey].state = 1;
            cout << "Item " << arr[hashKey].data << " is inserted." << endl;
            return true;
        }
        else if (option == QUADRATIC) {
            int i = 1;
            int hashKey = item % size;
            while(arr[hashKey].data != NULL) {
                hashKey = ((item % size) + (i*i)) % size;
                i++;
            }
            arr[hashKey].data = item;
            arr[hashKey].state = 1;
            cout << "Item " << arr[hashKey].data << " is inserted." << endl;
            return true;
        }
        else if (option == DOUBLE) {
            int i = 1;
            int hashKey = item % size; //h1(key)
            int reverseHashKey = reverse(item); //h2(key)
            while(arr[hashKey].data != NULL) {
                hashKey = ((item % size) + (i * reverseHashKey)) % size;
                i++;
            }
            arr[hashKey].data = item;
            arr[hashKey].state = 1;
            cout << "Item " << arr[hashKey].data << " is inserted." << endl;
            return true;
        }
        else {
            cout << "ERROR: Collision Strategy is not valid!" << endl;
            return false;
        }
    }
    else {
        cout << "ERROR: Table is full!" << endl;
        return false;
    }
}

bool HashTable::search(const int item, int &numProbes) {
    if (!isEmpty()){
        if (option == LINEAR) {
            int hashKey = item % size;
            while (arr[hashKey].state == 1) {
                numProbes++;
                if (arr[hashKey].data != item) {
                    hashKey = (hashKey + 1) % size;
                }
                else {
                    cout << "Item " << item << " is found after " << numProbes << " probes." << endl;
                    return true;
                }
            }
            cout << "Item " << item << " is not found after " << numProbes << " probes." << endl;
            return false;
        } else if (option == QUADRATIC) {
            int i = 1;
            int hashKey = item % size;
            while (arr[hashKey].state == 1) {
                numProbes++;
                if (arr[hashKey].data != item) {
                    hashKey = ((item % size) + (i * i)) % size;
                    i++;
                }
                else {
                    cout << "Item " << item << " is found after " << numProbes << " probes." << endl;
                    return true;
                }
            }
            cout << "Item " << item << " is not found after " << numProbes << " probes." << endl;
            return false;
        } else if (option == DOUBLE) {
            int i = 1;
            int hashKey = item % size; // h1(key)
            int reverseHashKey = reverse(item); // h2(key)
            while (arr[hashKey].state == 1) {
                numProbes++;
                if (arr[hashKey].data != item) {
                    hashKey = ((item % size) + (i * reverseHashKey)) % size;
                    i++;
                }
                else {
                    cout << "Item " << item << " is found after " << numProbes << " probes." << endl;
                    return true;
                }
            }
            cout << "Item " << item << " is not found after " << numProbes << " probes." << endl;
            return false;
        } else {
            cout << "ERROR: Collision Strategy is not valid!" << endl;
            return false;
        }
    }
    else {
        cout << "ERROR: Table is empty!" << endl;
        return false;
    }
}

void HashTable::analyze(int &numSuccProbes, int &numUnsuccProbes) {
    if (option == LINEAR) {
        int success;
        int unsuccess;
        for (int i = 0; i < size; i++) {
            if (arr[i].state == 1 && arr[i].data != NULL) {
                success = 0;
                search(arr[i].data, success);
                numSuccProbes = numSuccProbes + success;
            }
        }
        double succResult = (double) numSuccProbes / size;
        cout << "------------------------------------------------" << endl;
        cout << "Average number of successful search: " << succResult << endl;
        cout << "------------------------------------------------" << endl;

        for (int i = 0; i < size; i++) {
            unsuccess = 0;
            search(i, unsuccess);
            numUnsuccProbes = numUnsuccProbes + unsuccess;
        }
        double unsuccResult = (double) numUnsuccProbes / size;
        cout << "------------------------------------------------" << endl;
        cout << "Average number of unsuccessful search: " << unsuccResult << endl;
    } else if (option == QUADRATIC) {
        int success;
        int unsuccess;
        for (int i = 0; i < size; i++) {
            if (arr[i].state == 1 && arr[i].data != NULL) {
                success = 0;
                search(arr[i].data, success);
                numSuccProbes = numSuccProbes + success;
            }
        }
        double succResult = (double) numSuccProbes / size;
        cout << "------------------------------------------------" << endl;
        cout << "Average number of successful search: " << succResult << endl;
        cout << "------------------------------------------------" << endl;

        for (int i = 0; i < size; i++) {
            unsuccess = 0;
            search(i, unsuccess);
            numUnsuccProbes = numUnsuccProbes + unsuccess;
        }
        double unsuccResult = (double) numUnsuccProbes / size;
        cout << "------------------------------------------------" << endl;
        cout << "Average number of unsuccessful search: " << unsuccResult << endl;
    } else if (option == DOUBLE) {
        int success;
        int unsuccess;
        for (int i = 0; i < size; i++) {
            if (arr[i].state == 1 && arr[i].data != NULL) {
                success = 0;
                search(arr[i].data, success);
                numSuccProbes = numSuccProbes + success;
            }
        }
        double succResult = (double) numSuccProbes / size;
        cout << "------------------------------------------------" << endl;
        cout << "Average number of successful search: " << succResult << endl;
    }
}

bool HashTable::remove(const int item) {
    if (!isEmpty()) {
        if (option == LINEAR) {
            int hashKey = item % size;
            while (arr[hashKey].state == 1) {
                if (arr[hashKey].data != item) {
                    hashKey = (hashKey + 1) % size;
                }
                else {
                    arr[hashKey].data = NULL;
                    cout << "Item " << item << " is removed." << endl;
                    return true;
                }
            }
            cout << "Item is not removed!" << endl;
            return false;
        } else if (option == QUADRATIC) {
            int i = 1;
            int hashKey = item % size;
            while (arr[hashKey].state == 1) {
                if (arr[hashKey].data != item) {
                    hashKey = ((item % size) + (i * i)) % size;
                    i++;
                }
                else {
                    arr[hashKey].data = NULL;
                    cout << "Item " << item << " is removed." << endl;
                    return true;
                }
            }
            cout << "Item is not removed!" << endl;
            return false;
        } else if (option == DOUBLE) {
            int i = 1;
            int hashKey = item % size;
            int reverseHashKey = reverse(item);
            while (arr[hashKey].state == 1) {
                if (arr[hashKey].data != item) {
                    hashKey = ((item % size) + (i * reverseHashKey)) % size;
                    i++;
                }
                else {
                    arr[hashKey].data = NULL;
                    cout << "Item " << item << " is removed." << endl;
                    return true;
                }
            }
            cout << "Item is not removed!" << endl;
            return false;
        } else {
            cout << "ERROR: Collision Strategy is not valid!" << endl;
            return false;
        }
    }
    else {
        cout << "ERROR: Table is empty!" << endl;
        return false;
    }
}

bool HashTable::isFull() {
    for (int i = 0; i < size; i++) {
        if (arr[i].data == NULL) {
            return false;
        }
    }
    return true;
}

bool HashTable::isEmpty() {
    for (int i = 0; i < size; i++) {
        if (arr[i].data != NULL) {
            return false;
        }
    }
    return true;
}

void HashTable::display() {
    cout << "------------------------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << i << ": " << arr[i].data << endl;
    }
    cout << "------------------------------------------------" << endl;
}

int HashTable::reverse(int num) {
    int remain;
    int reverse;
    while(num != 0) {
        remain = num % 10;
        reverse = reverse*10 + remain;
        num = num / 10;
    }
    return reverse;
}