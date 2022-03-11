#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree<int> bst1;
    int n, element;
    cout << "Size of BST: ";
    cin >> n;
    cout << "Elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        bst1.insertBSTDistinct(element);
    }

    if (bst1.isEmpty())
        cout << "BST is empty";
    else
        cout << "BST is not empty";
    cout << endl;

    cout << "Inorder: \n";
    bst1.printInorder(" ");
    cout << "\n";
    cout << "Preorder: \n";
    bst1.printPreorder(" ");
    cout << "\n";
    cout << "Postorder: \n";
    bst1.printPostorder(" ");
    cout << "\n";

    cout << "Height of BTS: " << bst1.height() << endl;

    cout << "Deleting node 10..." << endl;
    bst1.deleteNode(10);

    cout << "Inorder: \n";
    bst1.printInorder(" ");
    cout << "\n";
    cout << "Preorder: \n";
    bst1.printPreorder(" ");
    cout << "\n";
    cout << "Postorder: \n";
    bst1.printPostorder(" ");
    cout << "\n";
}