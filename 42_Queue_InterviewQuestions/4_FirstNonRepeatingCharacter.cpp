#include <bits/stdc++.h>
using namespace std;

char nonRepeatingChar(string s) {
    int freq[26] = {0};          // lowercase letters count
    queue<char> q;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        freq[c - 'a']++;
        q.push(c);

        // Jab tak queue ka front repeat ho chuka hai, remove karo
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }
    }

    // Agar queue empty hai to koi non-repeating nahi mila
    if (q.empty()) return '$';
    return q.front();
}

// Driver code
int main() {
    string s = "geeksforgeeks";
    cout << "First non-repeating character: " << nonRepeatingChar(s) << endl;

    s = "racecar";
    cout << "First non-repeating character: " << nonRepeatingChar(s) << endl;

    s = "aabbccc";
    cout << "First non-repeating character: " << nonRepeatingChar(s) << endl;

    return 0;
}
