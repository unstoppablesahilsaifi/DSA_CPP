#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* sortList(Node* head) {
    int zero = 0, one = 0, two = 0;

    // Step 1: Count 0, 1, 2
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == 0) zero++;
        else if (temp->data == 1) one++;
        else if (temp->data == 2) two++;
        temp = temp->next;
    }

    // Step 2: Overwrite values according to count
    Node* curr = head;
    while (curr != NULL) {
        if (zero > 0) {
            curr->data = 0;
            zero--;
        } else if (one > 0) {
            curr->data = 1;
            one--;
        } else if (two > 0) {
            curr->data = 2;
            two--;
        }
        curr = curr->next;
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* n1 = new Node(2);
    Node* n2 = new Node(0);
    Node* n3 = new Node(2);
    Node* n4 = new Node(1);
    Node* n5 = new Node(0);
    Node* n6 = new Node(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    cout << "Before: ";
    printList(n1);

    sortList(n1);

    cout << "After: ";
    printList(n1);

    return 0;
}
