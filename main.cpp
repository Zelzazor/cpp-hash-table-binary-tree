#include <cstdlib>
#include <iostream>
#include <string>

#include "HashTable.h"
#include "BinaryTree.h"
#include "Node.h"
using namespace std;

int main()
{

    BinaryTree tree;

    for (int i = 1; i < 6; i++)
    {
        tree.insertNode(i);
    }
    tree.insertNode(1);

    tree.removeNode(1);

    Node *nodo = tree.getRoot();

    cout << nodo->key << endl;

    tree.printInorder();
    cout << endl;

    HashTable hash;

    hash.AddItem("Samuel", "Coca cola");
    hash.AddItem("Emily", "Juguito");
    hash.AddItem("Juan", "Sprite");
    hash.AddItem("Felipe", "Seven Up");
    hash.AddItem("Carlos", "Romo");
    hash.AddItem("Sabrina", "Gatdrink");
    hash.AddItem("Salina", "Chuchita");
    hash.AddItem("Corto", "Zapatero");

    hash.RemoveItem("Corto");

    cout << endl
         << hash.GetValue("Samuel");
    cout << endl
         << hash.GetValue("Felipe");
    cout << endl
         << hash.GetValue("Corto");
    return 0;
}