

/*
Problem-

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]

*/
/*
ye ek DNF algo hoti h low and mid index 0 per point krenge starting m and high krega end of the array.

Step – 1: arr[mid] == 0

swap(arr[lo], arr[mid])
lo = lo + 1 = 1
mid = mid + 1 = 1

 
Step – 2: arr[mid] == 1

mid = mid + 1 


Step – 3: arr[mid] == 2

swap(arr[mid], arr[hi])
hi = hi – 1 = 4

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
      int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};