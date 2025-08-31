#include <iostream>
#include <stack>
using namespace std;

// helper recursive function
void solve(stack<int>& s, int x) {
    // base case
    if(s.empty()) {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    solve(s, x);

    s.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) {
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

    // print stack (top to bottom)
    cout << "Stack after insertion (top to bottom): ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
