#include <cstdlib>
#include <iostream>
#include <string>

#include "HashTable.h"
using namespace std;

HashTable::HashTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        hashtable[i] = new item;
        hashtable[i]->key = "empty";
        hashtable[i]->value = "empty";
        hashtable[i]->next = NULL;
    }
}

int HashTable::Hash(string key)
{
    int hash = 0;
    int index;

    for (int i = 0; i < key.length(); i++)
    {
        hash += (int)key[i] * 21;
    }

    index = hash % tableSize;

    return index;
}

void HashTable::AddItem(string name, string drink)
{
    int index = Hash(name);

    if (hashtable[index]->key == "empty")
    {
        hashtable[index]->key = name;
        hashtable[index]->value = drink;
    }
    else
    {
        item *Ptr = hashtable[index];
        item *n = new item;
        n->key = name;
        n->value = drink;
        n->next = NULL;

        while (Ptr->next != NULL)
        {
            Ptr = Ptr->next;
        }

        Ptr->next = n;
    }
}

void HashTable::PrintTable()
{
    int number;
    for (int i = 0; i < tableSize; i++)
    {
        number = NumberOfItemsInIndex(i);
        PrintItemsInIndex(i);
    }
}

void HashTable::PrintItemsInIndex(int index)
{
    item *Ptr = hashtable[index];

    if (Ptr->key == "empty")
    {
        cout << "index: " << index << " esta vacio" << endl;
    }
    else
    {
        cout << "-------------\n";
        cout << "index: " << index << endl;
        while (Ptr != NULL)
        {

            cout << Ptr->key << "-->" << Ptr->value << endl;
            Ptr = Ptr->next;
        }
        cout << "-------------\n";
    }
}

int HashTable::NumberOfItemsInIndex(int index)
{
    int count = 0;

    item *Ptr = hashtable[index];

    if (Ptr->key == "empty")
    {
        return count;
    }
    else
    {
        while (Ptr->next != NULL)
        {
            Ptr = Ptr->next;
            count++;
        }
    }

    return count;
}

string HashTable::GetValue(string name)
{
    int index = Hash(name);
    bool foundName = false;
    string value;

    item *Ptr = hashtable[index];

    while (Ptr != NULL)
    {
        if (Ptr->key == name)
        {
            return Ptr->value;
        }
        Ptr = Ptr->next;
    }

    cout << "Key no encontrada.";
    return "";
}

void HashTable::RemoveItem(string name)
{
    int index = Hash(name);
    bool found = true;

    item *delPtr;
    item *p1;
    item *p2;

    //El index esta vacio
    if (hashtable[index]->key == "empty" && hashtable[index]->value == "empty")
    {
        found = false;
    }
    else if (hashtable[index]->key == name && hashtable[index]->next == NULL) // index tiene 1 elemento y es el que queremos remover.
    {
        hashtable[index]->key = "empty";
        hashtable[index]->value = "empty";
    }
    else if (hashtable[index]->key == name) //index tiene varios elementos y el primero es el que queremos remover.
    {
        delPtr = hashtable[index];
        hashtable[index] = hashtable[index]->next;
        delete delPtr;
    }
    else // index tiene varios elementos y puede o no que este el elemento
    {
        p1 = hashtable[index]->next;
        p2 = hashtable[index];

        while (p1 != NULL && p1->key != name)
        {
            p2 = p1;
            p1 = p1->next;
        }

        if (p1 == NULL)
        {

            found = false;
        }
        else
        {
            delPtr = p1;
            p1 = p1->next;
            p2->next = p1;

            delete delPtr;
        }
    }

    if (found)
    {
        cout<<"La clave " << name << " fue eliminada del hash";
    }
    else
    {
        cout<<"La clave " << name << " no fue encontrada en tabla hash.";
    }
}