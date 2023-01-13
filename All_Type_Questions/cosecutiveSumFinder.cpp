/*
Input Format:
5
134
12
7
2
1324

OutPut Format:
2

Explanation->
Only 12 and 2 can be represented in a form n*(n+1)
-> 12= 3*4 or 3*(3+1)
-> 2=  1*2 or 1*(1+1)
*/

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {134, 12, 7, 2, 1324};
    int n = 5;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == j * (j + 1))
            {
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}