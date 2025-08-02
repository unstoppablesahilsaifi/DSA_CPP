
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

    // beech me insert karna hai, ek nai node banani hoti h jo insert krni h
    Node* nodeToInsert = new Node(d);

    // naye node ka next existing node pe point kare, nodeToInsert usko point krega jisko temp point kr rha hoga.
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

int main() {
    
    // ek naya node banaya jiska data 10 hai
    Node* node1 = new Node(10);
    
    // head aur tail dono usi node ko point kar rahe hain
    Node* head = node1; 
    Node* tail = node1;

       insertAtHead(head, 5);  // 👈 Yeh line ab insertAtHead() ko test karegi

    // tail pe insert kar rahe hain
    insertAtTail(tail, 12);
    insertAtTail(tail, 15);

    // 4th position pe 22 insert kar rahe hain
    insertAtPosition(tail,head, 4, 22);

    // head aur tail ke data check
    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;

    // manually loop create kiya (tail ka next ko kisi node pe point kar diya)
    tail -> next = head -> next;

    // ab loop detect ya remove ka code nahi hai, sirf print kar rahe hain
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


/*
Deletion Explanation

Bilkul! Chaliye **line-by-line** aur **logical flow ke sath** samajhte hain ki:

```cpp
if(position == 1) {
    Node* temp = head;
    head = head -> next;
    temp -> next = NULL;
    delete temp;
}
```

yeh 4 lines **linked list ke first node ko safely delete karne ke liye** kaise kaam karti hain.

---

## 🎯 Goal:

Hume **linked list ke first node** ko delete karna hai.

### 🔰 Maan lo yeh list hai:

```
head → [10] → [20] → [30] → NULL
```

### 📌 Ab hume `[10]` node delete karna hai — yani `position == 1`

---

## ✅ Line-by-Line Explanation:

---

### 🔹 `if(position == 1) {`

🔍 Yeh check karta hai ki kya user ne **pehla node** delete karne ke liye kaha hai?

> Agar haan, to head node ko hataana hoga — baki list ko preserve karte hue.

---

### 🔹 `Node* temp = head;`

💡 **Why?**

* `head` node ko delete karne se pehle uska pointer safe kar lete hain, taki usse delete kiya ja sake baad me.
* Yani humne `[10]` ko `temp` pointer me store kar liya:

```
temp → [10] → [20] → [30] → NULL
```

---

### 🔹 `head = head -> next;`

💡 **Why?**

* Ab head ko next node pe shift kar do, yani `head = [20]` ho gaya:

```
head → [20] → [30] → NULL
```

> Is line ke baad `[10]` node list se logically nikal gaya, lekin memory me abhi bhi exist karta hai (`temp` usse point kar raha hai).

---

### 🔹 `temp -> next = NULL;`

💡 **Why? (Good practice)**

* Hum **delete karne se pehle** uska `next` NULL kar dete hain:

  * Taaki **dangling pointer** ka risk na ho.
  * Agar kisi aur part of code me `~Node()` ya recursive destructor chale to vo accidently next nodes ko na delete kare.

> So ab `[10]` node ka `next = NULL` ho gaya

---

### 🔹 `delete temp;`

🧹 **Ab actual memory free kar rahe hain.**

* `delete` keyword us node ko RAM se hata deta hai.
* Agar destructor defined hai to vo bhi chalega (aur console me message bhi dikhega if `cout` hai destructor me).

---

## 🔁 Final Result:

List ban gayi:

```
head → [20] → [30] → NULL
```

Aur `[10]` node safely delete ho gaya without memory leak.

---

## 🧠 Summary:

| Step | Line                | Purpose                                 |
| ---- | ------------------- | --------------------------------------- |
| 1️⃣  | `temp = head`       | Old node ko temporarily store kara      |
| 2️⃣  | `head = head->next` | Head pointer ko next node pe shift kara |
| 3️⃣  | `temp->next = NULL` | Node isolate kiya safe deletion ke liye |
| 4️⃣  | `delete temp`       | Memory free kari (node delete)          |

---



















Great! Ab hum **middle ya last node delete** karne ka part line-by-line samjhenge from this code:

```cpp
else {
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;

    while(cnt < position) {
        prev = curr;
        curr = curr -> next;
        cnt++;
    }

    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
}
```

---

## 🎯 Goal:

Delete node at **any position other than 1**
(i.e., **middle** ya **last node**)

### 🔰 Maan lo list hai:

```
head → [10] → [20] → [30] → [40] → NULL
```

Agar hume 3rd node (i.e., `[30]`) delete karni ho, to `position = 3` diya jaayega.

---

## ✅ Line-by-Line Explanation:

---

### 🔹 `Node* curr = head;`

💡 Yeh current node ko start me head pe point kar raha hai:

```
curr → [10]
```

---

### 🔹 `Node* prev = NULL;`

💡 Previous node ke liye ek pointer banaya jo initially NULL hai. Iska kaam hai:
`curr` ke just pehle waale node ko track karna.

---

### 🔹 `int cnt = 1;`

💡 Yeh counter hai jo position tak pahuchne me madad karega (starting from node 1).

---

### 🔹 `while(cnt < position) { ... }`

🔁 Loop chalega jab tak hum **delete karne waale node** tak nahi pahuch jaate.

* Har iteration me:

  * `prev = curr;`
  * `curr = curr->next;`
  * `cnt++;`

---

### 💥 Loop ka kaam kya hai?

Let’s say `position = 3`, to:

| Iteration | cnt | `prev` points to | `curr` points to      |
| --------- | --- | ---------------- | --------------------- |
| 1         | 1   | NULL             | \[10]                 |
| 2         | 2   | \[10]            | \[20]                 |
| 3         | 3   | \[20]            | \[30]             ✅ ✅ |

Loop breaks here when `cnt == 3`

---

### 🔹 `prev -> next = curr -> next;`

💡 **Link to tod diya!**

* `[20] → [30]` ko break karke `[20] → [40]` kar diya:

```
[10] → [20] → [40] → NULL
```

> Ab `[30]` list se nikal chuka hai logically — lekin abhi bhi memory me hai.

---

### 🔹 `curr -> next = NULL;`

💡 Safe deletion ke liye `curr` ka `next` NULL kar diya —
taaki koi accidental deletion of next node na ho.

---

### 🔹 `delete curr;`

🧹 Finally `[30]` node memory se hata diya.

---

## 🧠 Summary Table:

| Step | Line                      | Purpose                                |
| ---- | ------------------------- | -------------------------------------- |
| 1️⃣  | `curr = head`             | Traverse ke liye current node set kara |
| 2️⃣  | `prev = NULL`             | Pehle node ko track karne ke liye      |
| 3️⃣  | `while(...)`              | Position tak pahuchne ke liye loop     |
| 4️⃣  | `prev->next = curr->next` | Node ko list se hata diya              |
| 5️⃣  | `curr->next = NULL`       | Safe deletion                          |
| 6️⃣  | `delete curr`             | Memory se delete kara                  |

---

## 🔚 Final Output:

```
[10] → [20] → [40] → NULL
```

Aur `[30]` safely delete ho gaya.



















Destucture explanation

Zarur! Aaiye **Linked List me last node delete karna** step-by-step samajhte hain, using the same code structure:

---

### ✅ Code snippet (jo pehle se likha hai):

```cpp
else {
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;

    while(cnt < position) {
        prev = curr;
        curr = curr -> next;
        cnt++;
    }

    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
}
```

---

## 📌 Maan lo Linked List hai:

```
head → [10] → [20] → [30] → [40] → NULL
```

Aur hume last node `[40]` delete karni hai
🔹 i.e., `position = 4`

---

## 🔄 Loop Execution:

| Iteration | `cnt` | `curr`  | `prev`  |
| --------- | ----- | ------- | ------- |
| 1         | 1     | \[10]   | NULL    |
| 2         | 2     | \[20]   | \[10]   |
| 3         | 3     | \[30]   | \[20]   |
| 4         | 4     | \[40] ✅ | \[30] ✅ |

---

## 🧠 What happens next?

### 🔹 `prev->next = curr->next;`

Ab `curr` hai `[40]`
Aur `curr->next = NULL`

To:

```cpp
prev->next = NULL;
```

🔁 Final list:

```
[10] → [20] → [30] → NULL
```

Node `[40]` ab list se remove ho gaya.

---

### 🔹 `curr->next = NULL;`

Safety ke liye — although already NULL hai, but achha habit hai.

---

### 🔹 `delete curr;`

Ab node `[40]` ki memory free ho jaayegi.

---

## 🔚 Final Result:

After deleting 4th node (last):

```
[10] → [20] → [30] → NULL
```

🧹 `[40]` memory se bhi hat gaya.

---

## ⚠️ Important Edge Case:

Agar list me sirf ek node ho (i.e., `head == tail`),
aur aap `position = 1` delete kar rahe ho —
to wo pehle wale if block me handle ho jaata hai:

```cpp
if(position == 1) {
    ...
}
```

But agar list me **multiple nodes hain** aur aap **last node delete** kar rahe ho, to upar waala `else` block use hota hai.

---

## ✅ Bonus Tip (Optional but Recommended):

Agar aap tail bhi track kar rahe ho, to **tail ko update** karna na bhoolo:

```cpp
if(curr == tail) {
    tail = prev;
}
```

*/