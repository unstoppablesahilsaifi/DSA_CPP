/*Tree traversal ka matlab hai tree ke saare nodes ko ek specific order me visit karna.

**Postorder Traversal Rule (LRN):**

1. **L** → Left Subtree traverse karo
2. **R** → Right Subtree traverse karo
3. **N** → Root Node ko visit karo (sabse last me print hoga)

👉 Matlab root hamesha **end me print hoga**, pehle left aur right subtrees process honge.

---

### 🔹 Example Tree:

```
        1
       / \
      2   3
     / \
    4   5
```

**Postorder Traversal**:
`4 5 2 3 1`*/




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

// ---------------- Postorder Traversal ----------------
/*
   Postorder Traversal (LRN):
   1. Left subtree traverse karo
   2. Right subtree traverse karo
   3. Root node print karo
*/
void postorder(Node* root) {
    if (root == NULL) return;   // base case

    postorder(root->left);      // Step 1: Left subtree
    postorder(root->right);     // Step 2: Right subtree
    cout << root->data << " ";  // Step 3: Root node
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

         Postorder = 4 5 2 3 1
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Postorder Traversal: ";
    postorder(root);   // Function call
    cout << endl;

    return 0;
}
