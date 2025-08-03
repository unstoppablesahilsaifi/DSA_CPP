#include<iostream>
#include<map>
using namespace std;

// ✅ Node class representing each element in the circular linked list
class Node {
public:
    int data;
    Node* next;

    // ✅ Constructor: Initialize data and set next to NULL
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    // ✅ Destructor: Saari next nodes ko delete karega (recursive delete)
    ~Node() {
        int value = this->data;

        // Agar next node hai, to usse bhi delete karo
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }

        cout << "memory is free for node with data " << value << endl;
    }
};

// ✅ Function to insert a node after a given element in a circular list
void insertNode(Node* &tail, int element, int d) {

    // 🟡 Case 1: Agar list empty hai
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;

        // Self loop banate hain (1 node circular list)
        newNode->next = newNode;
    }
    else {
        // 🟢 Case 2: List non-empty hai, element find karna hoga
        Node* curr = tail;

        // Jab tak element nahi milta, loop chalao
        while(curr->data != element) {
            curr = curr->next;
        }

        // Element mil gaya, insert new node after it
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

// ✅ Function to print all nodes of circular list
void print(Node* tail) {

    // 🛑 Edge case: list empty hai
    if(tail == NULL) {
        cout << "List is Empty" << endl;
        return;
    }

    Node* temp = tail;

    // 🟢 Do-while loop kyunki circular list hamesha loop karegi
    do {
        cout << tail->data << " ";
        tail = tail->next;
    } while(tail != temp);

    cout << endl;
}

// ✅ Function to delete a node with given value from the list
void deleteNode(Node* &tail, int value) {

    // 🛑 Edge case: empty list
    if(tail == NULL) {
        cout << "List is empty, please check again" << endl;
        return;
    }
    else {
        // 🟢 Assume value list me present hai
        Node* prev = tail;
        Node* curr = prev->next;

        // Jab tak value nahi milta, loop chalao
        while(curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        // ✅ Link ko update karo (bypass node)
        prev->next = curr->next;

        // 🔴 Single node list case
        if(curr == prev) {
            tail = NULL;
        }
        // 🟡 Tail delete ho rahi hai
        else if(tail == curr) {
            tail = prev;
        }

        // ✅ Delete node safely
        curr->next = NULL;
        delete curr;
    }
}

// ✅ Check if list is circular (i.e., kabhi na khatam ho)
bool isCircularList(Node* head) {
    // 🛑 Empty list is circular by design
    if(head == NULL) {
        return true;
    }

    Node* temp = head->next;

    // Jab tak NULL nahi milta ya head wapas nahi aata, aage badho
    while(temp != NULL && temp != head) {
        temp = temp->next;
    }

    // Agar head wapas aaya => circular
    if(temp == head) {
        return true;
    }

    return false;
}

// ✅ Detect loop using hashmap (ye normal singly list ke liye zyada useful hai)
bool detectLoop(Node* head) {
    if(head == NULL)
        return false;

    map<Node*, bool> visited;
    Node* temp = head;

    while(temp != NULL) {
        // Node pehle se visit hua => loop detected
        if(visited[temp] == true) {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    // Loop nahi mila
    return false;
}

// ✅ Main function
int main() {
    Node* tail = NULL;

    // Sample insert calls:
    /*
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    deleteNode(tail, 5);
    print(tail);
    */

    // ✅ Circularity check
    if(isCircularList(tail)) {
        cout << "Linked List is Circular in nature" << endl;
    }
    else {
        cout << "Linked List is not Circular" << endl;
