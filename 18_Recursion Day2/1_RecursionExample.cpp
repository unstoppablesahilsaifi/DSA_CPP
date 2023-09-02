// Code
#include<iostream>
using namespace std;
void reachHome(int src, int destination){
     

     cout<<"Source  "<<src<<"  Destination  "<<destination<<endl;
     //Base case
     if(src==destination){
        cout<<"Phuch  Gya"<<endl;
        //return statement mandate  hoti h base case m
        return ;
     }

     //Recursive call

     src++;

     reachHome(src,destination);

}

int main(){

   int destination=10;
   int src=1;

   reachHome(src,destination);

    return 0;

}