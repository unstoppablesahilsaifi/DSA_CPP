class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // 2 dost bna diye, fast dost 2 step aage jata h and slow step 1 step aage jata h
        //Iska mtlb agar fast vala n step aage jayga to slow vala n/2 hoga, mtlb agar fast end m phuch gya to slow middle hoga na
    
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL) {
            //fast ko ek step aage badha abhi
           fast=fast->next;
           // but hm check kr rhe h ki bhai fast ka next NULL to nhi h, kyuki agar NULL hua to uska next krne ka kya mtlb
           //isliye fast agar NULL nhi h to ek step or aage badha do tabhi 2 step complete honge na
           if(fast!=NULL){
            fast=fast->next;
           }
           slow=slow->next;
        }
        return slow; // middle node
    }
};
