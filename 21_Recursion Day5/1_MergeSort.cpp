// #include<iostream>
// using namespace std;

// void merge(int *arr, int s, int e) {

//     int mid = (s+e)/2;

//     int len1 = mid - s + 1;
//     int len2 = e - mid;

//     int *first = new int[len1];
//     int *second = new int[len2];

//     //copy values
//     int mainArrayIndex = s;
//     for(int i=0; i<len1; i++) {
//         first[i] = arr[mainArrayIndex++];
//     }

//     mainArrayIndex = mid+1;
//     for(int i=0; i<len2; i++) {
//         second[i] = arr[mainArrayIndex++];
//     }

//     //merge 2 sorted arrays     
//     int index1 = 0;
//     int index2 = 0;
//     mainArrayIndex = s;

//     while(index1 < len1 && index2 < len2) {
//         if(first[index1] < second[index2]) {
//             arr[mainArrayIndex++] = first[index1++];
//         }
//         else{
//             arr[mainArrayIndex++] = second[index2++];
//         }
//     }   

//     while(index1 < len1) {
//         arr[mainArrayIndex++] = first[index1++];
//     }

//     while(index2 < len2 ) {
//         arr[mainArrayIndex++] = second[index2++];
//     }

//     delete []first;
//     delete []second;

// }

// void mergeSort(int *arr, int s, int e) {

//     //base case
//     if(s >= e) {
//         return;
//     }
    
//     int mid = (s+e)/2;

//     //left part sort karna h 
//     mergeSort(arr, s, mid);
    
//     //right part sort karna h 
//     mergeSort(arr, mid+1, e);

//     //merge
//     merge(arr, s, e);

// }

// int main() {

//     int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
//     int n = 15;

//     mergeSort(arr, 0, n-1);

//     for(int i=0;i<n;i++){
//         cout << arr[i] << " ";
//     } cout << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp; // temporary vector for merged result

    int i = left;     // starting index of left subarray
    int j = mid + 1;  // starting index of right subarray

    // Merge both subarrays into temp
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements from left subarray
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from right subarray
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy back from temp to original array
    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
