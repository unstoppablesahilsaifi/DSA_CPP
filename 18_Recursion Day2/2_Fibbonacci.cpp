// Code to find the nth term of fibonacci series
// 0 1 1 2 3 5 8 13 21............

//LeetCode 509 Question

  int fib(int n) {
        //Base Case
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        //Recursive Call

        int ans=fib(n-1)+fib(n-2);
        return ans;
    }