#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int>& arr, int n) {
    vector<int> ans(n);
    stack<int> st;

    // Right se left traverse karenge
    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];

        // Stack se sab bade elements hata do
        while (!st.empty() && st.top() >= curr) {
            st.pop();
        }

        // Agar stack empty hai → -1, warna top hi answer hai
        ans[i] = st.empty() ? -1 : st.top();

        // Current element ko stack me push karo
        st.push(curr);
    }

    return ans;
}

int main() {
    vector<int> arr = {2, 1, 4,3};
    int n = arr.size();

    vector<int> result = nextSmallerElement(arr, n);

    cout << "Next Smaller Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

/*Approach (Using Stack, O(N))

Ek stack use karenge jo right se left traverse me help karega.

Traverse array right se left:

Jab tak stack ka top current element se bada ya equal ho, stack se pop karo.

Agar stack empty ho → iska matlab koi smaller element nahi mila, answer -1.

Agar stack non-empty ho → stack ka top = next smaller element.

Current element ko stack me push karo.

Finally, ans array ko reverse karne ki zaroorat nahi hogi kyunki hum direct index pe bhar rahe honge.*/