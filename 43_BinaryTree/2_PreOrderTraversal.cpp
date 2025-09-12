/*Tree traversal ka matlab hai tree ke saare nodes ko ek specific order me visit karna.

Preorder Traversal Rule (NLR):

N → Root Node ko visit karo (print karo)

L → Left Subtree traverse karo

R → Right Subtree traverse karo

Matlab root hamesha sabse pehle print hoga, fir left subtree, fir right subtree.*/

/*        1
       / \
      2   3
     / \
    4   5
Preorder Traversal:
1 2 4 5 3

*/

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

// ---------------- Preorder Traversal ----------------
/*
   Preorder Traversal (NLR):
   1. Root print karo
   2. Left subtree traverse karo
   3. Right subtree traverse karo
*/
void preorder(Node* root) {
    if (root == NULL) {
        return; // base case: agar node null h to return
    }

    cout << root->data << " ";   // Step 1: Root visit
    preorder(root->left);        // Step 2: Left traverse
    preorder(root->right);       // Step 3: Right traverse
}

// ---------------- Main Function ----------------
int main() {
    // Tree create kar rahe manually:
    /*
              1
             / \
            2   3
           / \
          4   5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder Traversal: ";
    preorder(root);   // Function call
    cout << endl;

    return 0;
}
