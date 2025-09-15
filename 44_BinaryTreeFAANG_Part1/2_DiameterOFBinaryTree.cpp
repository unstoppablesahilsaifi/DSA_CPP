#include <bits/stdc++.h>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    // Height function (edges ke terms mein)
    int height(Node* node) {
        if (node == nullptr) {
            return -1;  
            // empty tree = -1
            // ek single node ka height = 0
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

    // Diameter function (O(n^2))
    int diameter(Node* root) {
        if (root == nullptr) return 0;

        // 1. Left subtree diameter
        int leftDia = diameter(root->left);

        // 2. Right subtree diameter
        int rightDia = diameter(root->right);

        // 3. Diameter passing through root
        int throughRoot = height(root->left) + height(root->right) + 2;
        // +2 because leftHeight & rightHeight are in edges (starting from -1)

        // max of three
        return max({leftDia, rightDia, throughRoot});
    }
};

int main() {
    /*
        Tree:
                 12
               /    \
              8      18
             / \
            5  11
    */

    Node* root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);

    Solution obj;

    cout << "Height of tree (in edges) = " << obj.height(root) << endl;
    cout << "Diameter (in edges) = " << obj.diameter(root) << endl;
    cout << "Diameter (in nodes) = " << obj.diameter(root) + 1 << endl;

    /*
        Expected Output:
        Height of tree (in edges) = 2
        Diameter (in edges) = 3
        Diameter (in nodes) = 4
    */

    return 0;
}
