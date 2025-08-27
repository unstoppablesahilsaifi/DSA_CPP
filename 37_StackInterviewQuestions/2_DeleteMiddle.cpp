#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int>& inputStack, int N) {
    if (N == 0) return; // empty stack case

    int mid = N / 2;  // middle index (0-based from top)
    stack<int> temp;

    // Step 1: pop elements until we reach middle
    for (int i = 0; i < mid; i++) {
        temp.push(inputStack.top());
        inputStack.pop();
    }

    // Step 2: delete middle element
    inputStack.pop();

    // Step 3: restore elements back
    while (!temp.empty()) {
        inputStack.push(temp.top());
        temp.pop();
    }
}

// Utility function to print stack (top → bottom)
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;

    // Example stack
    for (int i = 1; i <= 5; i++) {
        st.push(i);  // stack: 1(bottom) 2 3 4 5(top)
    }

    cout << "Original Stack (top to bottom): ";
    printStack(st);

    // Delete middle
    deleteMiddle(st, 5);

    cout << "After deleting middle: ";
    printStack(st);

    return 0;
}
