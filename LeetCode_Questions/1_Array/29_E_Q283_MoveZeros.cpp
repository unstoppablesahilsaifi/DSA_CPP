class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      //using bubble sort
      int n=nums.size();
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<n-1-i;j++)
          {
              if(nums[j]==0)
              {
                  swap(nums[j],nums[j+1]);
              }
          }
      }  
    }
};