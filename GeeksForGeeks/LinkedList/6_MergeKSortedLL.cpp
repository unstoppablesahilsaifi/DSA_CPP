/*Merge K sorted linked lists
Difficulty: MediumAccuracy: 57.01%Submissions: 115K+Points: 4Average Time: 60m
Given an array arr[] of n sorted linked lists of different sizes. Your task is to merge all these lists into a single sorted linked list and return the head of the merged list.

Examples:

Input:
   
Output: 1 -> 2 -> 3 -> 4 -> 7 -> 8 -> 9
Explanation: The arr[] has 3 sorted linked list of size 3, 3, 1.
1st list: 1 -> 3 -> 7
2nd list: 2 -> 4 -> 8
3rd list: 9
The merged list will be: 
    
Input:
   
Output: 1 -> 3 -> 4 -> 5 -> 6 -> 8
Explanation: The arr[] has 3 sorted linked list of size 2, 1, 3.
1st list: 1 -> 3
2nd list: 8
3rd list: 4 -> 5 -> 6
The merged list will be: 
    
Constraints
1 ≤ total no. of nodes ≤ 105
1 ≤ node->data ≤ 103
*/

/*
👉 Node structure:
Har linked list node ke paas ek data aur ek pointer hota hai jo next node ki taraf point karta hai.
*/
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
  
    /*
    ✅ Function: mergeTwoLists
    Do sorted linked lists ko merge karta hai (bilkul merge sort ka "merge step").
    Input: l1 aur l2 (sorted lists ke heads)
    Output: ek sorted linked list ka head
    */
    Node* mergeTwoLists(Node* l1, Node* l2) {
        if (!l1) return l2;  // agar pehli list empty hai
        if (!l2) return l1;  // agar dusri list empty hai
        
        // Dummy node (sirf ease ke liye, taaki head pointer ghumana na pade)
        Node* dummy = new Node(0);
        Node* tail = dummy; // tail hamesha last node ko track karega
        
        // Jab tak dono lists empty nahi hoti
        while (l1 && l2) {
            if (l1->data <= l2->data) {
                tail->next = l1;   // chhoti value ko result me jodo
                l1 = l1->next;     // l1 aage badh jao
            } else {
                tail->next = l2;   // dusri wali chhoti nikli
                l2 = l2->next;     // l2 aage badh jao
            }
            tail = tail->next; // tail ko aage le jao
        }
        
        // Agar ek list khatam ho gayi, dusre ke saare nodes chipka do
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;
        
        return dummy->next; // dummy ka next hi actual head hai
    }

    /*
    ✅ Function: mergeLists
    Ye function array of lists ko recursively divide karta hai aur phir merge kar ke return karta hai.
    
    Logic:
    - Agar left == right → sirf ek list bachi → wahi return karo
    - Nahi toh array ko do parts me divide karo:
        arr[left..mid] aur arr[mid+1..right]
    - Dono parts ko recursively merge karo
    - Aur finally dono merged parts ko mergeTwoLists() se merge karo
    */
    Node* mergeLists(vector<Node*>& arr, int left, int right) {
        if (left > right) return NULL;        // invalid range
        if (left == right) return arr[left];  // sirf ek list bachi
        
        int mid = left + (right - left) / 2;  // middle nikalo
        
        // Left half aur right half merge karke lao
        Node* l1 = mergeLists(arr, left, mid);
        Node* l2 = mergeLists(arr, mid + 1, right);
        
        // Dono halves ko merge karke return karo
        return mergeTwoLists(l1, l2);
    }
    
    /*
    ✅ Function: mergeKLists
    Ye public function hai jo user call karega.
    Input: vector<Node*> arr → jitni bhi linked lists ke head diye gaye hain
    Output: ek single sorted linked list ka head
    */
    Node* mergeKLists(vector<Node*>& arr) {
        if (arr.empty()) return NULL; // agar array empty hai
        return mergeLists(arr, 0, arr.size() - 1);
    }
};
