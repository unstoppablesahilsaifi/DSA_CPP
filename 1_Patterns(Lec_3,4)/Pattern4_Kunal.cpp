//  #include<iostream>
//  using namespace std;
 
//  int main()
//  {
//     /* *
//        * *
//        * * *
//        * * * *
//     */ 
//     int n;
//     cin>>n;
//     int i=1;
//     while(i<=n)
//     {
//         int j=1;
//         while(j<=i){
//             cout<<"*"<<" ";
//             j++;
//         }
//         cout<<endl;
//         i++;
//     }

//  }


//  #include<iostream>
//  using namespace std;
 
//  int main()
//  {
//     /* 
//        * * * *
//        * * *
//        * * 
//        * 
//     */ 
//     int n;
//     cin>>n;
//     int i=1;
//     while(i<=n)
//     {
//         int j=1;
//         while(j<=n+1-i){
//             cout<<"*"<<" ";
//             j++;
//         }
//         cout<<endl;
//         i++;
//     }

//  }



//  #include<iostream>
//  using namespace std;
 
//  int main()
//  {
//     /* 
//        1 
//        1 2
//        1 2 3
//        1 2 3 4
//        1 2 3 4 5 
//     */ 
//     int n;
//     cin>>n;
//     int i=1;
//     while(i<=n)
//     {
//         int j=1;
//         while(j<=i){
//             cout<<j<<" ";
//             j++;
//         }
//         cout<<endl;
//         i++;
//     }

//  }

// 31 :16

 #include<iostream>
 using namespace std;
 
 int main()
 {
    /* 
       1 
       1 2
       1 2 3
       1 2 3 4
       1 2 3 4 5 
    */ 
    int n;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        int j=1;
        while(j<=i){
            cout<<j<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

 }
 