// My Approach


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
//             n>>1;
//         }
//         return count;
//     }
// };