#include <iostream>
#include <stack>
using namespace std;

// 🔹 Helper function: recursively x ko stack ke bottom me daalna
void solve(stack<int>& s, int x) {
    //  Base case: agar stack empty hai, to wahi par x push karo
    if(s.empty()) {
        cout << "Base case reached: stack empty, pushing " << x << endl;
        s.push(x);
        return;
    }

    // 🔹 Step 1: Top element nikal lo
    int num = s.top();
    cout << "Popped: " << num << endl;
    s.pop();

    // 🔹 Step 2: Recursive call (ab chhote stack ke liye same kaam)
    cout << "Calling recursion for remaining stack..." << endl;
    solve(s, x);

    // 🔹 Step 3: Jaise hi recursion se return aaya, wapas top element ko push karo
    cout << "Pushing back: " << num << endl;
    s.push(num);
}

// 🔹 Public function
stack<int> pushAtBottom(stack<int>& myStack, int x) {
    cout << "\n--- Inserting " << x << " at bottom ---\n";
    solve(myStack, x);
    return myStack;
}

int main() {
    stack<int> st;
    int n, x;

    cout << "Enter number of elements in stack: ";
    cin >> n;

    cout << "Enter elements (top to bottom): ";
    for(int i=0; i<n; i++) {
        int val;
        cin >> val;
        st.push(val);
    }

    cout << "Enter element to insert at bottom: ";
    cin >> x;

    st = pushAtBottom(st, x);

    // 🔹 Print stack (top to bottom)
    cout << "\nStack after insertion (top to bottom): ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}


/*#include <iostream>
#include <stack>
using namespace std;

// Function to insert element at bottom without recursion
void insertAtBottom(stack<int>& st, int x) {
    stack<int> temp;

    // Step 1: Move all elements to temp
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    // Step 2: Push new element in original stack
    st.push(x);

    // Step 3: Move back elements from temp to original stack
    while (!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
}

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Original stack top: " << st.top() << endl;

    insertAtBottom(st, 5);

    cout << "Stack after inserting 5 at bottom:\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
*/