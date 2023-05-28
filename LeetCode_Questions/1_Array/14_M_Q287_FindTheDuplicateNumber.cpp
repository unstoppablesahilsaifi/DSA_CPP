class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size();i++)
        {
            if(nums[i]==nums[i+1])
            {
                return nums[i];
            }
        }
        return -1;
    }
};

//Second approach using XOR


class Solution {
public:
    // Using XOR 
int findDuplicate(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if ((nums[i] ^ nums[j]) == 0)
                return nums[i];
    return -1;
}
};
