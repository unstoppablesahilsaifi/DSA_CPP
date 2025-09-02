Given the head of a singly linked list and an integer k. 
Swap the kth node (1-based index) from the beginning and the kth node from the end of the linked list. 
Return the head of the final formed list and if it's not possible to swap the nodes return the original list.

Examples:

Input: k = 1,
  
Output: 5 -> 2 -> 3 -> 4 -> 1
Explanation: Here k = 1, hence after swapping the 1st node from the beginning and end the new list will be 5 -> 2 -> 3 -> 4 -> 1.
  
Input: k = 2,
  
Output: 5 -> 9 -> 8 -> 5 -> 10 -> 3
Explanation: Here k = 2, hence after swapping the 2nd node from the beginning and end the new list will be 5 -> 9 -> 8 -> 5 -> 10 -> 3.
  
Constraints:
1 ≤ list size ≤ 104
1 ≤ node->data ≤ 106
1 ≤ k ≤ 10


class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;

        // Step 1: Find length
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // Step 2: If k is invalid
        if (k > n) return head;

        // Step 3: If kth node from start == kth node from end
        if (2*k - 1 == n) return head;

        // Step 4: Find kth from start
        Node* x = head;
        for (int i = 1; i < k; i++)
            x = x->next;

        // Step 5: Find kth from end (n-k+1 th node)
        Node* y = head;
        for (int i = 1; i < n-k+1; i++)
            y = y->next;

        // Step 6: Swap data
        int tempData = x->data;
        x->data = y->data;
        y->data = tempData;

        return head;
    }
};
