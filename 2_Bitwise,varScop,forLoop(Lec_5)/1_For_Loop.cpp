/*
Pre/post Incre/Decre code

#include<iostream>
using namespace std;

int main()
{
    int i=7;
    cout<<(++i)<<endl; //Pre incre
    cout<<(i++)<<endl; //Post Incre
    cout<<(i--)<<endl; // Post Decre
    cout<<(--i)<<endl; // Pre decre

    return 0;
}

O/P-
8
8
9
7

*/


// output finding

/*
#include<iostream>
using namespace std;

int main()
{
    //Find output 
    int a, b=1;
    a=10;
    if (++a) // agar ye if condition 0 hai means false sirf tb ye else pr jayega, If condition agar exist krti h to, mtlb a hmare paas h
    cout<<b; // does not matter ki incre ho rha h ya decre per exist to krta h na  that's why if m jayga. 
    else
    cout<< ++b;
    return 0;
}

OP= 1
*/

/*
#include<iostream>
using namespace std;

int main()
{
    int a=1;
    int b=2;
    if(a-- > 0 || ++b > 2){
        cout<<"Stage 1 Inside if";
    }
    else{
        cout<<"stage 2 inside else";
    }
    return 0;
}

OP= stage 1 inside if
Note- (2nd Condition does not execute as 1st one is true in OR case) kyuki OR condition m koi bhi ek true honi chahiye jab hme 1st
      hi true mil gai to 2nd per jane ka mtlb ni bnta na isliye 2nd execute nhi hogi

*/

  ///////////////////////Print 1 to 5

  
/*
#include<iostream>
using namespace std;

int main()
{
    //Approach 1
    // int n = 5;
    // for(int i = 1; i<=n;i++)
    // {
    //     cout<<i<<endl;
    // }
    /////////////////or
    //Approach 2
    int n = 5;
    int i = 1;
    for(;;){
        if(i<=n){
        cout<<i<<endl;
        }
        else
        break;
        i++;
    }
    return 0;
}
*/




/////Fibonacci series 10 iteration
/*
#include<iostream>
using namespace std;

int main()
{
    int n = 10;
    int a = 0;
    int b = 1;
    cout<<a<<" "<<b<<" ";
    for(int i = 1;i<=n-2;i++){    // agar hamein exact 10 iteration chaiye toh hamne n-2 use kiya kuki do hum explicitly print krwa chuke hai
        int sum = a+b;
        cout<<sum<<" ";
        a=b;
        b=sum;
    }
    
    return 0;
}
*/

/*********************Prime or not*********************/
/*
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    bool isPrime = 1;

    for(int i = 2; i<n ; i++){
        //rem = 0, Not a Prime
        if(n%i==0){
             isPrime = 0;
             break;
        }
    }
     if(isPrime == 0){
        cout<<n<<" "<<"is Not a Prime Number";
     }
     else{
         cout<<n<<" "<< "is a Prime Number";
     }
     return 0;

}

*/

// prog to check the number of factor of n 
/*
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int count=0;
    
    for(int i = 1; i<=n ; i++){
        if(n%i==0){
             count++;
        }
    }
    cout<<count;
}

*/


/********************Find Output good question***************888*/
/*
#include<iostream>
using namespace std;

int main()
{
    for(int i=0;i<5;i++){
        for(int j = i;j<=5;j++){
            cout<<i<<" "<<j<<endl;
        }
    }
}
*/
