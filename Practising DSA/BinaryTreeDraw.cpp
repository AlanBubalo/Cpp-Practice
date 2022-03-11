#include <iostream>
#include <cmath>
using namespace std;
#include "BinaryTree.h"
/*
void print(int n)
{
    Node<int>* current = Thomas.root;
    for (int i = 0; i < n && isEmpty(current); i++)
    {
        if 0
            current = current->left;
        else
            current = current->right;
    }
    cout << current->data;
    print(n+1)
}
*/
int main()
{
    BinaryTree<int> Thomas;
    Thomas.newRoot(5);
    Thomas.root->left = new Node<int>(3);
    Thomas.root->right = new Node<int>(7);
    Thomas.root->left->left = new Node<int>(9);
    Thomas.root->left->right = new Node<int>(8);
    Thomas.root->right->left = new Node<int>(2);
    Thomas.root->right->right = new Node<int>(4);

    Thomas.printPreorder(" ");
    cout << "\n";

    Thomas.printInorder(" ");
    cout << "\n";

    Thomas.printLevelOrder(" ");
    cout << "\n" << "Thomas.height() = " << Thomas.height();
    cout << "\n" << "Thomas.count() = " << Thomas.count() << "\n";

    Thomas.deleteNode(3);
    cout << "Deleted node 3";

    Thomas.printPreorder(" ");
    cout << "\n";

    return 0;
}