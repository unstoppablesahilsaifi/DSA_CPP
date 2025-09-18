/*Problem Statement:
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Class: Node
 * Ek basic binary tree node define kar raha hai
 */
class Node {
public:
    int val;       // Node value
    Node* left;    // Left child
    Node* right;   // Right child

    // Constructor
    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    /**
     * Function: isSameTree
     * Input: 2 tree roots (p, q)
     * Output: true agar dono structurally same hain aur values same hain
     */
    bool isSameTree(Node* p, Node* q) {
        // Base case: dono null -> same tree
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // Base case: ek null hai aur dusra null nahi -> alag tree
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // Agar current node ka value alag hai -> not same
        if (p->val != q->val) {
            return false;
        }

        // Recursively check karo left subtree aur right subtree
         bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        bool check = p->val == q->val;

        if(left && right && check){
            return true;
        }
        return false;
    }
};

// ------------------ Driver Code for Testing ------------------
int main() {
    /**
     * Tree 1:         1
     *                / \
     *               2   3
     * 
     * Tree 2:         1
     *                / \
     *               2   3
     */
    Node* p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(3);

    Node* q = new Node(1);
    q->left = new Node(2);
    q->right = new Node(3);

    Solution obj;
    if (obj.isSameTree(p, q)) {
        cout << "Trees are SAME " << endl;
    } else {
        cout << "Trees are DIFFERENT " << endl;
    }

    return 0;
}
