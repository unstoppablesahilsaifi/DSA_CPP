// Below one for merge two sorted array where we can take third array.

#include<iostream>
#include<vector>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, int arr3[]) {

    int i = 0, j = 0;
    int k = 0;
    while( i<n && j<m) {
        if(arr1[i] < arr2[j]){
            arr3[k++] = arr1[i++];
        }

        // or

        //   if(arr1[i] < arr2[j]){
        //     arr3[k] = arr1[i];
        //      k++;
        //      i++;
        // }
        else{
            arr3[k++] = arr2[j++];
        }
    }

    //copy first array k element ko
    while(i<n) {
        arr3[k++] = arr1[i++];
    }

    //copy kardo second array k remaining element ko
    while(j<m) {
        arr2[k++] = arr2[j++];
    }
}

void print(int ans[], int n) {
    for(int i=0; i<n; i++) {
        cout<< ans[i] <<" ";
    }
    cout << endl;
}

int main() {

    int arr1[5] = {1,3,5,7,9};
    int arr2[3] = {2,4,6};

    int arr3[8] = {0};

    merge(arr1, 5, arr2, 3, arr3);

    print(arr3, 8);


    return 0;
}

//-------------------------------



//Best one approache


/*
class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--; k--;
            }
            else{
                nums1[k] = nums2[j];
                j--; k--;
            }
        }
        while(j>=0){
            nums1[k] = nums2[j];
            j--; k--;
        }
        
    }
};
*/

// Belwo is, when we don't take third array.

class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // removing zeroes
        for(int i = 0; i<nums2.size() ; i++){
            nums1.pop_back();
        }
        
        
        for(int i = 0; i<nums2.size() ; i++){
            nums1.push_back(nums2[i]);
        }
        
        sort(nums1.begin() , nums1.end());


        
    }
};