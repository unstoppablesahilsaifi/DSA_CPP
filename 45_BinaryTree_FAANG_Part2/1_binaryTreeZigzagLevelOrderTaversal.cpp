#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ---------------------
// Node class definition
// ---------------------
class Node {
public:
    int data;       // Node ka value
    Node* left;     // Left child ka pointer
    Node* right;    // Right child ka pointer

    // Constructor -> jab naya Node banega tab initialize hoga
Node(int d) {
    data = d;
    left = nullptr;
    right = nullptr;
}
};

// ---------------------
// Zigzag Level Order Traversal
// ---------------------
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>> result;   // Final output list of levels

        // Agar root NULL hai to seedha empty return kar do
        if (!root) return result;

        // BFS ke liye queue use hoti hai
        queue<Node*> q;
        q.push(root);

        // Direction flag: true = left to right, false = right to left
        bool leftToRight = true;

        // Jab tak queue empty na ho tab tak levels traverse karo
        while (!q.empty()) {
            int size = q.size();              // current level me kitne nodes hai
            vector<int> level(size);          // current level ka result

            // Current level ke nodes process karo
            for (int i = 0; i < size; i++) {
                Node* node = q.front();       // queue ke front se node nikalo
                q.pop();

                // Agar leftToRight true hai to i pe rakho
                // agar false hai to ulta index (size - 1 - i)
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->data;

                // Next level ke liye children ko queue me daalo
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Current level ko result me add karo
            result.push_back(level);

            // Direction flip kar do
            leftToRight = !leftToRight;
        }

        return result;
    }
};

// ---------------------
// Driver Code (Testing)
// ---------------------
int main() {
    /*
        Example Tree:
                1
               / \
              2   3
             / \   \
            4   5   6

        Zigzag Order:
        [
          [1],
          [3,2],
          [4,5,6]
        ]
    */

    // Tree create karte hain
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // Solution object
    Solution sol;
    vector<vector<int>> ans = sol.zigzagLevelOrder(root);

   // Output print karna using normal for loops
cout << "Zigzag Level Order Traversal:" << endl;
for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << " ";
    }
    cout << endl;
}


    return 0;
}
