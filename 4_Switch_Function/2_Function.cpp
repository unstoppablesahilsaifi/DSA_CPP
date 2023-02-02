// // Power Maker

// #include<iostream>
// using namespace std;

// int main()
// {
//     int a,b;
//     cin>>a>>b;
//     int ans=1;
//     for(int i=1;i<=b;i++){
//         ans=ans*a;
//     }
//     cout<<ans;
//     return 0;
// }

// a=2
// b=3
// OP= 8

//--------------------------------------------------------------------

// // Program to  count the  1's bit
// #include <iostream>
// #include <math.h>
// using namespace std;

// int bitConverter(int n){
//     int i = 0;
//     int ans = 0;
//     while(n!=0){
//         int bit = n&1;
//         ans =ans +bit*pow(10,i) ;
//         n = n>>1;
//         i = i+1;
//     }
//     return ans ;
// }

// int BitCounter(int n){
//     int num = bitConverter(n);
//     int ans = 0;
//     while(num!=0){
//         int digit = num%10;
//         if(digit==1){
//             ans = ans + digit;

//         }
//         num=num/10;
//     }
//     return ans;

//     return num;
// }

// int main(){
//     int a,b;
//     cout<<"Enter the Value of A and B"<<endl;
//     cin>>a;
//     cin>>b;
//     int answer = BitCounter(a) + BitCounter(b);
//     cout<<answer;
// }

// 2nd approach for count bit

// #include<iostream>
// using namespace std;

// int bitCounter(int n)
// {
//     int count=0;
//     while(n!=0){
//         if(n&1){
//             count++;
//         }
//         n=n>>1;
//     }
//     return count;
// }

// int main()
// {
//     int a=2;
//     int b=3;

//     cout<<"Output for bits  "<<bitCounter(a) + bitCounter(b);
//     return 0;
// }

//--------------------------------------------------------------------------------
// nth fibonacci number
// 0 1 1 2 3 5 8 13

#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    int b = 1;

    int n = 10;
    cout << a << " " << b << " ";
    for (int i = 0; i < n - 2; i++)
    {
        int c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    return 0;
}
