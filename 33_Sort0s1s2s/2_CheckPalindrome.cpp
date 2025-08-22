/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    bool checkPalin(vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;
        while (l <= r) {
            if (arr[l] != arr[r]) {
                return false;  // mismatch mila, palindrome nahi hai
            }
            l++;
            r--;
        }
        return true; // pura check ho gaya, palindrome hai
    }

public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;

        // linked list ke elements vector me store karlo
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // check karo palindrome hai ya nahi
        return checkPalin(arr);
    }
};
