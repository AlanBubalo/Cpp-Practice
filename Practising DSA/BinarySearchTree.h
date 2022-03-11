#include <iostream>
#include <cmath>
using namespace std;

/*
========== Binary Search Tree ==========

Functions:
    insert
    insertDistinct
    isEmpty
    printPreorder
    printInorder
    printPostorder
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
class BinarySearchTree
{
public:
    Node<T> *root;

    BinarySearchTree()
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

    // ---------- Inserts a node in a tree ----------

    void insertBST(T data)
    {
        root = insertRec(root, data);
    }

    Node<T> *insertRec(Node<T> *root, T data)
    {
        if (isEmpty(root))
            return new Node<T>(data);
        if (data < root->label)
        {
            root->left = insertRec(root->left, data);
            return root;
        }
        root->right = insertRec(root->right, data);
        return root;
    }

    // ---------- Inserts a node in a tree with distinct data ----------

    void insertBSTDistinct(T data)
    {
        root = insertDistinctRec(root, data);
    }

    Node<T> *insertDistinctRec(Node<T> *node, T data)
    {
        if (isEmpty(node))
            return new Node<T>(data);
        if (data < node->label)
        {
            node->left = insertDistinctRec(node->left, data);
            return node;
        }
        if (data > node->label)
        {
            node->right = insertDistinctRec(node->right, data);
            return node;
        }
        return node;
    }
    
    Node<T> *getNodeBST(T data)
    {
        return getNodeBST(root, data);
    }

    Node<T> *getNodeBST(Node<T> *node, T data)
    {
        while (!isEmpty(node))
        {
            if (data < node->label)
                node = node->left;
            else if (data > node->label)
                node = node->right;
            else
                return node;
        }
    }

    // ---------- Returns 1 if the node with that data exists, 0 otherwise ----------

    bool exists(T data)
    {
        return existsRec(root, data);
    }

    bool existsRec(Node<T> *node, T data)
    {
        if (isEmpty(node))
            return false;
        if (node->label == data)
            return true;
        if (node->label > data)
            return existsRec(node->left, data);
        if (node->label < data)
            return existsRec(node->right, data);
        return false;
    }

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
        printPreorderRec(root, separator);
    }

    void printPreorderRec(Node<T> *node, string separator = " ")
    {
        if (!isEmpty(node))
        {
            cout << node->label << separator;
            printPreorderRec(node->left, separator);
            printPreorderRec(node->right, separator);
        }
    }

    // ---------- Prints a tree in an inorder ----------

    void printInorder(string separator = " ")
    {
        printInorderRec(root, separator);
    }

    void printInorderRec(Node<T> *node, string separator = " ")
    {
        if (!isEmpty(node))
        {
            printInorderRec(node->left, separator);
            cout << node->label << separator;
            printInorderRec(node->right, separator);
        }
    }

    // ---------- Prints a tree in an postorder ----------

    void printPostorder(string separator = " ")
    {
        printPostorderRec(root, separator);
    }

    void printPostorderRec(Node<T> *node, string separator = " ")
    {
        if (!isEmpty(node))
        {
            printPostorderRec(node->left, separator);
            printPostorderRec(node->right, separator);
            cout << node->label << separator;
        }
    }

    // ---------- Prints a tree in a level order ----------

    void printLevelOrder(string separator = " ")
    {
        printLevelOrderRec(root, separator);
    }

    void printLevelOrderRec(Node<T> *node, string separator = " ")
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
        return heightRec(root);
    }

    int heightRec(Node<T> *root)
    {
        if (isEmpty(root))
            return 0;
        int b = heightRec(root->left);
        int a = heightRec(root->right);
        if (a > b)
            return a + 1;
        return b + 1;
    }

    // ---------- Returns a number od nodes in a tree ----------

    int count()
    {
        return countRec(root);
    }

    int countRec(Node<T> *root)
    {
        int c = 1;
        if (isEmpty(root))
            return 0;
        else
        {
            c += countRec(root->left);
            c += countRec(root->right);
            return c;
        }
    }



    void draw()
    {
        return drawRec(root);
    }

    void drawRec(Node<T> *root)
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
        root = deleteNodeRec(root, data);
    }

    Node<T> *deleteNodeRec(Node<T> *root, T data)
    {
        if (isEmpty(root))
            return root;
        if (data < root->label)
        {
            root->left = deleteNodeRec(root->left, data);
            return root;
        }
        if (data > root->label)
        {
            root->right = deleteNodeRec(root->right, data);
            return root;
        }
        if (root->left == NULL)
            return root->right;
        if (root->right == NULL)
            return root->left;
        Node<T> *temporary = minimumRight(root->right);
        root->label = temporary->label;
        root->right = deleteNodeRec(root->right, temporary->label);
        return root;
    }

    Node<T> *minimumRight(Node<T> *root)
    {
        Node<T> *temporary = root;
        while (temporary && !isEmpty(temporary->left))
            temporary = temporary->left;
        return temporary;
    }



};