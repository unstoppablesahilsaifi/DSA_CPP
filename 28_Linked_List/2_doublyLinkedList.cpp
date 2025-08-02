#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // ✅ Constructor: ek naye node ko initialize karta hai
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // ✅ Destructor: jab node delete hota hai, to uske baad ke nodes ko bhi recursively delete karta hai
    ~Node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

// ✅ Doubly Linked List ko traverse (print) karne ka function
void print(Node* head) {
    Node* temp  = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}

// ✅ Linked List ki length calculate karta hai
int getLength(Node* head) {
    int len = 0;
    Node* temp  = head ;

    while(temp != NULL) {
        len++;
        temp  = temp -> next;
    }

    return len;
}

// ✅ Insert at head — list ke starting me node add karta hai
void insertAtHead(Node* &tail, Node* &head, int d) {
    // agar list empty hai
    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

// ✅ Insert at tail — list ke end me node add karta hai
void insertAtTail(Node* &tail,Node* &head, int d) {
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else {
        Node* temp = new Node(d);
        tail -> next  = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

// ✅ Insert at any given position in DLL
void insertAtPosition(Node* &tail, Node* &head, int position, int d) {
    
    // Position = 1 ka case → head pe insert karna hai
    if(position == 1) {
        insertAtHead(tail,head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    // Position tak pahuchne ke liye loop chalayenge
    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    // Last position pe insert karne ka case
    if(temp -> next == NULL) {
        insertAtTail(tail,head,d);
        return ;
    }

    // ✅ Beech me kahin insert karna hai
    Node* nodeToInsert = new Node(d);

    nodeToInsert ->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

// ✅ Delete a node from given position in DLL
void deleteNode(int position, Node* & head) { 

    // 1st position ka case → head delete karna hai
    if(position == 1) {
        Node* temp = head;

        // aage wale node ka prev NULL kar do
        temp -> next -> prev = NULL;

        // head ko aage badhao
        head = temp ->next;

        // current node ka next NULL kar do
        temp -> next = NULL;

        // memory free karo
        delete temp;
    }
    else {
        // Beech ya end se delete karna ho
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        // current node ka prev NULL karo (safe deletion)
        curr -> prev = NULL;

        // pichle node ka next aage ke node se jod do
        prev -> next = curr -> next;

        // aage ke node ka prev NULL karo (agar koi hai to)
        curr -> next = NULL;

        // delete the node
        delete curr;
    }
}

// ✅ Main function to test DLL operations
int main() {

    Node* head = NULL;
    Node* tail = NULL;

    print(head);

    insertAtHead(tail,head, 11);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtHead(tail,head, 13);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtHead(tail,head, 8);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtTail(tail,head, 25);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(tail, head, 2, 100);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(tail, head, 1, 101);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(tail, head, 7, 102);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    deleteNode(7, head);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    return 0;
}
