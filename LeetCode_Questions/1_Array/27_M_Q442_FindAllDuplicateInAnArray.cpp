class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       int n = nums.size(); 
       sort(nums.begin(), nums.end());
       vector<int> ans;
       for(int i = 1; i <= n - 1 ; i++){
            if(nums[i] == nums[i-1]){
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
};

/*
Brute force nut gave TLE


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i=0;i<nums.size();i++){
            for (int j=0;j<nums.size();j++){
                if (i==j){
                    j++;
                    break;
                }
                if(nums[i]==nums[j]){
                    ans.push_back(nums[i]);
                }
            }
        }
        return ans;
    }
};
*/