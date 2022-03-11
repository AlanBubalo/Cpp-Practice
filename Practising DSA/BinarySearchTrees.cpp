#include <iostream>
#include <cstddef>

using namespace std;	

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int d) : data(d), left(NULL), right(NULL) {}
};

class Solution{
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* currentNode;
                if (data <= root->data){
                    currentNode = insert(root->left, data);
                    root->left = currentNode;
                    return root;
                }
                currentNode = insert(root->right, data);
                root->right = currentNode;
                return root;
            }
        }

		int getHeight(Node* root){
            if (root == NULL) return -1;
            int b = getHeight(root->left);
            int a = getHeight(root->right);
            if (a > b) return a + 1;
            return b + 1;
        }

}; //End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;
    cin >> t;
    while(t-- > 0){
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << height;
    return 0;
}