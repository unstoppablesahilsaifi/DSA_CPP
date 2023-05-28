class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
        vector<int> prefix(n, 1); // initialize prefix array with 1
        vector<int> suffix(n, 1); // initialize suffix array with 1
        
        // Calculate prefix array
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        
        // Calculate suffix array
        for(int i = n-2; i >= 0; i--) {
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        
        // Build product array
        vector<int> product(n);
        for(int i = 0; i < n; i++) {
            product[i] = prefix[i] * suffix[i];
        }
        
        return product;
        
    }
};