class Solution {
public:
    int countPrimes(int n) {
        vector<bool>prime(n+1, true);
        int count=0;
        prime[0] = prime[1] = false;
        for(int i=2;i<n;i++){
            if(prime[i]){
                count++;
                for(int j=i*2; j<n ;j+=i){
                    prime[j] = 0;
                }
            }
        }
        return  count;
    }
};
