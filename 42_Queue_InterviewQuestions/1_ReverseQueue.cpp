// #include <iostream>
// #include <queue>
// #include <stack>
// using namespace std;

// /*
//     Function to reverse a queue using a stack
// */
// queue<int> reverseQueue(queue<int> q) {
//     stack<int> s;

//     // Step 1: Push all elements of the queue into the stack
//     // Stack reverses the order of elements automatically
//     while (!q.empty()) {
//         int element = q.front(); // get front element of queue
//         q.pop();                 // remove it from queue
//         s.push(element);         // push into stack
//     }

//     // Step 2: Pop all elements from stack and push back to queue
//     // This will reverse the original order of the queue
//     while (!s.empty()) {
//         int element = s.top(); // get top element of stack
//         s.pop();               // remove it from stack
//         q.push(element);       // push into queue
//     }

//     return q; // reversed queue
// }

// int main() {
//     // Step 0: Create a queue and push elements
//     queue<int> q;
//     q.push(1);
//     q.push(7);
//     q.push(4);
//     q.push(9);
//     q.push(15);

//     cout << "Original Queue: ";
//     queue<int> temp = q; // copy to print
//     while (!temp.empty()) {
//         cout << temp.front() << " ";
//         temp.pop();
//     }
//     cout << endl;

//     // Step 3: Reverse the queue
//     q = reverseQueue(q);

//     // Step 4: Print the reversed queue
//     cout << "Reversed Queue: ";
//     while (!q.empty()) {
//         cout << q.front() << " ";
//         q.pop();
//     }
//     cout << endl;

//     return 0;
// }




// Now Recursion s krte h 

#include <iostream>
#include <queue>
using namespace std;

/*
    Function to reverse a queue using recursion
*/
void reverseQueue(queue<int> &q) {
    // Base case: if queue is empty, return
    if (q.empty()) return;

    // Step 1: Remove front element
    int element = q.front();
    q.pop();

    // Step 2: Recursively reverse the remaining queue
    reverseQueue(q);

    // Step 3: Push the removed element at the back
    q.push(element);
}

int main() {
    // Step 0: Create a queue and push elements
    queue<int> q;
    q.push(1);
    q.push(7);
    q.push(4);
    q.push(9);
    q.push(15);

    // Print original queue
    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Step 1: Reverse queue using recursion
    reverseQueue(q);

    // Print reversed queue
    cout << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
