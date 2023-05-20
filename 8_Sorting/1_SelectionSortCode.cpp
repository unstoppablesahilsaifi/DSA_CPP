#include<iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;i<n;j++){
            if(arr[j]<arr[minIndex])
                minIndex=j;
           
        }
        swap(arr[i],arr[minIndex]);
    }
    
    
}

int main()
{
    int arr[10]={22,45,11,3,86};
    int n=5;
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}