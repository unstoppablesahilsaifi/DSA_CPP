//Code
 /*
 agar hm kisi bhi number ko %n krte  h to answer 0-(n-1) ki range m  hi aayga.
 like 43 % 10=3
 and array ka index 0 s suru hota h and n-1 per end hota h

 arr= 23 42 56 43 ye array h to hme ek rotate krne per 43 ki 1st place per lana hoga
 agar nth place ko n se mode krde to ans 0 mtlb 1st place per


 ab samjho shi s----
 k hamra 3 h maan lo to hmara rotate arrayb hoga 42 56 43 23 thik h??
 mode k hisab s, 43 hmara 2nd index per aayga 3 baar rotate  hone k baad ok? 43 ki index h (n-1) OK?
 yaani 3baar  shift krna pdega. chalo kroo n-1 ka +1 kro to n. 1 step aage hp  gya 2nd k liye n+1 and 3rd step k liye n+2 OK?
 lekin n+2 to array s bhar h hme to array k andar khelna h thik h?
 mtlb agar hm (n+2) ko mode krde n s to  value 2 aaygi mtb 2nd index ok na? areey bhai ye hi to krna tha 2nd index per hi to
 place krna tha.

 to ek formula banao arr[(i+k)%nums.size()]=arr[i];
 mtlb array ka index + k ki value ko mode n and usme array ki value daal do, yehi to hua h array ka index n-1 + ki value(3) and mode uska
 

 */


class Solution {
public:
    void rotate(vector<int>& nums,int k) {
     vector<int> temp(nums.size());
     for(int i=0;i<nums.size();i++){
         temp[(i+k)%nums.size()]=nums[i];
     }
     nums=temp;
    }
};