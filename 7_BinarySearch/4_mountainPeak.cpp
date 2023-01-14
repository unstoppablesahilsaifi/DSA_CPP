// Prod to find max element using Bog O(n)
#include <iostream>
using namespace std;
int maxFinder(int arr[], int n)
{
    int ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (ans < arr[i])
        {
            ans=arr[i];
        }
    }
    return ans;
}
int main()
{
    int arr[] = {1, 6, 9, 12, 16, 17, 14, 11, 0,500};
    int n = 10;
    cout << "Max Number" << maxFinder(arr, n);
    return 0;
}