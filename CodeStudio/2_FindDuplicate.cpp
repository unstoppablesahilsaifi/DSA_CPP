// // Brute Force which is not working
// #include <iostream>
// using namespace std;
// int findDuplicate(int arr[], int n)
// {
//     int count = 0, i;
//     for (i = 1; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i == arr[j])
//             {
//                 count++;
//             }
//             if (count == 2)
//             {
//                 break;
//             }
//         }
//         if (count == 2)
//         {
//             break;
//         }
//     }
//     return i;
// }
// int main()
// {
//     int arr[5] = {1, 3, 4, 2, 2};
//     int n = 5;
//     cout << "Duplicate number is  :" << findDuplicate(arr, n);
//     return 0;
// }


///// Optimize Approach/////

/*
N size ka array h number contains 1 to N-1.
suppose array h 5,1,2,3,4,2 ab OP hoga 2 kyuki 2 hi duplicate h 
1st loop m saare array element k liye jisme 2 s 2 cancel ho jayga and 5,1,3,4 bchega.
2nd loop 1 ki counting s chelega N-1 tak mtlb, 1,2,3,4,5 kyuki array size N-6 h mtlb 5 baar chlega
jisme sab cancel ho jaynge and 2 bchega

*/


// #include <bits/stdc++.h> 
// #include <bits/stdc++.h> 
// int findDuplicate(vector<int> &arr, int n){
// 	// Write your code here.
//      int ans=0;
//      ye loop chlega index k according
//     for(int i=0;i<arr.size();i++){
//         ans=ans^arr[i];
//     }
//     ye loop chlega number k according mtlb values k acc
//      for(int i=1;i<arr.size();i++){
//         ans=ans^i;
//      }
//     return ans;
// }


/*

The XOR operation outputs:
- `1` if the bits are different.
- `0` if the bits are the same.


### **Truth Table for XOR**
For two bits, \( A \) and \( B \), the XOR operation \( A \oplus B \) works as follows:

| \( A \) | \( B \) | \( A \oplus B \) |
|--------|--------|-----------------|
| 0      | 0      | 0               |
| 0      | 1      | 1               |
| 1      | 0      | 1               |
| 1      | 1      | 0               |

---

*/