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
                { f=m; 
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