
// ### 📦 1. **Array**

// * **Size**: Fixed at creation.
// * **Memory**: Contiguous block.
// * **Access (get/set)**: 🔥 Fast – O(1)
// * **Insert/Delete**: ❌ Slow – O(n) (shifting needed)
// * **Thread-Safe**: ❌ No
// * **Use Case**: When size is known and random access is frequent.

// ---

// ### 🔗 2. **LinkedList**

// * **Size**: Dynamic (grows/shrinks easily).
// * **Memory**: Non-contiguous (each node stores data + reference).
// * **Access (get/set)**: ❌ Slow – O(n)
// * **Insert/Delete**: ✅ Fast – O(1) (if pointer is known)
// * **Thread-Safe**: ❌ No
// * **Use Case**: Frequent insertion/deletion, not much random access.

// ---

// ### 📑 3. **Vector**

// * **Size**: Dynamic (like ArrayList but grows by 2x).
// * **Memory**: Contiguous block.
// * **Access (get/set)**: 🔥 Fast – O(1)
// * **Insert/Delete**: ❌ Slow – O(n)
// * **Thread-Safe**: ✅ Yes (synchronized methods)
// * **Use Case**: Legacy code or when thread-safety is needed.

// ---

// ### 🔍 Summary Table:

// | Feature       | Array     | LinkedList | Vector    |
// | ------------- | --------- | ---------- | --------- |
// | Size          | Fixed     | Dynamic    | Dynamic   |
// | Access Speed  | Fast O(1) | Slow O(n)  | Fast O(1) |
// | Insert/Delete | Slow O(n) | Fast O(1)  | Slow O(n) |
// | Thread-Safe   | No        | No         | Yes       |
// | Memory        | Efficient | More usage | Efficient |

// ---

// ### ✅ When to Use:

// * **Array**: Use for performance + fixed-size data (e.g., matrix, lookup table).
// * **LinkedList**: Use for frequent inserts/deletes (e.g., queues, undo operations).
// * **Vector**: Use if you need a thread-safe dynamic array, though it's outdated (prefer `Collections.synchronizedList(new ArrayList<>())` now).


// 
#include<iostream>
#include<map>
using namespace std;

// 👇 Node class – ek node ke structure ko define karta hai (data + pointer to next node)
class Node {

    public:
    int data;
    Node* next;

    // ✅ Constructor – jab bhi naya node banega, data assign hoga aur next NULL hoga
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    // ✅ Destructor – jab node delete hoga to memory free karega (including next nodes)
    ~Node() {
        int value = this -> data;

        // agar current node ke baad koi node bacha ho to usse bhi delete karo
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

// ✅ Insert at head – naye node ko list ke beginning me add karta hai
void insertAtHead(Node* &head, int d) {

    // naya node banao jisme data d hoga
    Node* temp = new Node(d);

    // naye node ka next current head ko point karega
    temp -> next = head;

    // head ko naye node pe update kar do
    head = temp;
}

// ✅ Insert at tail – naye node ko list ke end me add karta hai
void insertAtTail(Node* &tail, int d) {
    // naya node create karo
    Node* temp = new Node(d);

    // tail ka next naye node ko point karega
    tail -> next = temp;

    // tail ko naye node pe update kar do
    tail  = temp;
}

// ✅ Linked list print karne ka function
void print(Node* &head) {

    // agar list empty hai to message print karo
    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }

    // temporary pointer head se start karega
    Node* temp = head;

    // jab tak NULL nahi milta tab tak data print karte jao
    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

// ✅ Insert at any given position (1-based indexing)
void insertAtPosition(Node* &tail, Node* & head, int position, int d) {

    // agar position 1 hai to head pe insert karo
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    // position - 1 tak pahunch jao
    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    // agar insert last me karna hai
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    // beech me insert karna hai
    Node* nodeToInsert = new Node(d);

    // naye node ka next existing node pe point kare
    nodeToInsert -> next = temp -> next;

    // previous node ka next naye node pe point kare
    temp -> next = nodeToInsert;
}

// ✅ Delete node at given position (1-based indexing)
void deleteNode(int position, Node* & head) { 

    // agar first node delete karni ho
    if(position == 1) {
        Node* temp = head;

        // head ko next node pe update karo
        head = head -> next;

        // current node ka next NULL karo aur delete karo
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        // agar middle ya last node delete karni ho
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;

        // desired position tak pahunch jao
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        // previous node ka next current ke next pe point kare
        prev -> next = curr -> next;

        // current node ko isolate kar ke delete karo
        curr -> next  = NULL;
        delete curr;
    }
}

// ✅ Check if linked list is circular (last node first node ko point karta ho)
bool isCircularList(Node* head) {
    // agar list empty hai to circular maan lo
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;

    // jab tak list khatam na ho ya head pe na aa jaaye
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    // agar head pe aa gaye to circular hai
    if(temp == head ) {
        return true;
    }

    return false;
}

// ✅ Detect loop using map – visited nodes ko track karte hain
bool detectLoop(Node* head) {

    if(head == NULL)
        return false;

    map<Node*, bool> visited;
    Node* temp = head;

    while(temp !=NULL) {

        // agar node pehle visit ho chuka hai to loop hai
        if(visited[temp] == true) {
            cout << "Present on element " << temp->data << endl;
            return true;
        }

        // current node ko visited mark karo
        visited[temp] = true;
        temp = temp -> next;
    }

    return false;
}

// ✅ Floyd’s Algorithm – fast & slow pointer se loop detect karna
Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        // agar fast aur slow mil jaayein to loop hai
        if(slow == fast) {
            cout << "present at " << slow -> data << endl;
            return slow;
        }
    }

    return NULL;
}

// ✅ Loop ka starting node find karna
Node* getStartingNode(Node* head) {

    if(head == NULL) 
        return NULL;

    // intersection point find karo
    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    // slow aur intersection ko ek-ek step chalao
    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow; // yahi loop ka start hai
}

// ✅ Loop ko remove karna
void removeLoop(Node* head) {

    if( head == NULL)
        return;

    // loop ka starting node find karo
    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    // last node find karo jo loop me jaa raha ho
    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    // loop tod do
    temp -> next = NULL;
}

int main() {
    
    // ek naya node banaya jiska data 10 hai
    Node* node1 = new Node(10);
    
    // head aur tail dono usi node ko point kar rahe hain
    Node* head = node1; 
    Node* tail = node1;

    // tail pe insert kar rahe hain
    insertAtTail(tail, 12);
    insertAtTail(tail, 15);

    // 4th position pe 22 insert kar rahe hain
    insertAtPosition(tail,head, 4, 22);

    // head aur tail ke data check
    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;

    // manually loop create kiya (tail ka next ko kisi node pe point kar diya)
    tail -> next = head ->next;

    // loop detect kar rahe hain
    if(floydDetectLoop(head) != NULL) {
        cout << "Cycle is present " << endl;
    }
    else
    {
        cout << "no cycle" << endl;
    }

    // loop start hone wali node find karna
    Node* loop = getStartingNode(head);
    cout << "loop starts at " << loop -> data  << endl;

    // loop remove kar diya
    removeLoop(head);

    // ab list ko print kar diya
    print(head);

    /*
    // isCircularList() ka check
    if(isCircularList(head)) {
        cout << " Linked List is Circular in nature" << endl;
    }
    else{
        cout << "Linked List is not Circular " << endl;
    }
    */

    return 0;
}
