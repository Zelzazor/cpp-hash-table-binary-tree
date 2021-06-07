#include <iostream>
#include <queue>

#include "BinaryTree.h"
#include "Node.h"
using namespace std;

BinaryTree::BinaryTree()
{
    root = NULL; // inicializar arbol con raiz nula
}

Node *BinaryTree::createNode(int key)
{
    Node *node = new Node(); // crear nuevo nodo

    node->key = key;   // asignar key a nodo
    node->left = NULL; // hijos nulos
    node->right = NULL;

    return node;
}

void BinaryTree::setDeepestRightNodeToNULL(Node *extremeRight)
{

    queue<Node *> q;
    q.push(root);

    Node *temp;

    while (!q.empty()) //Busqueda transversal top down left right hasta encontrar el nodo del extremo derecho
    {
        temp = q.front();
        q.pop();

        if (temp->left != NULL)
        {
            if (temp->left == extremeRight)
            {
                temp->left = NULL; //Borramos su referencia
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
                temp->right = NULL; //Borramos su referencia
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
        return NULL; // Si la raiz es nula pues no se encontrara ningun nodo
    }

    queue<Node *> q;
    Node *out = NULL;
    q.push(root);

    while (!q.empty()) // Chequeo de forma transversal top down left right del nodo hasta finalmente encontrarlo o no encontrarlo
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
    if (root == NULL) // si no hay raiz
    {
        root = createNode(key); // entonces la raiz sera el nuevo nodo insertado
        return;
    }
    Node *nodeToInsert = createNode(key); // crear nodo con numero especificado

    queue<Node *> q; // cola de punteros de nodo

    q.push(root); // insertar root a la cola

    while (!q.empty()) // mientras la cola no este vacia
    {
        Node *temp = q.front(); // nodo mas delante de la cola
        q.pop();                // sacamos ese nodo

        if (temp->left == NULL) // si no hay hijo izquierdo
        {
            temp->left = nodeToInsert; // insertamos nodo en hijo izquierdo
            return;
        }
        else
        {
            q.push(temp->left); //ponemos hijo izquierdo en la cola
        }

        if (temp->right == NULL) // si es null el hijo derecho
        {
            temp->right = nodeToInsert; //insertamos el nodo que queremos insertaren hijo derecho
            return;
        }
        else
        {
            q.push(temp->right); // ponemos hijo derecho en la cola
        }
    }
}

Node *BinaryTree::getRoot()
{
    return root; // retorna raiz
}

void BinaryTree::printInorder()
{
    Node *node = root;
    if (node == NULL)
        return;

    /* primera recursion en el hijo izquierdo */
    printInorder(node->left);

    /* imprimimos la key de nodo */
    cout << node->key << " ";

    /* recursion en hijo derecho */
    printInorder(node->right);
}

void BinaryTree::printInorder(Node *node)
{
    if (node == NULL)
        return;

    /* primera recursion en el hijo izquierdo */
    printInorder(node->left);

    /* imprimimos la key de nodo */
    cout << node->key << " ";

    /* recursion en hijo derecho */
    printInorder(node->right);
}

void BinaryTree::removeNode(int key)
{
    Node *nodeToDelete = search(key); // buscar nodo que queremos borar
    queue<Node *> q;
    q.push(root);
    Node *temp;
    if (nodeToDelete == NULL) // Si no se encuentra
    {
        cout << "Node not found";
        return;
    }
    else if (nodeToDelete->left == NULL && nodeToDelete->right == NULL) // si es nodo hoja
    {
        while (!q.empty()) //Busqueda transversal del nodo hasta encontrarlo. Se elimina su referencia
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
        Node *childNode = nodeToDelete->right == NULL ? nodeToDelete->left : nodeToDelete->right; // Obtencion del nodo hijo del nodo que queremos borrar

        while (!q.empty()) // Busqueda transversal top bottom left right hasta encontrar el padre del nodo que queremos borrar
        {
            temp = q.front();
            q.pop();

            if (temp->left != NULL)
            {
                if (temp->left == nodeToDelete) // si el hijo izquierdo es el nodo que queremos borrar
                {
                    temp->left = childNode; // asignamos al nodo izquierdo del padre de nodo borrado, el nodo hijo del nodo borrado
                }
                else
                {
                    q.push(temp->left);
                }
            }

            if (temp->right != NULL) // si es el hijo derecho, el mismo proceso del izquierdo
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