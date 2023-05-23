
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