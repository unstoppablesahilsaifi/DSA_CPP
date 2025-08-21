//LeetCode 83. Remove Duplicates from Sorted List

// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         // empty list
//         if (head == NULL) {
//             return NULL;
//         }

//         // Non-Empty List
//         ListNode* curr = head;
//         while (curr != NULL && curr->next != NULL) {
//             if (curr->val == curr->next->val) {
//                 // duplicate mila → next ko skip karo
//                 ListNode* dup = curr->next; 
//                 curr->next = curr->next->next;
//                 delete dup; // memory free
//             } else {
//                 // unique node → aage badho
//                 curr = curr->next;
//             }
//         }
//         return head;
//     }
// };
