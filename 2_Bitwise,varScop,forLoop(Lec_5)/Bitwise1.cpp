#include<iostream>
using namespace std;

int main()
{
    
    int a=4;
    int b=6;
    cout<<"a&b= "<<(a&b)<<endl;
    cout<<"a | b= "<<(a | b)<<endl;
    cout<<"~a= "<<(~a)<<endl;
    cout<<"a^b ="<<(a ^ b)<<endl;
    cout<<(17>>1)<<endl;
    cout<<(17>>2)<<endl;
    cout<<(19<<1)<<endl;
    cout<<(19<<2)<<endl;

}

/*
OP- 4
    6
   -5
    2
   Why we get -5 in case of NOT:
   We get -5 coz 4 is 1 0 0 is binary when we make it Not it will be 1111....011 but 1 means last bit defines number became negative to hmne kya padha tha ki
   bhai negative number ko print krne k liye 2' s comliment krte h
   111....011 ka 1's hua 000...100 2's krne k liye +1 krdo which means
   
       111....011
   1's 000....100
       ----------
   2's         +1
       -----------
       000....101 which means 5 sign negative hi rhega
   
   Shift Operator Output:(Small number k case m right shift jitni baar hoga utni baar 2 s divide hoga and left shift utni baar multiply)
   8  17/2=8 coz 1 baar shift hua h 
   4  17/2*2  17/4=4 coz 2 baar shift hua h
   38 19*2= 38
   76  19*2*2=76
      
   Now, question ye h ki sift small number hi kyu?????????
      kyuki suppose kyuki number h jiski bits h 0100000..10 iski left shift kiya to 10000000...100 bn gya mtlb negative bn gya na last bit 1 h isliye
*/