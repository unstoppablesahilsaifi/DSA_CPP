// Agar kisi badi problem ka solution depend krta h kisi same type ki choti problem per to ham recursion use krte h 

// 2 ki power n= 2 * 2 ki power n-1

#include<iostream> 
using namespace std;

int power(int n) {

    //base case (jha per rukna hota h usee base case kehte h )
    if(n == 0)
        return 1;

    //recursive relation
    return 2 * power(n-1);    
}

int main() {

    int n;
    cin >> n;

    int ans = power(n);

    cout << ans << endl;

    return 0;
}