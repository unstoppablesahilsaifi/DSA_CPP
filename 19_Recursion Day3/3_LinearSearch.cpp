#include<iostream>
using namespace std;

void print(int arr[], int n) {
    cout << "Size of array is " << n << endl;

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

}

bool linearSearch(int arr[], int size, int k ) {
    print(arr,size);
    //base case
    if(size == 0) 
        return false;


    // agar aaray ka 1st element key h to true krdo nhi to baaki(else part) array m check kro na bhai fir
    if(arr[0] == k) {
        return true;
    }
    else {
        // ab yhaa per arr+1 krdiya h iska mtlb dusra index as 1st element check hoga if condition m
        bool remainingPart = linearSearch(arr+1, size-1, k );
        return remainingPart;
    }
}

int main() {

    int arr[5] = {3,5,1,2,6};
    int size = 5;
    int key = 6;
    bool ans = linearSearch(arr, size, key);

    if(ans ){
        cout << "Present " << endl;
    }
    else{
        cout << "absent " << endl;
    }

    return 0;
}