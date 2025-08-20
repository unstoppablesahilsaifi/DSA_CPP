#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

// Floyd's Cycle Detection Algorithm
Node* floydDetectLoop(Node* head) {
    if (head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast) {
            return slow; // loop detected
        }
    }
    return NULL; // no loop
}

// Function to check if list contains loop
bool isCircular(Node* head) {
    return (floydDetectLoop(head) != NULL);
}

int main() {
    // Create nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    // Connect nodes → creating a loop
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // loop created (n4 -> n2)

    // Detect loop
    if (isCircular(n1)) {
        cout << "Loop detected in Linked List " << endl;
    } else {
        cout << "No Loop found" << endl;
    }

    // Example 2: No loop
    Node* a1 = new Node(10);
    Node* a2 = new Node(20);
    Node* a3 = new Node(30);

    a1->next = a2;
    a2->next = a3;
    a3->next = NULL; // no loop

    if (isCircular(a1)) {
        cout << "Loop detected in Linked List " << endl;
    } else {
        cout << "No Loop found " << endl;
    }

    return 0;
}


// do pointer chalaye, ekk fast and ek slow, jab dono meet kr jaye mtlb loop h and nhi h