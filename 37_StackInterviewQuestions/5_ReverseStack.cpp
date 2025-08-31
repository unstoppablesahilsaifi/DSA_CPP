#include <iostream>
#include <stack>
using namespace std;

// 🔹 Helper: element ko stack ke bottom me insert karna (recursively)
void insertAtBottom(stack<int> &s, int element) {
    // Base case: agar stack empty hai → wahi par element daal do
    if(s.empty()) {
        cout << "Base case reached in insertAtBottom: inserting " << element << endl;
        s.push(element);
        return;
    }

    // 🔹 Step 1: Top element nikal lo
    int num = s.top();
    s.pop();
    cout << "insertAtBottom: popped " << num << endl;

    // 🔹 Step 2: Recursive call for smaller stack
    insertAtBottom(s, element);

    // 🔹 Step 3: Wapas aate waqt element push karo
    cout << "insertAtBottom: pushing back " << num << endl;
    s.push(num);
}

// 🔹 Main function: Recursively reverse the stack
void reverseStack(stack<int> &st) {
    //  Base case
    if(st.empty()) {
        cout << "Base case reached in reverseStack: stack empty" << endl;
        return;
    }

    // 🔹 Step 1: Top element nikal lo
    int num = st.top();
    st.pop();
    cout << "reverseStack: popped " << num << endl;

    // 🔹 Step 2: Recursive call for smaller stack
    reverseStack(st);

    // 🔹 Step 3: Insert popped element at bottom
    cout << "reverseStack: inserting " << num << " at bottom" << endl;
    insertAtBottom(st, num);
}

// 🔹 Utility: Print stack (top to bottom)
void printStack(stack<int> st) {
    cout << "[Top] ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "[Bottom]\n";
}

int main() {
    stack<int> st;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements (top to bottom): ";
    for(int i=0; i<n; i++) {
        int val;
        cin >> val;
        st.push(val);
    }

    cout << "\nOriginal Stack: ";
    printStack(st);

    reverseStack(st);

    cout << "\nReversed Stack: ";
    printStack(st);

    return 0;
}
