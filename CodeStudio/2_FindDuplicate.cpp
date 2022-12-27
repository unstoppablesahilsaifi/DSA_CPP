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
#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
     int ans=0;
    for(int i=0;i<arr.size();i++){
        ans=ans^arr[i];
    }
     for(int i=1;i<arr.size();i++){
        ans=ans^i;
     }
    return ans;
}
