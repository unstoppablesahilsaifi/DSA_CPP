//1009. Complement of Base 10 Integer
/*
Firstly understand the approach

n=5 -> 101
ans hoga 2 kyuki compliment of 5 hua 010 or 010 ka mtlb 2, thik h bhut badhiya ab suno

int 32 bit ka hota  h to 5 mtlb hua 00000....000101
compliment ho gya bit ko reverse krdo(mtln ~n ya ~5 krdo) 111111.....111010, lekin ise agar int m convert krenge to bhut bdi digit aaygi
hmee to last k do digit chahhiye na
to mtlb not of n ~n m hmee kuch aisa krna pdega ki last ki required bit 10 ko rok le or baaki ho hta de

to bhai ek kaam kr skte h ki ek  aisa number bna le jisse pehle vala part 000000.... ho jaye and last part 111 ho jaye
like 00000..0000111 ab ye 3 hi 1 kyu liye kyuki bhai 5 ko jab bit m convert krte h to last one 3rd number per h na
to mtlb 00000..0000111 aisa mask bna le or ~n s AND & krde to
n=5 ->  000000..000101

~n ->   111111..111010
mask-> &111111..111111    (1 ka & kiya h)
ans ->  000000.0000010  -> 2

to abhi tak formula ye h ki ~n k sath & krado mask ko


ab sochna h mask kaise bnega

hmare jo n=5 h uski bit presentation h 00000...0000101 or jo last 1 aa rha h vo 3rd number per aa rha h
to mask bnega 0000...000111
to n ko right shift kro
1st right shift m 00000...010
2nd right shift m 00000...001
3rd right shift m 00000...000 jab tak n!=0 ho

mtlb 3 baar loop chala h to 3 baar 1 daalna pdega na to create mask
ab mask hme 0 se initialize kiya  hua tha
to bhai mask ko left shift  krke OR krdo 1 s
to 3 baar left shift krne per 0000..00111 aa gya       0 | 0 = 0 baaki sab 1 hoga
*/


// class Solution {
// public:
//     int bitwiseComplement(int n) {
//         int m=n;
//         int mask=0;
//         if(n==0){
//             return 1;
//         }
//       while(m!=0){
//           mask=(mask << 1) | 1;
//           m= m >> 1;
//       }
//       int ans= (~n) & mask;
//       return ans;
//     }
// };