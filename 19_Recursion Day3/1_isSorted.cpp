//Sorted Array

// To check array is sorted or not using for loop
/*
#include <iostream>

bool isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false; // Array is not sorted
        }
    }
    return true; // Array is sorted
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 4, 3, 2, 1};

    if (isSorted(arr1, sizeof(arr1) / sizeof(arr1[0]))) {
        std::cout << "arr1 is sorted." << std::endl;
    } else {
        std::cout << "arr1 is not sorted." << std::endl;
    }

    if (isSorted(arr2, sizeof(arr2) / sizeof(arr2[0]))) {
        std::cout << "arr2 is sorted." << std::endl;
    } else {
        std::cout << "arr2 is not sorted." << std::endl;
    }

    return 0;
}

*/
// --------------------------------------------------------------

// Love Babbar Approach


#include<iostream>
using namespace std;

bool isSorted(int arr[], int size) {

    //base case
    if(size == 0 || size == 1 ){
        return true;
    }

    if(arr[0] > arr[1])
        return false;
    else {

        // arr+1 isliye kiya kyuki har baar 1 iteration to check ho jaygi na to curser ek aage jayga.
        // kyuki 1 baar uper check hua ki kahi 1st 2nd s bada to nhi h, to iteration to check ho na.


        
        // size-1 isliye kiya kyuki har baar 1 iteration check hone k baad size 1 to kam ho gya.
        bool remainingPart = isSorted(arr + 1, size - 1 );
        return remainingPart;
    }

}

int main() {

    int arr[5] = {2,4,9,9,9};
    int size = 5;

    bool ans = isSorted(arr, size);

    if(ans){
        cout << "Array is sorted " << endl;
    }
    else {
        cout << "Array is not sorted " << endl;
    }

    return 0;
}
