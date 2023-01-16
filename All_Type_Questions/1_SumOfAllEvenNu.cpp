#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    int sum=0;
    for (int i = 1; i <=n; i++)
    {
        if(i%2==0){
            sum=sum+i;
        }
    }
    cout<<sum;
    return 0;
}

/*
Input- 10
Output- 30 because (2+4+6+8+10= 30)
*/