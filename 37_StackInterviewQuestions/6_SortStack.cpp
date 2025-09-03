#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int>& st) {
    stack<int> temp;

    // Step 1: Move all elements to temp
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    // Step 2: Insert back into original stack in sorted order
    while (!temp.empty()) {
        int curr = temp.top();
        temp.pop();

        // Jab tak original stack ka top curr se chhota hai, wapas temp me bhej do
        while (!st.empty() && st.top() > curr) {
            temp.push(st.top());
            st.pop();
        }

        // Correct position me curr ko daal do
        st.push(curr);
    }
}

int main() {
    stack<int> st;
    st.push(34);
    st.push(3);
    st.push(31);
    st.push(98);
    st.push(92);
    st.push(23);

    cout << "Original Stack (top to bottom):\n";
    stack<int> copy = st;
    while (!copy.empty()) {
        cout << copy.top() << " ";
        copy.pop();
    }
    cout << endl;

    sortStack(st);

    cout << "Sorted Stack (top to bottom):\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
