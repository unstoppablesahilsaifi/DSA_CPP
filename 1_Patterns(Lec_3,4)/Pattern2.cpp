// #include <iostream>
// using namespace std;
//..
// int main()
// {
//     /*
//       for n=3

//        1 2 3
//        4 5 6
//        7 8 9

//     */

//     int n;
//     cin >> n;
//     int i = 1;
//     int count = 1;
//     while (i <= n)
//     {
//         int j = 1;
//         while (j <= n)
//         {
//             cout << count<<" ";
//             count++;
//             j++;
//         }
//         cout << endl;
//         i++;
//     }

//     return 0;
// }

// #include<iostream>
// using namespace std;

// int main()
// {
//     /*
//     for n=4;

//       *
//       * *
//       * * *
//       * * * *
//     */

//    int n;
//    cin>>n;
//    int i=1;
//    while(i<=n){
//      int j=1;
//      while(j<=i)
//      {
//         cout<<"*"<<" ";
//         j++;
//      }
//      cout<<endl;
//      i++;
//    }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     /*
//     for n=4;

//       1
//       2 3
//       4 5 6
//       7 8 9 10
//     */

//     int n;
//     cin >> n;
//     int i = 1;
//     int count = 1;
//     while (i <= n)
//     {
//         int j = 1;
//         while (j <= i)
//         {
//             cout << count << " ";
//             count++;
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;

// int main()
// {
//     /*
//     for n=4;

//       1
//       1 2
//       1 2 3
//       1 2 3 4
//     */

//     int n;
//     cin >> n;
//     int i = 1;

//     while (i <= n)
//     {
//         int j = 1;
//         while (j <= i)
//         {
//             cout <<j<< " ";
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     /*
//     for n=4;

//       1
//       2 2
//       3 3 3
//       4 4 4 4
//     */

//     int n;
//     cin >> n;
//     int i = 1;

//     while (i <= n)
//     {
//         int j = 1;
//         while (j <= i)
//         {
//             cout <<i<< " ";
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int main()
// {
//     /*
//     for n=4;

//       1
//       2 3
//       3 4 5
//       4 5 6 7
//     */

//     int n;
//     cin >> n;
//     int i = 1;
//     int count;
//     while (i <= n)
//     {
//         int j = 1;
//         count=i;
//         while (j <= i)
//         {
//             cout <<count<< " ";
//             count++;
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// Approach 2 for the above pattern(working on it[still did not find])


// #include <iostream>
// using namespace std;

// int main()
// {
//     /*
//     for n=4;

//       1
//       2 3
//       3 4 5
//       4 5 6 7
//     */

//     int n;
//     cin >> n;
//     int i = 1;
//     while(i <= n)
//     {
//         int j = 1;
//         while (j <= i)
//         {
//              j=i;
//             cout <<j<< " ";
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
    for n=4;

      1
      2 1
      3 2 1
      4 3 2 1
    */

    int n;
    cin >> n;
    int i = 1;
    while(i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            cout<<(i-j+1);
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
