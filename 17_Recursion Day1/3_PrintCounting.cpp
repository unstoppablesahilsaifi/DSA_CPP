//Code

// Online C++ compiler to run C++ program online
#include <iostream>
void printCounting(int n){
    if(n==0){
        return;
    }
    printCounting(n-1); // Added a semicolon here
    std::cout << n;    // Added a space before n
}

int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    int n = 6;
    printCounting(n);

    return 0;
}



