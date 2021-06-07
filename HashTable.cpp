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
    //Inicializar diccionario con un key value pair vacio
}

int HashTable::Hash(string key)
{
    //Calculo de indice o bucket
    int hash = 0;
    int index;

    for (int i = 0; i < key.length(); i++)
    {
        hash += (int)key[i] * 21;
    }

    index = hash % tableSize;

    return index;
}

void HashTable::AddItem(string key, string value)
{
    int index = Hash(key);

    if (hashtable[index]->key == "empty") // Si el indice esta vacio
    {
        // Agregarlo como primer item
        hashtable[index]->key = key;
        hashtable[index]->value = value;
    }
    else
    {
        //Si no esta vacio, agregarlo al final del linked list
        item *Ptr = hashtable[index];
        item *n = new item;
        n->key = key;
        n->value = value;
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
    item *Ptr = hashtable[index]; // tomar linked list del indice

    if (Ptr->key == "empty") //Si indice esta vacio no imprimir nada
    {
        cout << "index: " << index << " esta vacio" << endl;
    }
    else
    { // imprimir cada item del linked list
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
    //Conteo de items en indice especificado
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

string HashTable::GetValue(string key)
{
    int index = Hash(key);
    bool foundName = false;
    string value;

    item *Ptr = hashtable[index]; //Buscar indice donde deberia estar el key value pair

    while (Ptr != NULL) //Recorrer linked list en busca del key para retornar el value del key value pair
    {
        if (Ptr->key == key)
        {
            return Ptr->value;
        }
        Ptr = Ptr->next;
    }
    //Si llega aqui es que no encontro el key por lo que no se ha agregado al hashtable
    cout << "Key no encontrada.";
    return "";
}

void HashTable::RemoveItem(string key)
{
    int index = Hash(key);
    bool found = true;

    item *delPtr;
    item *p1;
    item *p2;

    if (hashtable[index]->key == "empty" && hashtable[index]->value == "empty") //El index esta vacio
    {
        found = false;
    }
    else if (hashtable[index]->key == key && hashtable[index]->next == NULL) // index tiene 1 elemento y es el que queremos remover.
    {
        hashtable[index]->key = "empty";
        hashtable[index]->value = "empty";
    }
    else if (hashtable[index]->key == key) //index tiene varios elementos y el primero es el que queremos remover.
    {
        delPtr = hashtable[index];
        hashtable[index] = hashtable[index]->next; //hacer que el primer elemento del linked list sea el siguiente del primer elemento para borrarlo
        delete delPtr;
    }
    else // index tiene varios elementos y puede o no que este el elemento
    {
        p1 = hashtable[index]->next;
        p2 = hashtable[index];

        while (p1 != NULL && p1->key != key) // mientras no se encuentre el key
        {
            p2 = p1;       // Se va guardando donde se quedo el recorrido
            p1 = p1->next; // recorriendo el linked list
        }

        if (p1 == NULL) //Si p1 termina siendo null es que nunca se encontro el key en el linked list del indice
        {

            found = false;
        }
        else
        {
            delPtr = p1;   //Se almacena para ser borrado de memoria
            p1 = p1->next; //p1 entonces es eliminado asignandole el siguiente en la linked list
            p2->next = p1; // el que era anterior a p1 tambien debe ser enlazado asignando su siguiente de nuevo al nuevo p1

            delete delPtr;
        }
    }

    if (found)
    {
        cout << "La clave " << key << " fue eliminada del hash";
    }
    else
    {
        cout << "La clave " << key << " no fue encontrada en tabla hash.";
    }
}