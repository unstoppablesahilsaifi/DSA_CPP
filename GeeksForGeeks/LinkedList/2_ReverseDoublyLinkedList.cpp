/*Reverse a Doubly Linked List
Difficulty: EasyAccuracy: 70.38%Submissions: 193K+Points: 2Average Time: 15m
You are given the head of a doubly linked list. You have to reverse the doubly linked list and return its head.

Examples:

Input:
   
Output: 5 <-> 4 <-> 3
Explanation: After reversing the given doubly linked list the new list will be 5 <-> 4 <-> 3.
   
Input: 
   
Output: 196 <-> 59 <-> 122 <-> 75
Explanation: After reversing the given doubly linked list the new list will be 196 <-> 59 <-> 122 <-> 75.
   
Constraints:
1 ≤ number of nodes ≤ 106
0 ≤ node->data ≤ 104*/


class Solution {
  public:
    Node *reverse(Node *head) {
        // Agar list empty hai ya sirf 1 node hai -> reverse ka koi faida nahi
        if (head == NULL || head->next == NULL) 
            return head;

        Node* temp = head;     // temp -> traversal ke liye pointer
        Node* prevNode = NULL; // prevNode -> har node ka previous store karega (useful baad me)

        // Step 1: Traverse the DLL and swap prev <-> next for each node
        while (temp != NULL) {
            // --- Swap Logic ---
            // pehle temp->prev ko store kar lete hain
            prevNode = temp->prev;

            // ab current node ka prev aur next swap karte hain
            temp->prev = temp->next;  // prev ban jayega old next
            temp->next = prevNode;    // next ban jayega old prev

            // ab temp ko aage badhaye
            // dhyaan: ab hum temp->prev me move karenge, kyunki swap ke baad
            // "prev" actually agla node hai.
            temp = temp->prev;
        }

        // Step 2: Jab loop khatam hoga,
        // prevNode last valid node ke upar hoga
        // aur uska prev naya head banega
        if (prevNode != NULL) {
            head = prevNode->prev;
        }

        return head; // naya reversed list ka head return karo
    }
};


Input DLL:
1 <-> 2 <-> 3

👉 Step 1: temp = 1

Swap prev and next → 1 ka next=NULL, prev=2

Move temp = temp->prev → temp ab 2 pe hai

👉 Step 2: temp = 2

Swap prev and next → 2 ka next=1, prev=3

Move temp = 3

👉 Step 3: temp = 3

Swap prev and next → 3 ka next=2, prev=NULL

Move temp = NULL → loop khatam

Final DLL:
3 <-> 2 <-> 1 ✅