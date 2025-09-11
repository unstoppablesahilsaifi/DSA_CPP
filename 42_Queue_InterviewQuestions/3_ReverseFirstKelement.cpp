#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstK(queue<int> &q, int k) {
    if (q.empty() || k > q.size() || k <= 0) return;

    stack<int> s;

    // Step 1: first k elements ko stack me daal do
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: stack se queue me wapas daal do (reverse ho jaayenge)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: baaki elements ko front se rear me move kar do
    int t = q.size() - k;
    for (int i = 0; i < t; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q; // Queue declare

    // Elements insert karna
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3; // first k elements reverse karne hain
    reverseFirstK(q, k);

    // Queue print karna
    cout << "Queue after reversing first " << k << " elements: ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
