/* 
Jab ham kisi number ko AND & krte h 1 k sath or agar anser 1 aa jaye to Odd number h else even number h.
Lets do this for 5
5 in binary- 1 0 1 or isme hm AND & 1 krte h to 1 0 1 aayga iska mtlb last bit 1 h to number odd hua
Lets do this for 4
4 in binary- 1 0 0 or isme hm AND & 1 krte  h to 1 0 0 aayga mtlb last digit 0 h to number even hua.
*/

// Ab second kaam ki baat
/*
agar kisi number ki bit nikalni h to use 1 ka AND & krdo agar last bit 0 aaye to 0 thi else 1 thi
*/

// Convert decimal to binary
// ans = (digit*10^i)+ ans

#include<iostream>
using namespace std;
#include<math.h>

int main()
{
    int n;
    cin>>n;
    int ans=0;
    int i=0;
    while(n!=0){
        int bit=n&1;
        ans=(bit * pow(10,i)) + ans;
        n=n >> 1;
        i++;
    }
    cout<<"Answer is= "<<ans<<endl;
    
}

/*
#include <iostream>
using namespace std;
 
// function to convert decimal to binary
void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
     
    // printing binary array in reverse order, Kyuki convert krte time revresed ho jata h jaise agar 25 ko krenge to convert krke 10011 aayga jabki shi h 11001
    // isliye reverse krna pdta h
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}
 
// Driver program to test above function
int main()
{
    int n = 17;
    decToBinary(n);
    return 0;
}
OP- 10001
// https://www.geeksforgeeks.org/program-decimal-binary-conversion/
*/