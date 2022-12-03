#include<iostream>
using namespace std;

int main()
{
    /*
    _ _ _ _ *
    _ _ _ * *
    _ _ * * *
    _ * * * *
    * * * * *

    */

    int n;
    cin>>n;
    int i=1;
    while (i<=n){
        //space print
        int space=n-i;
        while(space){
            cout<<" ";
            space--;
        }
        //star print

        int j=1;
        while(j<=i){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}