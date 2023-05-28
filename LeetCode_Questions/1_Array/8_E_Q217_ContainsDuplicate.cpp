class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
     int n = nums.size();
    sort(begin(nums), end(nums));
     bool result = false;
     for(int i = 1; i<n ; i++){
     if(nums[i] == nums[i-1]){
      result = true;
      }
     }
return result;
    }
};


// Second approach using XOR

class Solution {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        for(int i=0;i<nums.length-1;i++){
            if((nums[i]^nums[i+1])==0){
                return true;
            }
        }
      return false;  
    }
}