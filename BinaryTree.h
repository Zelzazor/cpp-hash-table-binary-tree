#include <iostream>
#include <queue>

#include "Node.h"

using namespace std;

#ifndef BINARYTREE_H
#define BINARYTREE_H
class BinaryTree
{
private:
    Node *root;                // raiz del árbol
    Node *createNode(int key); // crear un nodo
    void setDeepestRightNodeToNULL(Node *extremeRight);
    void printInorder(Node *node); // imprimir arbol con orden transversal in order

public:
    BinaryTree();             // constructor de la clase
    void insertNode(int key); // insertar un nodo en orden transversal arriba abajo izquierda derecha(top down left right)
    Node *search(int key);    // buscar un nodo(con prioridad al que este mas abajo a la derecha)
    void removeNode(int key); // con la misma prioridad de la funcion search
    Node *getRoot();          // conseguir raiz para propositos de testing
    void printInorder();      // imprimir in order
};

#endif