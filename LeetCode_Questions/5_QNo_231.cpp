// 231. Power of Two

// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         int ans=1;
//         int i;
//         for(i=0;i<=30;i++){
//             if(ans==n){
//                 return true;

//             }
//             if(ans<INT_MAX/2){
//                 ans=ans*2;
//             }
//         }
//         return false;
//     }
// };


/*
#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false; // Powers of two are positive integers
    }
    return (n & (n - 1)) == 0;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPowerOfTwo(num)) {
        cout << num << " is a power of two." << endl;
    } else {
        cout << num << " is not a power of two." << endl;
    }

    return 0;
}

*/