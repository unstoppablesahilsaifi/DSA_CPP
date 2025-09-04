/*Linked List Group Reverse
Difficulty: HardAccuracy: 57.08%Submissions: 258K+Points: 8Average Time: 30m
You are given the head of a Singly linked list. You have to reverse every k node in the linked list and return the head of the modified list.
Note: If the number of nodes is not a multiple of k then the left-out nodes at the end, should be considered as a group and must be reversed.

Examples:

Input: k = 2,
   
Output: 2 -> 1 -> 4 -> 3 -> 6 -> 5
Explanation: Linked List is reversed in a group of size k = 2.
   
Input: k = 4,
   
Output: 4 -> 3 -> 2 -> 1 -> 6 -> 5
Explanation: Linked List is reversed in a group of size k = 4.
   
Constraints:
1 ≤ size of linked list ≤ 105
0 ≤ node->data ≤ 106
1 ≤ k ≤ size of linked list*/

/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* reverseKGroup(Node* head, int k) {
        if (head == NULL) return NULL; // agar list empty hai
        
        // Step 1: Pehle check kro ki is group me kitne nodes h
        Node* temp = head;
        int count = 0;
        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        // Step 2: Agar nodes >= k hain to reverse kro
        if (count == k) {
            Node* prev = NULL;
            Node* curr = head;
            Node* next = NULL;
            int c = 0;

            // Reverse exactly k nodes
            while (curr != NULL && c < k) {
                next = curr->next;   // next pointer save
                curr->next = prev;   // link reverse
                prev = curr;         // move prev ahead
                curr = next;         // move curr ahead
                c++;
            }

            // Step 3: ab 'head' ban gaya group ka tail
            // usko link kro baaki reversed list se
            head->next = reverseKGroup(curr, k);

            // 'prev' is new head of this group
            return prev;
        }
        else {
            // Step 4: Agar bache hue nodes < k
            // is problem me bhi reverse krna h (as per statement)
            Node* prev = NULL;
            Node* curr = head;
            Node* next = NULL;

            while (curr != NULL) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
    }
};
