#include <iostream>
#include <queue>

#include "Node.h"

using namespace std;

#ifndef BINARYTREE_H
#define BINARYTREE_H
class BinaryTree
{
private:
    Node *root;
    Node *createNode(int key);
    void setDeepestRightNodeToNULL(Node *extremeRight);
    void printInorder(Node *node);

public:
    BinaryTree();
    void insertNode(int key);
    Node *search(int key);
    void removeNode(int key);
    Node *getRoot();
    void printInorder();
};

#endif