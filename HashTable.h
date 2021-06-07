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

    struct item // key value pairs
    {
        string key;
        string value;
        item *next;
    };

    item *hashtable[tableSize]; // arreglo de buckets

    int Hash(string key);              // funcion hash para obtener indice
    void PrintItemsInIndex(int index); // imprimir items en indice especifico

public:
    HashTable();                            // constructor
    int NumberOfItemsInIndex(int index);    // numero de itemes en indice especifico
    void AddItem(string key, string value); // agregar item al diccionario
    void PrintTable();                      // imprimir tabla
    string GetValue(string key);            // Conseguir value dado key
    void RemoveItem(string key);            // Remover key value pair dado key
};

#endif