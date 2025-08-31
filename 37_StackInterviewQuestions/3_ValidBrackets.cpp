#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int length = s.length();
        if (length == 0) 
            return true;

        stack<char> st;

        /*Jab bhi opening bracket (, [, { mile → push kar do.

Jab closing bracket mile → stack ke top element se match karo.

Agar match hua → pop() kar do.

Agar nahi hua → invalid.*/
        for (int i = 0; i < length; i++) {
            char ch = s[i];

            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } 
            else if (!st.empty() && ch == ')' && st.top() == '(') {
                st.pop();
            } 
            else if (!st.empty() && ch == ']' && st.top() == '[') {
                st.pop();
            } 
            else if (!st.empty() && ch == '}' && st.top() == '{') {
                st.pop();
            } 
            else {
                return false; // invalid case
            }
        }

        return st.empty(); // agar stack empty hai to valid
    }
};

int main() {
    Solution sol;
    string s;

    cout << "Enter a string with brackets: ";
    cin >> s;

    if (sol.isValid(s)) {
        cout << "Valid Parentheses " << endl;
    } else {
        cout << "Invalid Parentheses " << endl;
    }

    return 0;
}
