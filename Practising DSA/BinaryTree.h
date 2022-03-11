#include <iostream>
#include <cmath>
using namespace std;

/*
========== Binary Tree ==========

Functions:
    newRoot
    getRoot
    getLeft
    getRight
    insert
    isEmpty
    printPreorder
    printInorder
    printPostorder
    printLevelOrder
    height
    deleteNode
*/

template <class T>
class Node
{
public:
    T label;
    Node *left, *right;

    Node(T value)
        : label(value),
          left(NULL),
          right(NULL) {}
};

template <class T>
class BinaryTree
{
public:
    Node<T> *root;

    BinaryTree()
        : root(NULL) {}

    // ---------- Emptying your tree and adding value to a root ----------

    void newRoot(T data)
    {
        root = new Node<T>(data);
    }

    // ---------- Get the root node of a tree ----------

    Node<T> *getRoot()
    {
        return root;
    }

    // ---------- Get the node's left child of a tree ----------

    Node<T> *getLeft(Node<T> *node)
    {
        return node->left;
    }

    // ---------- Get the node's right child of a tree ----------

    Node<T> *getRight(Node<T> *node)
    {
        return node->right;
    }

    // ---------- Get the node of a tree with that specific data ----------
    // ------------- if that node doesn't exists, returns NULL ------------

    /* NOT WORKING LMAO

    Node<T> *getNode(T data)
    {
        return getNode(root, data);
    }

    Node<T> *getNode(Node<T> *node, T data)
    {
        if (!isEmpty(node->left) || !isEmpty(node->right)){
            if (node->label == data)
                return node;
            node->left = getNode(node->left, data);
            node->right = getNode(node->right, data);
        }
        else
            return node;
    }
    */

    // ---------- Returns 1 if the node with that data exists, 0 otherwise ----------

    

    // ---------- Returns 1 if the tree is empty, 0 otherwise ----------

    bool isEmpty()
    {
        return !root;
    }

    bool isEmpty(Node<T> *node)
    {
        return !node;
    }

    // ---------- Prints a tree in an preorder ----------

    void printPreorder(string separator = " ")
    {
        printPreorder(root, separator);
    }

    void printPreorder(Node<T> *node, string separator = " ")
    {
        if (!isEmpty(node))
        {
            cout << node->label << separator;
            printPreorder(node->left, separator);
            printPreorder(node->right, separator);
        }
    }

    // ---------- Prints a tree in an inorder ----------

    void printInorder(string separator = " ")
    {
        printInorder(root, separator);
    }

    void printInorder(Node<T> *node, string separator = " ")
    {
        if (!isEmpty(node))
        {
            printInorder(node->left, separator);
            cout << node->label << separator;
            printInorder(node->right, separator);
        }
    }

    // ---------- Prints a tree in an postorder ----------

    void printPostorder(string separator = " ")
    {
        printPostorder(root, separator);
    }

    void printPostorder(Node<T> *node, string separator = " ")
    {
        if (!isEmpty(node))
        {
            printPostorder(node->left, separator);
            printPostorder(node->right, separator);
            cout << node->label << separator;
        }
    }

    // ---------- Prints a tree in a level order ----------

    void printLevelOrder(string separator = " ")
    {
        printLevelOrder(root, separator);
    }

    void printLevelOrder(Node<T> *node, string separator = " ")
    {
        int h = height();
        for (int i = 1; i <= h; i++)
            printCurrentLevel(node, i, separator);
    }

    void printCurrentLevel(Node<T> *node, int level, string separator = " ")
    {
        if (isEmpty(node))
            return;
        if (level == 1)
            cout << node->label << separator;
        else if (level > 1)
        {
            printCurrentLevel(node->left, level - 1, separator);
            printCurrentLevel(node->right, level - 1, separator);
        }
    }

    // ---------- Returns a height of a tree ----------

    int height()
    {
        return height(root);
    }

    int height(Node<T> *node)
    {
        if (isEmpty(node))
            return 0;
        int b = height(node->left);
        int a = height(node->right);
        if (a > b)
            return a + 1;
        return b + 1;
    }

    // ---------- Returns a number od nodes in a tree ----------

    int count()
    {
        return count(root);
    }

    int count(Node<T> *node)
    {
        int c = 1;
        if (isEmpty(node))
            return 0;
        c += count(node->left);
        c += count(node->right);
        return c;
    }

    // ---------- Draws a tree graphically (DOESN'T WORK PROPERLY) ----------

    void draw()
    {
        int h = height();
        for (int i = 1; i <= h; i++)
        {
            string separator = " ";
            for (int j = 1; j <= pow(h - i, 2); j++)
            {
                cout << " ";
            }
            for (int j = 1; j <= pow(h - i + 1, 2); j++)
            {
                separator.append(" ");
            }
            printCurrentLevel(root, i, separator);
            cout << "\n";
        }
    }

    // ---------- Deletes one node and fixes a BST ----------

    void deleteNode(T data)
    {
        root = deleteNode(root, data);
    }

    Node<T> *deleteNode(Node<T> *node, T data)
    {
        if (isEmpty(node))
            return node;
        node->left = deleteNode(node->left, data);
        node->right = deleteNode(node->right, data);
        if (node->label == data)
            deleteAll(node);
    }

    void deleteAll(Node<T> *node)
    {
        if (!isEmpty(node))
        {
            deleteAll(node->left);
            deleteAll(node->right);
            delete node;
        }
    }

};