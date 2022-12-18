// My Approach for the normal program to find the no of bits of any number


// class Solution{
//     public:
//     // n: input to count the number of set bits
//     //Function to return sum of count of set bits in the integers from 1 to n.
//     int countSetBits(int n)
//     {
//         // Your logic here
//         int count=0;
//         while(n!=0){
//             if(n&1){
//                 count++;
//             }
//             n=n>>1;
//         }
//         return count;
//     }
// };


/*
You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).
Input: N = 4
Output: 5
Explanation:
For numbers from 1 to 4.
For 1: 0 0 1 = 1 set bits
For 2: 0 1 0 = 1 set bits
For 3: 0 1 1 = 2 set bits
For 4: 1 0 0 = 1 set bits
Therefore, the total set bits is 5.
*/


#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter n";
    cin>>n;
        // Your logic here
        int count=0;
        for(int i=1;i<=n;i++)
        {
            int x = i;
        while(x!=0)
        {
        if(x&1)
        {
         count++;
        }
        x=x>>1;
        }
        }
        cout<<count;
}