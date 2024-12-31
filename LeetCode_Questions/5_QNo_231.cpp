// 231. Power of Two

//Perfect Code

/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false; // Non-positive numbers cannot be powers of two
        }

        int count = 0;

        // Count the number of set bits in `n`
        while (n != 0) {
            if (n & 1) { // Check the least significant bit
                count++;
            }
            n = n >> 1; // Shift the number right by 1
        }

        // Return true if exactly one bit is set, false otherwise
        return count == 1;
    }
};

*/


/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;

        // Handle non-positive numbers
        if (n <= 0) {
            return false;
        }

        // Count the number of set bits
        while (n != 0) {
            count += (n & 1); // Check the least significant bit
            n >>= 1;          // Shift the number right by 1
        }

        // If exactly one bit is set, it's a power of two
        return count == 1;
    }
};

*/


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