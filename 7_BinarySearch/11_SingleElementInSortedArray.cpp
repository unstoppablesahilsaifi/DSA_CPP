/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/

// for explanation-  https://youtu.be/4KyrMRl0Gwc

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        if(l==h) return nums[l];
        while(l<=h){
            int m=(l+h)/2;
            if(m==0){
                if(nums[m]!=nums[m+1])
             return nums[m];
                else l=m+1;
            }
            else if(m==n-1){
                if(nums[m-1]!=nums[m]) 
                return nums[m];
                else h=m-1;
            }
            else if(nums[m]!=nums[m-1]&&nums[m]!=nums[m+1])
            return nums[m];
            else{
                int f,s;
                if(nums[m]==nums[m+1])
                { 
            
                    f=m; 
                  s=m+1;
                }
                else{
                     f=m-1;
                     s=m;}
            
                if(f%2==0)
                 l=m+1;
                else h=m-1;
            }
        }
        return 0;
    }
};