// 206. Reverse Linked List
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // ✅ Step 1: Initialize 3 pointers
        ListNode* prev = NULL;       // Peechla node (starting with NULL)
        ListNode* curr = head;       // Abhi wala node
        ListNode* forward = NULL;    // Aage wala node (to keep track)

        // ✅ Step 2: Loop jab tak curr NULL nahi hota
        while(curr != NULL) {

            // Save next node (aage badhne se pehle)
            forward = curr->next;

            // Link ulta karo – current ka next ab previous ko point kare
            curr->next = prev;

            // Move pointers one step ahead
            prev = curr;
            curr = forward;
        }

        // ✅ Step 3: Prev ab new head ban chuka hai
        return prev;
    }
};
