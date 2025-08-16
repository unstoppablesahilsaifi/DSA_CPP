class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;       // 1 step
            fast = fast->next->next; // 2 steps
        }
        return slow; // middle node
    }
};
