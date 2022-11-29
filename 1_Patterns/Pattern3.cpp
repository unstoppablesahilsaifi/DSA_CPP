
// #include <iostream>
// using namespace std;

// int main()
// {
//     /*
//     for n=4;

//       A
//       B B 
//       C C C
//       D D D D
//     */

//     int n;
//     cin >> n;
//     int i = 1;
//     while(i <= n)
//     {
//         int j = 1;
//         while (j <= i)
//         {
//             char ch='A'+i-1;
//             cout <<ch<< " ";
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }


#include <iostream>
using namespace std;

int main()
{
    /*
    for n=3;

      A A A
      B B B
      C C C
    */

    int n;
    cin >> n;
    int i = 1;
    while(i <= n)
    {
        int j = 1;
        while (j <= n)
        {
            char ch='A'+i-1;
            cout <<ch<< " ";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}