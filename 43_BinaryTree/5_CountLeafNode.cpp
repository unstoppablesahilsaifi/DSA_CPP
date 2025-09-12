/*  // Tree create karte hain
        /*
                 1
               /   \
              2     3
             / \   / \
            4   5 6   7
                     /
                    8


 Total Leaf Nodes: 4                   
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;  
    Node* right;  

    // Constructor to create data node
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL; 
    }
};

// Function to count leaf nodes
int leafCount(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return leafCount(root->left) + leafCount(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);

    int count = leafCount(root); 
    cout << "Total Count: " << count << endl;

    return 0;
}
