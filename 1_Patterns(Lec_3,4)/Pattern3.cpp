
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


// #include <iostream>
// using namespace std;

// int main()
// {
//     /*
//     for n=3;

//       A A A
//       B B B
//       C C C
//     */

//     int n;
//     cin >> n;
//     int i = 1;
//     while(i <= n)
//     {
//         int j = 1;
//         while (j <= n)
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



// #include <iostream>
// using namespace std;

// int main()
// {
//     /*
//     for n=3;

//       A B C
//       A B C
//       A B C
//     */

//     int n;
//     cin >> n;
//     int i = 1;
//     while(i <= n)
//     {
//         int j = 1;
//         while (j <= n)
//         {
//             char ch='A'+j-1;
//             cout <<ch<< " ";
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
//     for n=3;

//       A B C
//       D E F
//       G H I
//     */

//     int n;
//     cin >> n;
//     int i = 1;
//     char start='A';
//     while(i <= n)
//     {
//         int j = 1;
        
//         while (j <= n)
//         {
//             cout <<start<< " ";
//             start++;
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
//     for n=3;

//       A B C
//       B C D
//       C D E


//       formula- i+j-1;
//       Add A+1 both side for mapping 1 2 3 to A B C and so on............
//     */

//     int n;
//     cin >> n;
//     int i = 1;
//     char start='A';
//     while(i <= n)
//     {
//         int j = 1;
        
//         while (j <= n)
//         {
//             char ch='A'+i+j-2;
//             cout <<ch<< " ";
           
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
//     for n=3;

//       A
//       B B
//       C C C


//       formula- A+i-1;
//      mtlb i=A h  to  we can write like A+i-1
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



// #include <iostream>
// using namespace std;

// int main()
// {
//     /*
//     for n=3;

//       A
//       B C
//       D E F


//     */

//     int n;
//     cin >> n;
//     int i = 1;
//      char ch='A';
//     while(i <= n)
//     {
//         int j = 1;
        
//         while (j <= i)
//         {
           
//             cout <<ch<< " ";
//            ch++;
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
//     for n=3;

//       A
//       B C
//       C D E
//       D E F G


//     */

//     int n;
//     cin >> n;
//     int i = 1;
     
//     while(i <= n)
//     {
//         int j = 1;
        
//         while (j <= i)
//         {
//            char ch=('A'+i+j-2);
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
E
D E
C D E
B C D E
A B C D E


    */

    int n;
    cin >> n;
    int i = 1;
     
    while(i <= n)
    {
        int j = 1;
           char ch=('A'+n-i);
        while (j <= i)
        {
        
            cout <<ch<< " ";
          ch++;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}