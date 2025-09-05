
/*Sort a linked list of 0s, 1s and 2s
Difficulty: MediumAccuracy: 60.75%Submissions: 267K+Points: 4Average Time: 30m
Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

Examples:

Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
   
Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between. The final list will be:
   
Input: head = 2 → 2 → 0 → 1
   
Output: 0 → 1 → 2 → 2
Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be:
   
Constraints:
1 ≤ no. of nodes ≤ 106
0 ≤ node->data ≤ 2*/


class Solution {
  public:
    Node* segregate(Node* head) {
        if (head == nullptr || head->next == nullptr) 
            return head;
        
        int count0 = 0, count1 = 0, count2 = 0;
        
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == 0) {
                count0++;
            } else if (temp->data == 1) {
                count1++;
            } else {
                count2++;
            }
            temp = temp->next;
        }
        
        temp = head;

        // Overwrite data
        while (count0 > 0) {
            temp->data = 0;
            temp = temp->next;
            count0--;
        }
        while (count1 > 0) {
            temp->data = 1;
            temp = temp->next;
            count1--;
        }
        while (count2 > 0) {
            temp->data = 2;
            temp = temp->next;
            count2--;
        }
        
        return head;
    }
};
