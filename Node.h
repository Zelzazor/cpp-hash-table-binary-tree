#ifndef NODE_H
#define NODE_H

struct Node
{
    //Nodos del árbol con un valor y sus hijos izquierdo y derecho
    int key;
    Node *left;
    Node *right;
};

#endif