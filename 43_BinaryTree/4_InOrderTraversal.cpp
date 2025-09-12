/*Tree traversal ka matlab hai tree ke nodes ko ek fixed order me visit karna.

**Inorder Traversal Rule (LNR):**

1. **L** → Left Subtree traverse karo
2. **N** → Root Node visit karo
3. **R** → Right Subtree traverse karo

👉 Matlab root hamesha **beech me print hoga** (pehle left, fir root, fir right).

---

### 🔹 Example Tree:

```
        1
       / \
      2   3
     / \
    4   5
```

**Inorder Traversal**:
`4 2 5 1 3`*/



#include <iostream>
using namespace std;

// ---------------- Node Structure ----------------
class Node {
public:
    int data;      // Node ka value
    Node* left;    // Left child pointer
    Node* right;   // Right child pointer

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// ---------------- Inorder Traversal ----------------
/*
   Inorder Traversal (LNR):
   1. Left subtree traverse karo
   2. Root node print karo
   3. Right subtree traverse karo
*/
void inorder(Node* root) {
    if (root == NULL) return;   // base case

    inorder(root->left);        // Step 1: Left subtree
    cout << root->data << " ";  // Step 2: Root node
    inorder(root->right);       // Step 3: Right subtree
}

// ---------------- Main Function ----------------
int main() {
    /*
         Manually Creating Tree:
                1
               / \
              2   3
             / \
            4   5

         Inorder = 4 2 5 1 3
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder Traversal: ";
    inorder(root);   // Function call
    cout << endl;

    return 0;
}
