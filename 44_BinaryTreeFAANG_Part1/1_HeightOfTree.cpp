#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    int height(Node* node) {
        if (node == nullptr) {
            return -1;  // empty tree ki height -1 rakhi, taaki ek node ka height 0 aaye
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }
};

// ------------------ Driver Code ------------------
int main() {
    /*
        Example tree:
              12
             /  \
            8    18
           / \
          5  11
        Input: [12, 8, 18, 5, 11]
        Expected height = 2
    */

    Node* root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);

    Solution obj;
    cout << obj.height(root) << endl; // Output: 2

    return 0;
}
