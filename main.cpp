#include <cstdlib>
#include <iostream>
#include <string>

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

    
    return 0;
}