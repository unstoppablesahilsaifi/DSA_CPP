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

// Function to check if Linked List is circular
bool checkCircular(Node* head) {
    if (head == NULL) return false; // empty list can't be circular

    Node* temp = head->next;

    // Traverse until NULL or back to head
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    // if temp == head → circular, else not
    return (temp == head);
}

int main() {
    // Example 1: Circular list
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->next = n2;
    n2->next = n3;
    n3->next = n1;  // circular link

    cout << (checkCircular(n1) ? "Circular" : "Not Circular") << endl;

    // Example 2: Non-circular list
    Node* a1 = new Node(10);
    Node* a2 = new Node(20);
    Node* a3 = new Node(30);

    a1->next = a2;
    a2->next = a3;
    a3->next = NULL; // not circular

    cout << (checkCircular(a1) ? "Circular" : "Not Circular") << endl;

    return 0;
}
