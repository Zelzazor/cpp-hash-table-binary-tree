#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H

class HashTable
{
private:
    static const int tableSize = 40;

    struct item
    {
        string key;
        string value;
        item *next;
    };

    item *hashtable[tableSize];

    int Hash(string key);
    void PrintItemsInIndex(int index);

public:
    HashTable();
    int NumberOfItemsInIndex(int index);
    void AddItem(string name, string drink);
    void PrintTable();
    string GetValue(string name);
    void RemoveItem(string name);
};

#endif