//Code
 /*
 agar hm kisi bhi number ko %n krte  h to answer 0-(n-1) ki range m  hi aayga.
 like 43 % 10=3
 and array ka index 0 s suru hota h and n-1 per end hota h

 arr= 23 43 56 43 ye array h to hme ek rotate krne per 43 ki 1st place per lana hoga
 agar nth place ko n se mode krde to ans 0 mtlb 1st place per
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