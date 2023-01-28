// Convert Binnary into decimal
/*
Left shift krna mtlb digit m 2 ki multiply
ex-> no=2 h to left shit krne per bit 1 0 0 ho jaygi means 4 to hmne 2 s multiply hi kiya na

Right shift krne ka mtlb h divide krna
ex-> no=2 in binary 1 0 right shift krne per 1 ho jayga meand 2 s divide hi  hua na
*/

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
        int digit=n%10;
        if(digit==1){
            ans=ans+pow(2,i);
        }
        n=n/10;
        i++;
    }
    cout<<ans<<endl;
    return 0;
}

/*
#include <stdio.h>
#include <math.h>

// function prototype
int convert(long long);

int main() {
  long long n;
  printf("Enter a binary number: ");
  scanf("%lld", &n);
  printf("%lld in binary = %d in decimal", n, convert(n));
  return 0;
}

// function definition
int convert(long long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}
*/