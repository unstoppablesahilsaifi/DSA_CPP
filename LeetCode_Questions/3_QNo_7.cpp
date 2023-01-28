//7. Reverse Integer

// class Solution {
// public:
//     int reverse(int x) {
//        int ans=0;
//         while(x!=0){
//             int digit=x%10;
//             if((ans>INT_MAX/10) ||(ans<INT_MIN/10)){
//                 return 0;
//             }
//             ans= (ans*10)+digit;
//             x=x/10;
//         }
//         return ans;
//     }
// };

/*
Important approach for if condition

suppose kro ki ans m kuch aise aa jaye jo ki range ki verge per ho ans ans*10 krne per to vo range s bhaar chala jayga.
Ab isko bachane k liye if consition lagai h isko samjhte h 

if(ans>INT_MAX/10)
ans*10 > (INT_MAX/10) * 10
ans*10 > INT_MAX

===>>> ab baat ye h ki hmne ans > INT_MAX kyu nhi ki, kyuki ek condition per ans*10 hota mtlb INT_MAX*10 krna pdta  usko cover krne 
       k liye by 10 kiya jisse into  10 cancel ho jaye,
       rhi baat 3rd condition ki vo hmne isliye nhi ki ans*10 m hm fir fas jaate
*/