class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        //suppose missing number is 1
        int missingNumber=1;
        for(int number:nums){
            //If number equal to missing number yaani 1 h to, to may be missing number is 2
            if(number==missingNumber){
                missingNumber++;
            }
            else if(number>missingNumber){
                break;
            }
        }
      return missingNumber;
    }
};