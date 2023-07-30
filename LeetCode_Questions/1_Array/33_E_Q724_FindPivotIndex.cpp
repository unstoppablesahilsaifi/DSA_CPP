class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> sumright(n,0);
        vector<int> sumleft(n,0);
        int sL=0;
        int sR=0;
        for( int i=n-1;i>=0;i--){
            sL=sL+nums[i];
            sumleft[i]=sL;
        }
        
        for(int i=0;i<n;i++){
            sR=sR+nums[i];
            sumright[i]=sR;
        }
        for (int i = 0; i < n; i++) {
            if (sumleft[i] == sumright[i]) {
                return i;
            }
        }
        
        // If no pivot index found, return -1
        return -1;

    }
};