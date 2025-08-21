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

    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};

void removeDuplicate(Node* head) {
    // curr pointer ko head pe set karte hain
    Node* curr = head;

    // Outer loop → har node ke liye duplicates check karenge
    while (curr != NULL) {

        // prev hamesha temp ke ek step pehle rahega
        Node* prev = curr;

        // temp ko curr ke next pe set karte hain 
        // (kyunki curr node ko uske khud ke duplicate ke against check karna hai)
        Node* temp = curr->next;

        // Inner loop → curr ke against puri linked list traverse
        while (temp != NULL) {
            
            // Agar duplicate mila → yani curr->data == temp->data
            if (temp->data == curr->data) {
                // Duplicate node ko list se unlink karna hai
                prev->next = temp->next;

                // Delete karne ke liye ek temporary pointer bana lo
                Node* dup = temp;

                // temp ko aage badha do
                temp = temp->next;

                // Delete karne se pehle dup ka next NULL set karo (good practice)
                dup->next = NULL;

                // Memory free karo
                delete dup;
            } 
            else {
                // Agar duplicate nahi mila → prev aur temp ko ek step aage badha do
                prev = temp;
                temp = temp->next;
            }
        }

        // Jab ek node ke against sab duplicates hat gaye, curr ko aage move karo
        curr = curr->next;
    }
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
    Node* n1 = new Node(4);
    Node* n2 = new Node(2);
    Node* n3 = new Node(5);
    Node* n4 = new Node(4);
    Node* n5 = new Node(2);
    Node* n6 = new Node(2);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    cout << "Before: ";
    printList(n1);

    removeDuplicate(n1);

    cout << "After: ";
    printList(n1);

    return 0;
}
