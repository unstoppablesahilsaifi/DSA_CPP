class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;
        
        // Step 1: Check if there are at least k nodes left
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }
        
        // If less than k nodes remain, return head as it is
        if (count < k) {
            return head;
        }
        
        // Step 2: Reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        count = 0;
        
        while (curr != NULL && count < k) {
            //Ye curr ke next node ko save karta ha
            next = curr->next;
            //Ab hum current node ka pointer ulta kar dete hain,Pehle curr ka next ek aage ka node hota tha,
            //ab usko pichle node (prev) ki taraf point kara dete hain.
            curr->next = prev;
            //Ab jo node humne reverse kar diya (curr),usko hum prev bana dete hain.Taki agle step me naya curr uske sath jud sake.
            prev = curr;
            //Ab hum aage badhte hain.curr ko update karke usko uss node par le aate hain jo humne pehle next me store kiya tha.
            curr = next;
            count++;
        }
        
        // Step 3: Recursion for next part
        if (next != NULL) {
            head->next = reverseKGroup(next, k);
        }
        
        return prev; // New head of this segment
    }
};
