#include <iostream>
#include <queue>

#include "BinaryTree.h"
#include "Node.h"
using namespace std;

BinaryTree::BinaryTree()
{
    root = NULL;
}

Node *BinaryTree::createNode(int key)
{
    Node *node = new Node();

    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void BinaryTree::setDeepestRightNodeToNULL(Node *extremeRight)
{

    queue<Node *> q;
    q.push(root);

    Node *temp;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->left != NULL)
        {
            if (temp->left == extremeRight)
            {
                temp->left = NULL;
            }
            else
            {
                q.push(temp->left);
            }
        }

        if (temp->right != NULL)
        {
            if (temp->right == extremeRight)
            {
                temp->right = NULL;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }
}

Node *BinaryTree::search(int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    queue<Node *> q;
    Node *out = NULL;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->key == key)
        {
            cout << "HIT" << endl;
            out = temp;
        }

        if (temp->left != NULL)
        {
            q.push(temp->left);
        }

        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }

    return out;
}
void BinaryTree::insertNode(int key)
{
    if (root == NULL)
    {
        root = createNode(key);
        return;
    }
    Node *nodeToInsert = createNode(key);

    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left == NULL)
        {
            temp->left = nodeToInsert;
            return;
        }
        else
        {
            q.push(temp->left);
        }

        if (temp->right == NULL)
        {
            temp->right = nodeToInsert;
            return;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

Node *BinaryTree::getRoot()
{
    return root;
}

void BinaryTree::printInorder()
{
    Node *node = root;
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout << node->key << " ";
 
    /* now recur on right child */
    printInorder(node->right);
}

void BinaryTree::printInorder(Node *node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout << node->key << " ";
 
    /* now recur on right child */
    printInorder(node->right);
}

void BinaryTree::removeNode(int key)
{
    Node *nodeToDelete = search(key);
    queue<Node *> q;
    q.push(root);
    Node *temp;
    if (nodeToDelete == NULL)
    {
        cout << "Node not found";
        return;
    }
    else if (nodeToDelete->left == NULL && nodeToDelete->right == NULL) // nodo hoja
    {
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp->left != NULL)
            {
                if (temp->left == nodeToDelete)
                {
                    temp->left = NULL;
                }
                else
                {
                    q.push(temp->left);
                }
            }
            if (temp->right != NULL)
            {
                if (temp->right == nodeToDelete)
                {
                    temp->right = NULL;
                }
                else
                {
                    q.push(temp->right);
                }
            }
        }
    }
    else if (nodeToDelete->left == NULL || nodeToDelete->right == NULL) //nodo con un solo hijo
    {
        Node *childNode = nodeToDelete->right == NULL ? nodeToDelete->left : nodeToDelete->right;

        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            if (temp->left != NULL)
            {
                if (temp->left == nodeToDelete)
                {
                    temp->left = childNode;
                }
                else
                {
                    q.push(temp->left);
                }
            }

            if (temp->right != NULL)
            {
                if (temp->right == nodeToDelete)
                {
                    temp->right = childNode;
                }
                else
                {
                    q.push(temp->right);
                }
            }
        }
    }
    else //nodo con dos hijos
    {
        //Conseguir nodo en el extremo derecho
        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }

        int keyAtDeepestRight = temp->key;
        //borrar nodo extremo derecho(temp)
        setDeepestRightNodeToNULL(temp);
        //reemplazar valor de nodo a eliminar por nodo de extremo derecho
        nodeToDelete->key = keyAtDeepestRight;
    }
}