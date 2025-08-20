#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

class Solution {
public:
    // Step 1: Detect cycle using Floyd's Algorithm
    Node* detectCycle(Node* head) {
        if (head == NULL || head->next == NULL) return NULL;

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return slow; // intersection point
            }
        }
        return NULL; // no cycle
    }

    // Step 2: Find start of cycle
    Node* findStart(Node* head) {
        Node* intersect = detectCycle(head);
        if (intersect == NULL) return NULL; // no cycle

        Node* slow = head;
        while (slow != intersect) {
            slow = slow->next;
            intersect = intersect->next;
        }
        return slow; // start node of cycle
    }
};

int main() {
    // Create nodes
    Node* n1 = new Node(3);
    Node* n2 = new Node(2);
    Node* n3 = new Node(0);
    Node* n4 = new Node(-4);

    // Create linked list: 3 -> 2 -> 0 -> -4
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // Make it circular: tail (-4) connects to node 2
    n4->next = n2;

    Solution s;

    Node* intersection = s.detectCycle(n1);
    if (intersection != NULL) {
        cout << "Loop detected  at node with value: " << intersection->data << endl;
    } else {
        cout << "No loop " << endl;
    }

    Node* start = s.findStart(n1);
    if (start != NULL) {
        cout << "Start of loop is node with value: " << start->data << endl;
    } else {
        cout << "No loop, so no start node" << endl;
    }

    return 0;
}



/*
Bahut sahi bhai 👌 ab mai tumhe dono methods (`detectCycle` aur `findStart`) ka **step-by-step documentation/flow** deta hoon taaki easily samajh aa jaye.

---

## 📝 Documentation with Flow

### 🔹 `Node* detectCycle(Node* head)`

**Purpose** → Yeh function Floyd’s Cycle Detection Algorithm (Tortoise & Hare) use karke **loop detect karta hai** aur agar loop mila to **intersection point** return karta hai (jahaan slow aur fast pointer milte hain).

**Flow:**

1. **Base Case Check:**
   Agar list empty (`head == NULL`) ya single node (`head->next == NULL`) hai → `NULL` return (loop possible nahi).
2. **Initialize Pointers:**

   * `slow = head` (1 step move karega)
   * `fast = head` (2 steps move karega)
3. **Traverse:**
   Jab tak `fast != NULL && fast->next != NULL`:

   * `slow = slow->next` (ek kadam)
   * `fast = fast->next->next` (do kadam)
4. **Check Meeting:**

   * Agar `slow == fast` ho gaya → loop detect hua.
   * Us time ka node return karo (intersection point).
5. **No Loop:**
   Agar traversal khatam ho gaya aur dono kabhi nahi mile → return `NULL`.

---

### 🔹 `Node* findStart(Node* head)`

**Purpose** → Yeh function loop ka **starting node find karta hai** agar loop hai.

**Flow:**

1. **Detect Cycle First:**
   `intersect = detectCycle(head)` call karo.

   * Agar `intersect == NULL` → list me loop hi nahi, directly return `NULL`.
2. **Reset One Pointer:**

   * Ek pointer `slow = head` rakho.
   * Dusra pointer `intersect` par rakho (jo detectCycle se mila).
3. **Move Both Together:**
   Jab tak `slow != intersect`:

   * `slow = slow->next`
   * `intersect = intersect->next`
4. **Meeting Point:**

   * Jab dono pointers same node par mil jaayen, wahi **loop ka starting node** hai.
   * Return that node.

---

## 🔎 Example Dry Run (List: 3 → 2 → 0 → -4 → back to 2)

* **detectCycle:**

  * `slow` aur `fast` chalenge → woh `-4` par mil jaayenge (intersection point).
* **findStart:**

  * Ek pointer `head (3)` se aur ek pointer `intersection (-4)` se chalayenge.
  * Dono 1-1 step chalke node `2` par milenge → loop start found ✅.

---

### ✅ Output for Example

```
Loop detected  at node with value: -4
Start of loop is node with value: 2


*/