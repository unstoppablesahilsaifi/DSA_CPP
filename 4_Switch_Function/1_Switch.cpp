//Note Checker using Switch
#include<iostream>
using namespace std;
//100  , 50  , 20  , 1
int main()
{
    int amount=1330;
    int n1,n20,n50,n100;
    n1,n20,n50,n100=0;
    switch(amount>=100)
	{
		case 1:
			n100 = amount/100;
        	amount -= n100 * 100;
        break;
	}

    switch(amount >=50)
	{
		case 1:
			n50 = amount/50;
        	amount -= n50 * 50;
	}
    switch(amount >=20)
	{
		case 1:
			n20 = amount/20;
        	amount -= n20 * 20;
        break;
	}
    switch(amount >=10)
	{
		case 1:
			n1 = amount/1;
        	amount -= n1 * 1;
        break;
	}
    return 0;
}