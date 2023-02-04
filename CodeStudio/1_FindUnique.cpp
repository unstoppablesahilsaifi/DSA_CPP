
// array n=2m+1 h, means odd h kyuki 2 m kuch bhi multiply kro to even aayga and plus one krdo to odd ho jayga
// array odd isliye h kyuki har number ka duplicate h per jo unique find krna h use milakr to odd ho jayga na

#include <iostream>
using namespace std;

/*
 For self reference
5, 3, 1, 5, 1, 3, 4, 7, 4, 8, 8
a, b, c, d, e, f, g, h, i, j, k

*/

int uniqueFinder(int arr[], int n)
{
    int ans;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                j++;
            }

            /*
             Hmne ye j=0 s start and ye uper if ki condition kyu di??? 
             kyuki suppose array h 2 3 1 6 3 6 2 ab isme  index 0 vale 2 ko usi s compare to krenge nhi isliye, khud ko
             khud hi ki index s compare nhi krenge isliye j++ kiya ki bhai agar i or j same h to j ko badha dena.
             => ab iski jrurat hi kyu pdii, kyuki bhai suppose kro i h 3 mtlb 6 per, to bhai har i k liye j(har  baar 0 s) to suru s hi 
             compare krna pdega na, kya pta us i k compare m koi element usse pehle pdaa ho.
            */
            count = 1;
            if (arr[i] == arr[j])
            {
                count++;
                if (count == 2)
                {
                    break;
                }
            }
        }
        if (count == 1)
        {
            ans = arr[i];
            break;
        }
    }
    return ans;
}
int main()
{     // case 1:
    // int arr[] = {1, 3, 2, 3, 1};
    // int n=5;

    // case 2:
    // int arr[]={5};
    //  int n = 1;

    // Final case 3 :

    int arr[] = {5, 3, 1, 5, 1, 3, 4, 7, 4, 8, 8};
    int n = 11;
    // Calling business logic
    cout << "Unique Element is " << uniqueFinder(arr, n);

    return 0;
}

// geekforgeek Approach

// #include <iostream>
// using namespace std;

// // Function to return the only odd
// // occurring element
// int findOdd(int arr[], int n)
// {
//     int res = 0, i;
//     for (i = 0; i < n; i++)
//         res ^= arr[i];
//     return res;
// }

// // Driver Method
// int main(void)
// {
//     int arr[] = { 12, 12, 14, 90, 14, 14, 14 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << "The odd occurring element is  "<< findOdd(arr, n);
//     return 0;
// }


/*
Sample Input 1:
1
7
2 3 1 6 3 6 2

Sample Output 1:
1

-----------------------

Sample Input 2:
2
5
2 4 7 2 7
9
1 3 1 3 6 6 7 10 7


Sample Output 2:
4
10
*/