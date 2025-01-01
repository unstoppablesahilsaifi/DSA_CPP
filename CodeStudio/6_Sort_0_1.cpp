/******************** Self Approach************************/
#include <iostream>
using namespace std;
int sort(int arr[], int size)
{
    int i = 0;
    int j = size - 1;
    for (i; i < size; i++)
    {
        for (j; j < size; j--)
        {
            if (i >= j)
            {
                break;
            }
            
            if (arr[i] == 0)
            {
                i++;
            }
            else if(arr[j] == 1)
                j--;
            if (arr[i] == 1 && arr[j] == 0)
            {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        if (i >= j)
        {
            break;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,1};
    int size = 13;
    sort(arr, size);
    return 0;
}


/*
#include <iostream>
using namespace std;

void sortBinaryArray(int arr[], int n) {
    int left = 0; // Pointer to the start of the array
    int right = n - 1; // Pointer to the end of the array
    
    while (left < right) {
        if (arr[left] == 0) {
            left++; // Move left pointer to the right
        } else if (arr[right] == 1) {
            right--; // Move right pointer to the left
        } else {
            // Swap arr[left] and arr[right] if arr[left] is 1 and arr[right] is 0
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements (0 or 1):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sortBinaryArray(arr, n);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}


*/