// // Prod to find max element using Bog O(n)
// #include <iostream>
// using namespace std;
// int maxFinder(int arr[], int n)
// {
//     int ans = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (ans < arr[i])
//         {
//             ans=arr[i];
//         }
//     }
//     return ans;
// }
// int main()
// {
//     int arr[] = {1, 6, 9, 12, 16, 17, 14, 11, 0,500};
//     int n = 10;
//     cout << "Max Number" << maxFinder(arr, n);
//     return 0;
// }

// ---------------------------------------------------------------

#include<iostream>
#include<array>
using namespace std;

int findPeak(int arr[], int n){
    int start = 0;
    int end = n-1;
    int mid = start +(end-start)/2;
    int ans;

    while(start<end){
        if(arr[mid]<arr[mid+1]){
            start = mid+1;
        }
        else if(arr[mid]>arr[mid+1]){
             end = mid-1;
        }
        else 
        end =  mid;
        
        ans = mid;
        mid = start +(end-start)/2;
        
    }
return ans;

}
int main()
{
    int arr[]={0,1,2,3,4,5,6,7,8,9,8,7,2,1};
    int n = 14;
    cout<<"index of peak is: "<<findPeak(arr, n);
    return 0;
}


-------------------------------------------------------------

//Leetcode solution

/*
Why while(s<e) ??
Jab s=e hoga to vo element peak element bhi ho skta h , to loop ruk jayga vha per

agar hm while (s<=e) krte to kya hota?

vo loop tab bhi chalta jab s=e k ho jata lekin agar hme s=e p hi element mil gya to extra iteration ki need nhi h na.


*/


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
    int end =arr.size()-1;
    int mid = start +(end-start)/2;
  

    while(start<end){
        if(arr[mid]<arr[mid+1]){
            start = mid+1;
        }
        else{
             end = mid;
        }
       
        mid = start +(end-start)/2;
        
    }
return start;

    }
};