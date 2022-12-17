// Linear Search Program in C++
#include <iostream>
using namespace std;
int check(int arr[], int n)
{    
    int v;
    cout << "no is to  be checked";
    cin >> v;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==v)
        {
            return 1;
        }
      
    }
      
            return 0;
}
int main()
{

    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"No is"<< check(arr,n);
    return 0;
}